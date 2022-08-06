// Search : 
#include "OXEvent.h"

// Add : 
#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
#include "blood_dungeon.h"
#endif

// Search : 
	m_pkChrStone = NULL;
// Add : 
#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	m_pkUpdateBloodDungeon = NULL;
#endif

// Search : 
	event_cancel(&m_pkPoisonEvent);
// Add : 
#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	event_cancel(&m_pkUpdateBloodDungeon);
#endif

// Search : 
EVENTFUNC(recovery_event)
{
	char_event_info* info = dynamic_cast<char_event_info*>( event->info );
	if ( info == NULL )
	{
		sys_err( "recovery_event> <Factor> Null pointer" );
		return 0;
	}

	LPCHARACTER	ch = info->ch;

	if (ch == NULL) { // <Factor>
		return 0;
	}	
	
	
// Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	if (CBloodDungeon::instance().IsBloodDungeon(ch->GetRaceNum(), ch->GetMapIndex()) == true)
		return 0;
#endif



// Search : 
void CHARACTER::SetGuild(CGuild* pGuild)

// Before Add: 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
EVENTFUNC(blood_dungeon_data_event)
{
	char_event_info* info = dynamic_cast<char_event_info*>( event->info );
	if ( info == NULL )
	{
		sys_err( "blood_dungeon_data_event> <Factor> Null pointer" );
		return 0;
	}

	LPCHARACTER	ch = info->ch;

	if (NULL == ch || ch->IsNPC())
		return 0;
	
	if (CBloodDungeon::instance().IsBloodDungeon(CBloodDungeon::instance().BLOOD_DUNGEON_BOSS, ch->GetMapIndex()) == true && !ch->GetGuild())
		ch->GoHome();
	else if (CBloodDungeon::instance().IsBloodDungeon(CBloodDungeon::instance().BLOOD_DUNGEON_BOSS, ch->GetMapIndex()) == true && ch->GetLevel() < 100)
		ch->GoHome();
	
	if (ch && ch->GetDesc() && ch->IsPC() == true && ch->GetGuild())
	{
		if (CBloodDungeon::instance().IsBloodDungeon(CBloodDungeon::instance().BLOOD_DUNGEON_BOSS, ch->GetMapIndex()) == true)
			CBloodDungeon::instance().SendClientPacket(ch);
	}
	
	return PASSES_PER_SEC(1);
}

void CHARACTER::StartBloodDungeonDataEvent()
{
	if (m_pkUpdateBloodDungeon)
		return;
	
	char_event_info* info = AllocEventInfo<char_event_info>();
	info->ch = this;
	m_pkUpdateBloodDungeon = event_create(blood_dungeon_data_event, info, PASSES_PER_SEC(1));
}
#endif