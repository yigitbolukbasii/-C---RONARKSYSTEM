## Search : 
import constInfo

## Add : 

import uiblood_dungeon


## Search : 
		self.console = consoleModule.ConsoleWindow()
		self.console.BindGameClass(self)
		self.console.SetConsoleSize(wndMgr.GetScreenWidth(), 200)
		self.console.Hide()
		
## Add : 

		self.blood_dungeon = uiblood_dungeon.BloodDungeonSystemWindow()
		self.blood_dungeon.Hide()
		
## Search : 
		if self.console:
			self.console.BindGameClass(0)
			self.console.Close()
			self.console=None

## Add :

		if self.blood_dungeon:
			self.blood_dungeon.Destroy()
			self.blood_dungeon = None
			
## Search : 

		print "---------------------------------------------------------------------------- CLOSE GAME WINDOW"

		
## Add : 

	def IsBloodDungeonSystemWindow(self):
		if str(background.GetCurrentMapName()) == "metin2_map_t1" and not self.blood_dungeon.IsShow(): 
			self.blood_dungeon.Show()

## Search : 
	def ResetAffect(self, affect):
		self.affectShower.ResetAffect(affect)

## Add : 

	def BINARY_BLOOD_DUNGEON(self, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15):
		self.blood_dungeon.GetBloodDungeon(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15)
		
## Search : 
	def OnUpdate(self):	
		app.UpdateGame()

## Add : 
		self.IsBloodDungeonSystemWindow()


