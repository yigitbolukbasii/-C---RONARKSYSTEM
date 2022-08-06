#include "stdafx.h"
#include "vector.h"
#include "char.h"
#include "utils.h"
#include "log.h"
#include "db.h"
#include "dev_log.h"
#include "locale_service.h"
#include <stdlib.h>
#include "guild.h"
#include "guild_manager.h"
#include <sstream>
#include "config.h"
#include "desc.h"
#include "desc_manager.h"
#include "char_manager.h"
#include "buffer_manager.h"
#include "packet.h"
#include "desc_client.h"
#include "group_text_parse_tree.h"
#include <boost/algorithm/string/predicate.hpp>
#include <cctype>
#include "p2p.h"
#include "entity.h"
#include "sectree_manager.h"
#include "blood_dungeon.h"
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
CBloodDungeon::CBloodDungeon() { blood_table.clear(); }
CBloodDungeon::~CBloodDungeon(){}
DWORD BRankOne = 0, BRankTwo = 0, BRankTheree = 0, BRankFour = 0, BRankedFive = 0;
float BRankOnePoint = 0, BRankTwoPoint = 0, BRankThereePoint = 0, BRankFourPoint = 0, BRankedFivePoint = 0;
short BRankedOneMemberCount = 0, BRankedTwoMemberCount = 0, BRankedThereeMemberCount = 0, BRankedFourMemberCount = 0, BRankedFiveMemberCount = 0;

void CBloodDungeon::RestartDungeon(DWORD GuildID)
{
	BloodRanked(GuildID);
	blood_table.clear();
	BRankOne = 0;
	BRankTwo = 0;
	BRankTheree = 0;
	BRankFour = 0;
	BRankedFive = 0;
	BRankOnePoint = 0;
	BRankTwoPoint = 0;
	BRankThereePoint = 0;
	BRankFourPoint = 0;
	BRankedFivePoint = 0;
}

bool CBloodDungeon::IsBloodDungeon(DWORD dwMobVnum, DWORD dwMapIndex)
{
	if (dwMobVnum == BLOOD_DUNGEON_BOSS && dwMapIndex == BLOOD_DUNGEON_IDX)
		return true;
	else
		return false;
}


void CBloodDungeon::BloodRanked(DWORD GuildID)
{
	boost::unordered_map<DWORD, float>::iterator it = blood_table.find(GuildID);

	if (it->second > BRankOnePoint){
		if (BRankOne != 0 && it->first != BRankOne){
			BRankTwo = BRankOne;
			BRankTwoPoint = BRankOnePoint;
	
			BRankOne = it->first;
			BRankOnePoint = it->second;
			BloodDungeonKing = GuildID;
		}
		else{
			BRankOne = it->first;
			BRankOnePoint = it->second;
			BloodDungeonKing = GuildID;
		}
	}
	else if (it->second > BRankTwoPoint){
		if (BRankTwo != 0 && it->first != BRankTwo){
			BRankTheree = BRankTwo;
			BRankThereePoint =  BRankTwoPoint;
	
			BRankTwo = it->first;
			BRankTwoPoint =  it->second;
		}
		else{
			BRankTwo = it->first;
			BRankTwoPoint =  it->second;
		}
	}
	else if (it->second > BRankThereePoint){
		if (BRankTheree != 0 && it->first != BRankTheree){
			BRankFour = BRankTheree;
			BRankFourPoint = BRankThereePoint;
	
			BRankTheree = it->first;
			BRankThereePoint = it->second;
		}
		else{
			BRankTheree = it->first;
			BRankThereePoint = it->second;
		}
	}
	else if (it->second > BRankFourPoint && it->first != BRankFour){
		if (BRankFour != 0 && it->first != BRankFour)
		{
			BRankedFive = BRankFour;
			BRankedFivePoint = BRankFourPoint;
		
			BRankFour = it->first;
			BRankFourPoint = it->second;
		}
		else
		{
			BRankFour = it->first;
			BRankFourPoint = it->second;
		}
	}
	else if (it->second > BRankedFivePoint){
		BRankedFive = it->first;
		BRankedFivePoint = it->second;
	}
}

void CBloodDungeon::SetBloodGDamage(DWORD GuildID, float Damage)
{
	boost::unordered_map<DWORD, float>::iterator it = blood_table.find(GuildID);
	if (it == blood_table.end())
		blood_table.insert(std::make_pair(GuildID, Damage));
	else
		it->second += Damage;
	
	BloodRanked(GuildID);
}

void CBloodDungeon::SendClientPacket(LPCHARACTER pkChr)
{
	if(!pkChr || !pkChr->GetGuild())
		return;
	
	if (!pkChr->GetDesc())
		return;

	if (pkChr->IsPC() == true)
	{
		RefreshOnlineMember(pkChr);

		TPacketGCBloodDungeon p;

		p.header 			= HEADER_GC_BLOOD_DUNGEON;
		p.OneGuildID		= BRankOne;
		p.OneGuildDamage	= BRankOnePoint;
		p.OneGuildMember	= BRankedOneMemberCount;
		p.TwoGuildID		= BRankTwo;
		p.TwoGuildDamage	= BRankTwoPoint;
		p.TwoGuildMember	= BRankedTwoMemberCount;
		p.ThereeGuildID		= BRankTheree;
		p.ThereeGuildDamage	= BRankThereePoint;
		p.ThereeGuildMember	= BRankedThereeMemberCount;
		p.FourGuildID		= BRankFour;
		p.FourGuildDamage	= BRankFourPoint;
		p.FourGuildMember	= BRankedFourMemberCount;
		p.FiveGuildID		= BRankedFive;
		p.FiveGuildDamage	= BRankedFivePoint;
		p.FiveGuildMember	= BRankedFiveMemberCount;

		if (pkChr->GetDesc() != NULL)
			pkChr->GetDesc()->BufferedPacket(&p, sizeof(TPacketGCBloodDungeon));
	}
}

void CBloodDungeon::AddGuildMember(LPCHARACTER ch)
{
	boost::unordered_map<DWORD, short>::iterator it = online_member.find(ch->GetGuild()->GetID());
	if (it == online_member.end())
		online_member.insert(std::make_pair(ch->GetGuild()->GetID(), 1));
	else
		it->second += 1;
	
	RefreshOnlineMember(ch);
}

void CBloodDungeon::RemoveGuildMember(LPCHARACTER ch)
{
	boost::unordered_map<DWORD, short>::iterator it = online_member.find(ch->GetGuild()->GetID());
	if (it == online_member.end())
		online_member.insert(std::make_pair(ch->GetGuild()->GetID(), 0));
	else
		it->second -= 1;
	
	RefreshOnlineMember(ch);
}

void CBloodDungeon::RefreshOnlineMember(LPCHARACTER ch)
{
	boost::unordered_map<DWORD, short>::iterator it = online_member.find(ch->GetGuild()->GetID());
	if (ch->GetGuild()->GetID() == BRankOne)
		BRankedOneMemberCount = it->second;
	else if (ch->GetGuild()->GetID() == BRankTwo)
		BRankedTwoMemberCount = it->second;
	else if (ch->GetGuild()->GetID() == BRankTheree)
		BRankedThereeMemberCount = it->second;
	else if (ch->GetGuild()->GetID() == BRankFour)
		BRankedFourMemberCount = it->second;
	else if (ch->GetGuild()->GetID() == BRankedFive)
		BRankedFiveMemberCount = it->second;
}
#endif