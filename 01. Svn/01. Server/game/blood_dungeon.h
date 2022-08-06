#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>

class CBloodDungeon : public singleton<CBloodDungeon>
{
	public:
		CBloodDungeon();
		enum EBloodDungeon
		{
			BLOOD_DUNGEON_BOSS	= 22003, // Mob Vnum
			BLOOD_DUNGEON_IDX	= 103, // MapIndex
		};

		virtual		~CBloodDungeon();
		bool		IsBloodDungeon(DWORD dwMobVnum, DWORD dwMapIndex);
		float		GetBloodGDamage(DWORD Point);
		void		SendClientPacket(LPCHARACTER pkChr);
		void		RestartDungeon(DWORD GuildID);
		void		BloodRanked(DWORD GuildID);
		DWORD		BloodDungeonKing;
		DWORD		GetBloodGuildID(DWORD Point);
		void		SetBloodGDamage(DWORD GuildID, float Damage);
		boost::unordered_map<DWORD, float>	blood_table;
		boost::unordered_map<DWORD, short>	online_member;
		void		AddGuildMember(LPCHARACTER ch);
		void		RemoveGuildMember(LPCHARACTER ch);
		void		RefreshOnlineMember(LPCHARACTER ch);
};