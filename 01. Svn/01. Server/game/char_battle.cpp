// Search : 
#include "DragonLair.h"

// Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
#include "blood_dungeon.h"
#endif


// Search : 

	if(pkKiller && IsPC()) 
	{
		pkKiller->SetQuestNPCID(GetVID());
		quest::CQuestManager::instance().Dead(GetPlayerID());
	}
	
	//CHECK_FORKEDROAD_WAR
	if (IsPC())
	{
		if (CThreeWayWar::instance().IsThreeWayWarMapIndex(GetMapIndex()))
			isForked = true;
	}
	//END_CHECK_FORKEDROAD_WAR
	
// Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	if (!IsPC() && pkKiller && pkKiller->IsPC())
	{
		if (pkKiller->GetGuild() && CBloodDungeon::instance().IsBloodDungeon(GetRaceNum(), pkKiller->GetMapIndex()) == true)
		{
			CGuild* GetGuildBlood = CGuildManager::instance().FindGuild(CBloodDungeon::instance().BloodDungeonKing);
			char szNotice[512+1];
			snprintf(szNotice, sizeof(szNotice), "<Bahamut Bˆlgesi> Bahamut Kral˝ %s Loncas˝ Taraf˝ndan Katletti!", GetGuildBlood->GetName());
			BroadcastNotice(szNotice);
			CBloodDungeon::instance().RestartDungeon(pkKiller->GetGuild()->GetID());
		}
	}
#endif


// Search : 

		if (type == DAMAGE_TYPE_NORMAL)
		{
			// ±Ÿ¡¢ ∆Ú≈∏¿œ ∞ÊøÏ ∏∑¿ª ºˆ ¿÷¿Ω
			if (GetPoint(POINT_BLOCK) && number(1, 100) <= GetPoint(POINT_BLOCK))
			{
				if (test_server)
				{
					pAttacker->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s ∫Ì∑∞! (%d%%)"), GetName(), GetPoint(POINT_BLOCK));
					ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s ∫Ì∑∞! (%d%%)"), GetName(), GetPoint(POINT_BLOCK));
				}

				SendDamagePacket(pAttacker, 0, DAMAGE_BLOCK);
				return false;
			}
		}
		
// Before Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
		if(!IsPC())
		{
			if(pAttacker->IsPC())
			{
				if (CBloodDungeon::instance().IsBloodDungeon(GetRaceNum(), pAttacker->GetMapIndex()) == false)
				{
					if (GetPoint(POINT_DODGE) || GetPoint(POINT_BLOCK))
						return false;
				}
			}
		}
#endif		

// Search : 

		damageFlag |= DAMAGE_CRITICAL;

	if (IsPenetrate == true)
		damageFlag |= DAMAGE_PENETRATE;


	//√÷¡æ µ•πÃ¡ˆ ∫∏¡§
	float damMul = this->GetDamMul();
	float tempDam = dam;
	
// Add : 
#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	if(!IsPC())
	{
		if(pAttacker->IsPC() && pAttacker->GetGuild())
		{
			if (CBloodDungeon::instance().IsBloodDungeon(GetRaceNum(), GetMapIndex()) == true)
			{
				float BPercent = (double)(dam) / (double)(GetMobTable().dwMaxHP) * 100;
				CBloodDungeon::instance().SetBloodGDamage(pAttacker->GetGuild()->GetID(), BPercent);
				CBloodDungeon::instance().SendClientPacket(pAttacker);
			}
		}
	}
#endif