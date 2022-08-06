// Search : 

void CPythonPlayer::SendClickItemPacket(DWORD dwIID, bool bEgePckt, DWORD dwEgType)
{
	if (IsObserverMode())
		return;

// Add : 

#ifdef ENABLE_BLOOD_DUNGEON
	std::string strGuildName;
	if (!CPythonGuild::Instance().GetGuildName(GetGuildID(), &strGuildName))
		strGuildName = "Noname";

	strGuildName = strGuildName;

#endif

// Search : 
			if (!CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData))
			{
				Tracenf("CPythonPlayer::SendClickItemPacket(dwIID=%d) : Non-exist item.", dwIID);
				return;
			}
			

// Add : 

#ifdef ENABLE_BLOOD_DUNGEON
			if (0 == strcmp(c_szOwnerName, strGuildName.c_str())){
				CPythonNetworkStream& rkNetStream = CPythonNetworkStream::Instance();
				rkNetStream.SendItemPickUpPacket(dwIID);
				return;
			}
#endif