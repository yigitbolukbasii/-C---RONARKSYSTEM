// Search : 
#include "desc_client.h"


// Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
#include "blood_dungeon.h"
#include "guild.h"
#endif


// Search : 
	bool CQuestManager::PickupItem(unsigned int pc, LPITEM item)
	{
		...
	}
	
// Replace : 
	bool CQuestManager::PickupItem(unsigned int pc, LPITEM item)
	{
#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
		LPCHARACTER ch = GetCurrentCharacterPtr();
#endif
		
		if (test_server)
			sys_log( 0, "questmanager::PickupItem Start : itemVnum : %d PC : %d", item->GetOriginalVnum(), pc);
		
#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
		if (ch->GetGuild())
		{
			if (pc == ch->GetGuild()->GetID()){
				SetCurrentItem(item);
				return false;
			}
		}
#endif
		
		PC* pPC;
		if ((pPC = GetPC(pc)))
		{
			if (!CheckQuestLoaded(pPC))
			{
				LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(pc);
				if (ch)
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("퀘스트를 로드하는 중입니다. 잠시만 기다려 주십시오."));
				}
				return false;
			}
			// call script
			SetCurrentItem(item);

			return m_mapNPC[item->GetVnum()].OnPickupItem(*pPC);
		}
		else
		{
			sys_err("QUEST PICK_ITEM_EVENT no such pc id : %d", pc);
			return false;
		}
	}