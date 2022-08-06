// Search : 
#include "dungeon.h"

// Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
#include "blood_dungeon.h"
#endif


// Search : 
				if (item->GetType() == ITEM_QUEST)
					quest::CQuestManager::instance().PickupItem (GetPlayerID(), item);


// Replace : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
				if (item->GetType() == ITEM_QUEST)
					if (CBloodDungeon::instance().IsBloodDungeon(CBloodDungeon::instance().BLOOD_DUNGEON_BOSS, GetMapIndex()) == true)
						quest::CQuestManager::instance().PickupItem (GetGuild()->GetID(), item);
					else
						quest::CQuestManager::instance().PickupItem (GetPlayerID(), item);
#else
				if (item->GetType() == ITEM_QUEST)
					quest::CQuestManager::instance().PickupItem (GetPlayerID(), item);
#endif


// Search : 

				if (item->GetType() == ITEM_QUEST)
					quest::CQuestManager::instance().PickupItem (GetPlayerID(), item);
				
				
// Replace : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
			if (item->GetType() == ITEM_QUEST)
				if (CBloodDungeon::instance().IsBloodDungeon(CBloodDungeon::instance().BLOOD_DUNGEON_BOSS, GetMapIndex()) == true)
					quest::CQuestManager::instance().PickupItem (owner->GetGuild()->GetID(), item);
				else
					quest::CQuestManager::instance().PickupItem (owner->GetPlayerID(), item);
#else
			if (item->GetType() == ITEM_QUEST)
				quest::CQuestManager::instance().PickupItem (owner->GetPlayerID(), item);
#endif