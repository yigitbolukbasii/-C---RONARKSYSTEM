// Search : 
#include "char.h"

// Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
#include "blood_dungeon.h"
#include "guild.h"
#include "guild_manager.h"
#endif


// Search : 
bool CItem::IsOwnership(LPCHARACTER ch)
{
	...
}

// Replace : 

bool CItem::IsOwnership(LPCHARACTER ch)
{
	if (!m_pkOwnershipEvent)
		return true;

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	if (CBloodDungeon::instance().IsBloodDungeon(CBloodDungeon::instance().BLOOD_DUNGEON_BOSS, ch->GetMapIndex()) == true)
	{
		if(!ch->GetGuild())
			return false;
		
		return m_dwOwnershipPID == ch->GetGuild()->GetID() ? true : false;
	}
	else
	{
		return m_dwOwnershipPID == ch->GetPlayerID() ? true : false;
	}
#else
	return m_dwOwnershipPID == ch->GetPlayerID() ? true : false;
#endif
}


// Search : 

void CItem::SetOwnership(LPCHARACTER ch, int iSec)
{
	...
}


// Replace :

void CItem::SetOwnership(LPCHARACTER ch, int iSec)
{
	if (!ch)
	{
		if (m_pkOwnershipEvent)
		{
			event_cancel(&m_pkOwnershipEvent);
			m_dwOwnershipPID = 0;

			TPacketGCItemOwnership p;

			p.bHeader	= HEADER_GC_ITEM_OWNERSHIP;
			p.dwVID	= m_dwVID;
			p.szName[0]	= '\0';

			PacketAround(&p, sizeof(p));
		}
		return;
	}

	if (m_pkOwnershipEvent)
		return;

	if (true == LC_IsEurope())
	{
		if (iSec <= 10)
			iSec = 30;
	}
#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	if (CBloodDungeon::instance().IsBloodDungeon(CBloodDungeon::instance().BLOOD_DUNGEON_BOSS, ch->GetMapIndex()) == true)
	{
		CGuild* GetGuildBlood = CGuildManager::instance().FindGuild(CBloodDungeon::instance().BloodDungeonKing);
		if (GetGuildBlood)
		{
			m_dwOwnershipPID = GetGuildBlood->GetID();
			item_event_info* info = AllocEventInfo<item_event_info>();
			strlcpy(info->szOwnerName, GetGuildBlood->GetName(), sizeof(info->szOwnerName));
			info->item = this;
			SetOwnershipEvent(event_create(ownership_event, info, PASSES_PER_SEC(iSec)));
			TPacketGCItemOwnership p;
			p.bHeader = HEADER_GC_ITEM_OWNERSHIP;
			p.dwVID = m_dwVID;
			strlcpy(p.szName, GetGuildBlood->GetName(), sizeof(p.szName));
			PacketAround(&p, sizeof(p));
		}
		else
		{
			m_dwOwnershipPID = ch->GetPlayerID();
			item_event_info* info = AllocEventInfo<item_event_info>();
			strlcpy(info->szOwnerName, ch->GetName(), sizeof(info->szOwnerName));
			info->item = this;
			SetOwnershipEvent(event_create(ownership_event, info, PASSES_PER_SEC(iSec)));
			TPacketGCItemOwnership p;
			p.bHeader = HEADER_GC_ITEM_OWNERSHIP;
			p.dwVID = m_dwVID;
			strlcpy(p.szName, ch->GetName(), sizeof(p.szName));
			PacketAround(&p, sizeof(p));
		}
	}
	else
	{
		m_dwOwnershipPID = ch->GetPlayerID();
		item_event_info* info = AllocEventInfo<item_event_info>();
		strlcpy(info->szOwnerName, ch->GetName(), sizeof(info->szOwnerName));
		info->item = this;
		SetOwnershipEvent(event_create(ownership_event, info, PASSES_PER_SEC(iSec)));
		TPacketGCItemOwnership p;
		p.bHeader = HEADER_GC_ITEM_OWNERSHIP;
		p.dwVID = m_dwVID;
		strlcpy(p.szName, ch->GetName(), sizeof(p.szName));
		PacketAround(&p, sizeof(p));
	}

#else
	m_dwOwnershipPID = ch->GetPlayerID();
	item_event_info* info = AllocEventInfo<item_event_info>();
	strlcpy(info->szOwnerName, ch->GetName(), sizeof(info->szOwnerName));
	info->item = this;
	SetOwnershipEvent(event_create(ownership_event, info, PASSES_PER_SEC(iSec)));
	TPacketGCItemOwnership p;
	p.bHeader = HEADER_GC_ITEM_OWNERSHIP;
	p.dwVID = m_dwVID;
	strlcpy(p.szName, ch->GetName(), sizeof(p.szName));
	PacketAround(&p, sizeof(p));
#endif
}