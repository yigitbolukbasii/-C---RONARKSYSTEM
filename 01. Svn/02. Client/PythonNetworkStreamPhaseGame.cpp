// Search : 
			case HEADER_GC_HANDSHAKE_OK:
				RecvHandshakeOKPacket();
				return;
				break;
			

// Add : 

#ifdef ENABLE_BLOOD_DUNGEON
			case HEADER_GC_BLOOD_DUNGEON:
				ret = RecvBloodDungeon();
				break;
#endif

// Search : 
bool CPythonNetworkStream::RecvDungeon()

// Before Add : 

#ifdef ENABLE_BLOOD_DUNGEON
bool CPythonNetworkStream::RecvBloodDungeon()
{
	TPacketGCBloodDungeon p;
	if (!Recv(sizeof(TPacketGCBloodDungeon), &p))
	{
		Tracenf("Recv Blood Dungeon Packet Error");
		return false;
	}

	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "BINARY_BLOOD_DUNGEON", Py_BuildValue("(ifiifiifiifiifi)"
	, p.OneGuildID, p.OneGuildDamage,p.OneGuildMember, p.TwoGuildID, p.TwoGuildDamage,p.TwoGuildMember, p.ThereeGuildID
	, p.ThereeGuildDamage,p.ThereeGuildMember, p.FourGuildID, p.FourGuildDamage,p.FourGuildMember, p.FiveGuildID, p.FiveGuildDamage,p.FiveGuildMember));

	return true;
}
#endif
