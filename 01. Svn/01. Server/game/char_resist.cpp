// Search : 
#include "char.h"

// Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
#include "blood_dungeon.h"
#endif


// Search : 
EVENTFUNC(bleed_event)
{
	TBleedEventInfo * info = dynamic_cast<TBleedEventInfo *>(event->info);

	if (info == NULL)
	{
		sys_err("bleed_event> <Factor> Null pointer");
		return 0;
	}

	LPCHARACTER ch = info->ch;

	if (ch == NULL) { // <Factor>
		return 0;
	}

// Add : 
#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	if (CBloodDungeon::instance().IsBloodDungeon(ch->GetRaceNum(), ch->GetMapIndex()) == true)
		return 0;
#endif

// Search : 
EVENTFUNC(poison_event)
{
	TPoisonEventInfo * info = dynamic_cast<TPoisonEventInfo *>( event->info );
	
	if ( info == NULL )
	{
		sys_err( "poison_event> <Factor> Null pointer" );
		return 0;
	}

	LPCHARACTER ch = info->ch;

	if (ch == NULL) { // <Factor>
		return 0;
	}
	

// Add : 
#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	if (CBloodDungeon::instance().IsBloodDungeon(ch->GetRaceNum(), ch->GetMapIndex()) == true)
		return 0;
#endif

// Search : 
EVENTFUNC(fire_event)
{
	TFireEventInfo * info = dynamic_cast<TFireEventInfo *>( event->info );

	if ( info == NULL )
	{
		sys_err( "fire_event> <Factor> Null pointer" );
		return 0;
	}

	LPCHARACTER ch = info->ch;
	if (ch == NULL) { // <Factor>
		return 0;
	}
	

// Add : 
#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	if (CBloodDungeon::instance().IsBloodDungeon(ch->GetRaceNum(), ch->GetMapIndex()) == true)
		return 0;
#endif