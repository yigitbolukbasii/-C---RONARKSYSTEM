// Search : 
#include "char.h"

// Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
#include "blood_dungeon.h"
#endif


// Search : 
	ch->ResetPlayTime();

// Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	ch->StartBloodDungeonDataEvent();
#endif