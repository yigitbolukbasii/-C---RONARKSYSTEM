// Search : 
			Set(HEADER_GC_DUNGEON, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCDungeon), DYNAMIC_SIZE_PACKET));

// Add : 

#ifdef ENABLE_BLOOD_DUNGEON
			Set(HEADER_GC_BLOOD_DUNGEON, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCBloodDungeon), STATIC_SIZE_PACKET));
#endif