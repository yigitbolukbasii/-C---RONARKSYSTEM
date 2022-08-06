// Search : 
#include "MarkManager.h"

// Add :

#ifdef ENABLE_BLOOD_DUNGEON
#include "PythonPlayer.h"
#endif


// Search : 
		pTextTail->pOwnerTextInstance->Update();
		
// Before Add : 

#ifdef ENABLE_BLOOD_DUNGEON
		CPythonPlayer& rkPlayer = CPythonPlayer::Instance();

		std::string strGuildName;
		if (!CPythonGuild::Instance().GetGuildName(rkPlayer.GetGuildID(), &strGuildName))
			strGuildName = "Noname";

		strGuildName = strGuildName;

		if (pInstanceBase)
		{
			if (0 == strcmp(c_szName, strGuildName.c_str()))
				pTextTail->pOwnerTextInstance->SetColor(1.0f, 1.0f, 0.0f);
		}

#endif