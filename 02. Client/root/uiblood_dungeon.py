# app = __import__(pythonApi.GetModuleName("app"))
# chr = __import__(pythonApi.GetModuleName("chr"))
# chrmgr = __import__(pythonApi.GetModuleName("chrmgr"))
# player = __import__(pythonApi.GetModuleName("player"))
# net = __import__(pythonApi.GetModuleName("net"))
# pack = __import__(pythonApi.GetModuleName("pack"))
# background = __import__(pythonApi.GetModuleName("background"))
# chat = __import__(pythonApi.GetModuleName("chat"))
# textTail = __import__(pythonApi.GetModuleName("textTail"))
# event = __import__(pythonApi.GetModuleName("event"))
# effect = __import__(pythonApi.GetModuleName("effect"))
# systemSetting = __import__(pythonApi.GetModuleName("systemSetting"))
# quest = __import__(pythonApi.GetModuleName("quest"))
# guild = __import__(pythonApi.GetModuleName("guild"))
# skill = __import__(pythonApi.GetModuleName("skill"))
# messenger = __import__(pythonApi.GetModuleName("messenger"))
# ime = __import__(pythonApi.GetModuleName("ime"))
# item = __import__(pythonApi.GetModuleName("item"))
import wndMgr, uiCommon, ui, time, playerSettingModule, localeInfo, snd, mouseModule, constInfo, uiScriptLocale, interfacemodule, dbg
import app, chr, chrmgr, player, net, pack, background, chat, textTail, event, effect, systemSetting, quest, guild, skill, messenger, ime, item

class BloodDungeonSystemWindow(ui.ScriptWindow):

	def __init__(self):
		ui.ScriptWindow.__init__(self)
		self.Initialize()
		self.LoadWindow()

	def Initialize(self):
		self.UpdateTimer = 0
		self.RKOneGuildID = 0
		self.RKTwoGuildID = 0
		self.RKThreeGuildID = 0
		self.RKFourGuildID = 0
		self.RKFiveGuildID = 0
		
		self.RKOneGuildPoint = 0
		self.RKTwoGuildPoint = 0
		self.RKThereeGuildPoint = 0
		self.RKFourGuildPoint = 0
		self.RKFiveGuildPoint = 0

		self.RKOneGuildMember = 0
		self.RKTwoGuildMember = 0
		self.RKThreeGuildMember = 0
		self.RKFourGuildMember = 0
		self.RKFiveGuildMember = 0

	def __del__(self):
		ui.ScriptWindow.__del__(self)

	def LoadWindow(self):
		try:
			pyScrLoader = ui.PythonScriptLoader()
			pyScrLoader.LoadScriptFile(self, "UIScript/blood_dungeon.py")
		except:
			import exception
			exception.Abort("BloodDungeonSystemWindow.LoadWindow.LoadObject")
		try:
		
			self.BBloodThinboard = self.GetChild("Thinboard")
			self.BBloodTitle = self.GetChild("BloodTitle")
			self.BloodInfo = self.GetChild("BloodInfo")

			self.ROneGuild = self.GetChild("OneGuild")
			self.RTwoGuild = self.GetChild("TwoGuild")
			self.RThreeGuild = self.GetChild("ThreeGuild")
			self.RFourGuild = self.GetChild("FourGuild")
			self.RFiveGuild = self.GetChild("FiveGuild")

			self.ROneGuildGauge = self.GetChild("OneGuildGauge")
			self.RTwoGuildGauge = self.GetChild("TwoGuildGauge")
			self.RThreeGuildGauge = self.GetChild("ThreeGuildGauge")
			self.RFourGuildGauge = self.GetChild("FourGuildGauge")
			self.RFiveGuildGauge = self.GetChild("FiveGuildGauge")
			
			self.ROneGuildGaugePoint = self.GetChild("OneGuildGaugePoint")
			self.RTwoGuildGaugePoint = self.GetChild("TwoGuildGaugePoint")
			self.RThreeGuildGaugePoint = self.GetChild("ThreeGuildGaugePoint")
			self.RFourGuildGaugePoint = self.GetChild("FourGuildGaugePoint")
			self.RFiveGuildGaugePoint = self.GetChild("FiveGuildGaugePoint")

			self.ROneGuildMark = self.GetChild("OneGuildMark")
			self.RTwoGuildMark = self.GetChild("TwoGuildMark")
			self.RThreeGuildMark = self.GetChild("ThreeGuildMark")
			self.RFourGuildMark = self.GetChild("FourGuildMark")
			self.RFiveGuildMark = self.GetChild("FiveGuildMark")

		except:
			import exception
			exception.Abort("BloodDungeonSystemWindow.LoadWindow.BindObject")

	def MatFloat(self, arg):
		newarg = str(arg)
		return newarg[:4]

	def GetBloodDungeon(self, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15):
		self.RKOneGuildID = int(arg1)
		self.RKOneGuildPoint = float(self.MatFloat(arg2))
		self.RKOneGuildMember = int(arg3)

		self.RKTwoGuildID = int(arg4)
		self.RKTwoGuildPoint = float(self.MatFloat(arg5))
		self.RKTwoGuildMember = int(arg6)

		self.RKThreeGuildID = int(arg7)
		self.RKThereeGuildPoint = float(self.MatFloat(arg8))
		self.RKThreeGuildMember = int(arg9)

		self.RKFourGuildID = int(arg10)
		self.RKFourGuildPoint = float(self.MatFloat(arg11))
		self.RKFourGuildMember = int(arg12)

		self.RKFiveGuildID = int(arg13)
		self.RKFiveGuildPoint = float(self.MatFloat(arg14))
		self.RKFiveGuildMember = int(arg15)


			
	def SetBloodGauge(self):
		if self.RKOneGuildID == 0:
			self.ROneGuild.Hide()
			self.ROneGuildMark.Hide()
			self.ROneGuildGauge.Hide()
			self.ROneGuildGaugePoint.Hide()
		else:
			self.ROneGuildGauge.MakeGauge(75, "red")
			self.ROneGuildGauge.SetPercentage(self.RKOneGuildPoint, 100)
			self.ROneGuildGauge.Show()
			self.ROneGuildGaugePoint.Show()
			self.ROneGuild.Show()
			self.ROneGuildMark.Show()
			self.ROneGuildMark.SetIndex(self.RKOneGuildID)
			self.ROneGuild.SetText(guild.GetGuildName(int(self.RKOneGuildID)) + " (" + str(self.RKOneGuildMember) + ")")
			self.ROneGuildGaugePoint.SetText("%"+str(self.RKOneGuildPoint))

		if self.RKTwoGuildID == 0:
			self.RTwoGuild.Hide()
			self.RTwoGuildMark.Hide()
			self.RTwoGuildGauge.Hide()
			self.RTwoGuildGaugePoint.Hide()
		else:
			self.RTwoGuildGauge.MakeGauge(75, "red")
			self.RTwoGuildGauge.SetPercentage(self.RKTwoGuildPoint, 100)
			self.RTwoGuildGauge.Show()
			self.RTwoGuildGaugePoint.Show()
			self.RTwoGuild.Show()
			self.RTwoGuildMark.Show()
			self.RTwoGuildMark.SetIndex(self.RKTwoGuildID)
			self.RTwoGuild.SetText(guild.GetGuildName(int(self.RKTwoGuildID)) + " (" + str(self.RKTwoGuildMember) + ")")
			self.RTwoGuildGaugePoint.SetText("%"+str(self.RKTwoGuildPoint))
			
		if self.RKThreeGuildID == 0:
			self.RThreeGuild.Hide()
			self.RThreeGuildMark.Hide()
			self.RThreeGuildGauge.Hide()
			self.RThreeGuildGaugePoint.Hide()
		else:
			self.RThreeGuildGauge.MakeGauge(75, "red")
			self.RThreeGuildGauge.SetPercentage(self.RKThereeGuildPoint, 100)
			self.RThreeGuildGauge.Show()
			self.RThreeGuildGaugePoint.Show()
			self.RThreeGuild.Show()
			self.RThreeGuildMark.Show()
			self.RThreeGuildMark.SetIndex(self.RKThreeGuildID)
			self.RThreeGuild.SetText(guild.GetGuildName(int(self.RKThreeGuildID)) + " (" + str(self.RKThreeGuildMember) + ")")
			self.RThreeGuildGaugePoint.SetText("%"+str(self.RKThereeGuildPoint))
			
		if self.RKFourGuildID == 0:
			self.RFourGuild.Hide()
			self.RFourGuildMark.Hide()
			self.RFourGuildGauge.Hide()
			self.RFourGuildGaugePoint.Hide()
		else:
			self.RFourGuildGauge.MakeGauge(75, "red")
			self.RFourGuildGauge.SetPercentage(self.RKFourGuildPoint, 100)
			self.RFourGuildGauge.Show()
			self.RFourGuildGaugePoint.Show()
			self.RFourGuild.Show()
			self.RFourGuildMark.Show()
			self.RFourGuildMark.SetIndex(self.RKFourGuildID)
			self.RFourGuild.SetText(guild.GetGuildName(int(self.RKFourGuildID)) + " (" + str(self.RKFourGuildMember) + ")")
			self.RFourGuildGaugePoint.SetText("%"+str(self.RKFourGuildPoint))

			
		if self.RKFiveGuildID == 0:
			self.RFiveGuild.Hide()
			self.RFiveGuildMark.Hide()
			self.RFiveGuildGauge.Hide()
			self.RFiveGuildGaugePoint.Hide()
		else:
			self.RFiveGuildGauge.MakeGauge(75, "red")
			self.RFiveGuildGauge.SetPercentage(self.RKFiveGuildPoint, 100)
			self.RFiveGuildGauge.Show()
			self.RFiveGuildGaugePoint.Show()
			self.RFiveGuild.Show()
			self.RFiveGuildMark.Show()
			self.RFiveGuildMark.SetIndex(self.RKFiveGuildID)
			self.RFiveGuild.SetText(guild.GetGuildName(int(self.RKFiveGuildID)) + " (" + str(self.RKFiveGuildMember) + ")")
			self.RFiveGuildGaugePoint.SetText("%"+str(self.RKFiveGuildPoint))
			
			
	def UpdateFuc(self):
		if self.RKOneGuildID == 0:
			self.BBloodThinboard.SetSize(264, 80)
			self.SetBloodGauge()
			self.BloodInfo.Show()
			return
		else:
			self.BBloodThinboard.SetSize(264, 95)
			self.BloodInfo.Hide()
			self.SetBloodGauge()
			
		if self.RKTwoGuildID == 0:
			self.BBloodThinboard.SetSize(264, 95)
			self.SetBloodGauge()
			self.BloodInfo.Hide()
			return
		else:
			self.BBloodThinboard.SetSize(264, 110)
			self.SetBloodGauge()
			self.BloodInfo.Hide()
			
		if self.RKThreeGuildID == 0:
			self.BBloodThinboard.SetSize(264, 110)
			self.SetBloodGauge()
			self.BloodInfo.Hide()
		else:
			self.BBloodThinboard.SetSize(264, 125)
			self.SetBloodGauge()
			self.BloodInfo.Hide()

		if self.RKFourGuildID == 0:
			self.BBloodThinboard.SetSize(264, 125)
			self.SetBloodGauge()
			self.BloodInfo.Hide()
			return
		else:
			self.BBloodThinboard.SetSize(264, 140)
			self.SetBloodGauge()
			self.BloodInfo.Hide()

		if self.RKFiveGuildID == 0:
			self.BBloodThinboard.SetSize(264, 140)
			self.SetBloodGauge()
			self.BloodInfo.Hide()
			return
		else:
			self.BBloodThinboard.SetSize(264, 165)
			self.SetBloodGauge()
			self.BloodInfo.Hide()

	def OnUpdate(self):
		self.UpdateFuc()
