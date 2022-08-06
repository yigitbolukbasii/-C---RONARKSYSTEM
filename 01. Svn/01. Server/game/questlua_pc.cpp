// Search : 
#include "item.h"

// Add : 
#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
#include "blood_dungeon.h"
#endif

// Search
	int pc_is_observer(lua_State * L)

// Before Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	int pc_blood_dungeon_member_add(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		CBloodDungeon::instance().AddGuildMember(ch);

		return 0;
	}
	
	int pc_blood_dungeon_member_remove(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		CBloodDungeon::instance().RemoveGuildMember(ch);

		return 0;
	}
#endif

// Search : 
	void RegisterPCFunctionTable()
	{
		luaL_reg pc_functions[] = 
		{

// Add : 
#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
			{ "blood_dungeon_member_add",		pc_blood_dungeon_member_add			},
			{ "blood_dungeon_member_remove",	pc_blood_dungeon_member_remove	},
#endif