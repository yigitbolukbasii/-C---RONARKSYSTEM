quest blood_dungeon begin
	state start begin
		when logout with pc.get_map_index() == 340 begin
			pc.blood_dungeon_member_remove()
		end
		
		when login with pc.get_map_index() == 340 begin
			pc.blood_dungeon_member_add()
		end
	
		when 20087.chat."Esrarengiz - B�lgesi" with game.get_event_flag("blood_dungeon_login") == 0 begin
			say("")
			say_title("Merhaba "..pc.get_name().. " [ENTER]")
			say("seni bahamut b�lgesine g�nderebilirim fakat bunun i�in birka� �ey gerekiyor e�er bir loncada bulunuyorsan ve 100 seviye �st�nde isen seni oraya g�nderebilirim.")
			say_reward("[ENTER]bu �zelliklere sahip olduguna emin misin ?[ENTER]")
			local blood_teleport_select = select("Evet beni oraya g�nder!","Hay�r gitmek istemiyorum.")
			if blood_teleport_select == 1 then
				if not pc.get_guild() then
					say("")
					say("Bir dakika "..pc.get_name().. " bu b�lgeye loncan olmadan giremezsin.[ENTER]kendine bir lonca olu�turup tekrar girmeyi dene.")
					return
				end
				if pc.get_level() < 100 then
					say("")
					say("Bir dakika "..pc.get_name().. " bu b�lgeye 100 seviyenin alt�nda giremezsin.[ENTER]l�tfen 100 seviye olup tekrar gel.")
					return
				end
				
				if pc.is_gm() then pc.warp(14143500,12500) return end 
				if pc.get_empire() == 1 then
						pc.warp(14143500,12500) -- 1. Kordinat K�rm�z�
				elseif pc.get_empire() == 2 then
						pc.warp(14143500,12500) -- 2. Kordinat Sar�
				elseif pc.get_empire() == 3 then
						pc.warp(14143500,12500) -- 3. Kordinat Mavi
				end
			end
		end
	end
end