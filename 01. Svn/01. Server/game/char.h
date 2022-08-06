// Search : 
		LPEVENT				m_pkWarpEvent;

// Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
		LPEVENT				m_pkUpdateBloodDungeon;
#endif


// Search : 
};

ESex GET_SEX(LPCHARACTER ch);

// Before Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	public:
		void StartBloodDungeonDataEvent();
#endif