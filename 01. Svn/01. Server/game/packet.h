// Search : 
	HEADER_GC_AUTH_SUCCESS

// Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
	HEADER_GC_BLOOD_DUNGEON 							= 137,
#endif


// Search : 
typedef struct packet_messenger_guild_list

// Before Add : 

#ifdef ENABLE_BLOOD_DUNGEON_SYSTEM
typedef struct packet_blood_dungeon
{
	BYTE	header;
	DWORD	OneGuildID;
	float 	OneGuildDamage;
	short 	OneGuildMember;
	DWORD	TwoGuildID;
	float 	TwoGuildDamage;
	short 	TwoGuildMember;
	DWORD	ThereeGuildID;
	float 	ThereeGuildDamage;
	short 	ThereeGuildMember;
	DWORD	FourGuildID;
	float 	FourGuildDamage;
	short 	FourGuildMember;
	DWORD	FiveGuildID;
	float 	FiveGuildDamage;
	short 	FiveGuildMember;
} TPacketGCBloodDungeon;
#endif