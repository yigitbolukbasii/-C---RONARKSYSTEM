quest blood_dungeon begin
	state start begin
		when logout with pc.get_map_index() == 340 begin
			pc.blood_dungeon_member_remove()
		end
		
		when login with pc.get_map_index() == 340 begin
			pc.blood_dungeon_member_add()
		end
	
		when 20087.chat."Esrarengiz - Bölgesi" with game.get_event_flag("blood_dungeon_login") == 0 begin
			say("")
			say_title("Merhaba "..pc.get_name().. " [ENTER]")
			say("seni bahamut bölgesine gönderebilirim fakat bunun için birkaç þey gerekiyor eðer bir loncada bulunuyorsan ve 100 seviye üstünde isen seni oraya gönderebilirim.")
			say_reward("[ENTER]bu özelliklere sahip olduguna emin misin ?[ENTER]")
			local blood_teleport_select = select("Evet beni oraya gönder!","Hayýr gitmek istemiyorum.")
			if blood_teleport_select == 1 then
				if not pc.get_guild() then
					say("")
					say("Bir dakika "..pc.get_name().. " bu bölgeye loncan olmadan giremezsin.[ENTER]kendine bir lonca oluþturup tekrar girmeyi dene.")
					return
				end
				if pc.get_level() < 100 then
					say("")
					say("Bir dakika "..pc.get_name().. " bu bölgeye 100 seviyenin altýnda giremezsin.[ENTER]lütfen 100 seviye olup tekrar gel.")
					return
				end
				
				if pc.is_gm() then pc.warp(14143500,12500) return end 
				if pc.get_empire() == 1 then
						pc.warp(14143500,12500) -- 1. Kordinat Kýrmýzý
				elseif pc.get_empire() == 2 then
						pc.warp(14143500,12500) -- 2. Kordinat Sarý
				elseif pc.get_empire() == 3 then
						pc.warp(14143500,12500) -- 3. Kordinat Mavi
				end
			end
		end
	end
end