import uiScriptLocale
BOARDH = 264
BOARDW = 165

window = {
	"name" : "BloodDungeonSystemWindow",
	"style" : ("movable", "float",),
	"x" : SCREEN_WIDTH - 410,
	"y" : 25,
	"width" : BOARDH,
	"height" : BOARDW,
	"children" :
	(
		{
			"name" : "Thinboard",
			"type" : "thinboard",
			"style" : ("attach",),
			"x" : 0,
			"y" : 0,
			"width" : BOARDH,
			"height" : BOARDW,
			"children" :
			(
				## Title Desing
				{ "name" : "BloodTitle", "type" : "text", "x" : 97+10-5-4, "y" : 15, "color" : 0xfff8d090, "text" : "Bahamut Bölgesi"},
				{ "name" : "BloodTitleImage", "type" : "image", "x" : 27, "y" : 17, "image" : "d:/ymir work/BloodDungeon/horizontal_bar/center.tga" },
				{ "name" : "BloodInfo", "type" : "text", "x" : 60+25-4, "y" : 55, "text" : "Henüz Kimse Vurmadý."},

				## OneGuild Text and Symbol and Gauge Start
				{ "name" : "OneGuild", "type" : "text", "x" : 35, "y" : 55 },
				{ "name" : "OneGuildMark", "type" : "mark", "x" : 16, "y" : 57 },
				{ "name" : "OneGuildGauge", "type" : "gauge",  "x" : 145, "y" : 59, "width" : 100, "color" : "red", },
				{ "name" : "OneGuildGaugePoint", "type" : "text", "x" : 223, "y" : 55 },
				## OneGuild Text and Symbol and Gauge End

				## TwoGuild Text and Symbol and Gauge Start
				{ "name" : "TwoGuild", "type" : "text", "x" : 35, "y" : 75 },
				{ "name" : "TwoGuildMark", "type" : "mark", "x" : 16, "y" : 77 },
				{ "name" : "TwoGuildGauge", "type" : "gauge",  "x" : 145, "y" : 79, "width" : 100, "color" : "red", },
				{ "name" : "TwoGuildGaugePoint", "type" : "text", "x" : 223, "y" : 75 },
				## TwoGuild Text and Symbol and Gauge End

				## ThreeGuild Text and Symbol and Gauge Start
				{ "name" : "ThreeGuild", "type" : "text", "x" : 35, "y" : 95 },
				{ "name" : "ThreeGuildMark", "type" : "mark", "x" : 16, "y" : 97 },
				{ "name" : "ThreeGuildGauge", "type" : "gauge",  "x" : 145, "y" : 99, "width" : 100, "color" : "red", },
				{ "name" : "ThreeGuildGaugePoint", "type" : "text", "x" : 223, "y" : 95 },
				## ThreeGuild Text and Symbol and Gauge End

				## FourGuild Text and Symbol and Gauge Start
				{ "name" : "FourGuild", "type" : "text", "x" : 35, "y" : 115 },
				{ "name" : "FourGuildMark", "type" : "mark", "x" : 16, "y" : 117 },
				{ "name" : "FourGuildGauge", "type" : "gauge",  "x" : 145, "y" : 119, "width" : 100, "color" : "red", },
				{ "name" : "FourGuildGaugePoint", "type" : "text", "x" : 223, "y" : 115 },
				## FourGuild Text and Symbol and Gauge End

				## FiveGuild Text and Symbol and Gauge Start
				{ "name" : "FiveGuild", "type" : "text", "x" : 35, "y" : 135 },
				{ "name" : "FiveGuildMark", "type" : "mark", "x" : 16, "y" : 137 },
				{ "name" : "FiveGuildGauge", "type" : "gauge",  "x" : 145, "y" : 139, "width" : 100, "color" : "red", },
				{ "name" : "FiveGuildGaugePoint", "type" : "text", "x" : 223, "y" : 135 },
				## FiveGuild Text and Symbol and Gauge End

			),
		},
	),
}
