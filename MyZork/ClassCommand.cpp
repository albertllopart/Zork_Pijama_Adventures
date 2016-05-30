#include "ClassCommand.h"

Command::Command()
{
	dir = stay;
	item = nothing;
}

void Command::ModifyDirection(int dir)
{
	this->dir = dir;
}
void Command::ModifyItem(int item)
{
	this->item = item;
}
void Command::ModifyitemName(const char* itemName)
{
	this->itemName = itemName;
}
int Command::GetDirection()const
{
	return dir;
}
int Command::GetItem()const
{
	return item;
}
const String& Command::GetItemName()const
{
	return itemName;
}

void Command::ReadInstruction(String& str)
{

	//HELP

	if (str == "help")
	{
		cout << "MOVEMENT" << endl << endl;
		cout << "Move using the 'n', 's', 'e', 'w' keys, 'north/south/east/west' or 'go + north/south/east/west' commands." << endl;
		cout << "Open doors by using the 'open door' command." << endl << endl;
		cout << "INFORMATION" << endl << endl;
		cout << "Check door descriptions using 'look + north/south/east/west', player description using 'look + player/me/myself' or room descriptions using 'look room' command." << endl;
		cout << "Check NPC descriptions using 'look + NPC name (or something similar. There are some combinations that work)" << endl;
		cout << "You can check item descriptions by using the command 'look + <item>'" << endl;
		cout << "Check your inventory at any time by using the command 'look/check + inventory or inventory/inv/i" << endl;
		cout << "Check what the box contains by using 'look/check + box' command." << endl;
		cout << "Check your stats with the 'stats' command and check your equipment with the 'equipment, look equipment or check equipment' command." << endl << endl;
		cout << "INTERACTION" << endl << endl;
		cout << "Pick or drop items by using the 'pick/drop + <item>' command. You can also store items in a Box by using the commands 'put/get + <item> + into/from + box'." << endl;
		cout << "Equip and unequip items by using the commands 'equip/unequip + <item>'" << endl;
		cout << "Use items by using the command 'use + item'. Notice that this command will only work in certain rooms and with certain items." << endl;
		cout << "Press buttons with 'press button' command and open chests with the 'open chest' command." << endl;
		cout << "Talk to the Misterious Masked Man with the 'talk man / talk to man / talk misterious ... etc' command." << endl << endl;
		cout << "Use 'quit' command to quit the game." << endl << endl;
	}

	//LOOK EXITS

	else if (str == "look north") 
	{
		ModifyDirection(north);
		str = "look!";
	}
	else if (str == "look south") 
	{
		ModifyDirection(south);
		str = "look!";
	}
	else if (str == "look east") 
	{
		ModifyDirection(east);
		str = "look!";
	}
	else if (str == "look west") 
	{
		ModifyDirection(west);
		str = "look!";
	}

	//LOOK ITEMS

	else if (str == "look sword")
	{
		ModifyItem(sword);
		ModifyitemName("Sword");
		str = "look!";
	}
	else if (str == "look shield")
	{
		ModifyItem(shield);
		ModifyitemName("Wooden Shield");
		str = "look!";
	}
	else if (str == "look sack of grain")
	{
		ModifyItem(sack);
		ModifyitemName("Sack of grain");
		str = "look!";
	}
	else if (str == "look copper key")
	{
		ModifyItem(copper);
		ModifyitemName("Copper Key");
		str = "look!";
	}
	else if (str == "look silver key")
	{
		ModifyItem(silver);
		ModifyitemName("Silver Key");
		str = "look!";
	}
	else if (str == "look grenade")
	{
		ModifyItem(grenade);
		ModifyitemName("Grenade");
		str = "look!";
	}
	else if (str == "look orb")
	{
		ModifyItem(orb);
		ModifyitemName("Orb");
		str = "look!";
	}

	//LOOK INVENTORY

	else if (str == "look inventory" || str == "check inventory" || str == "inventory" || str == "inv" || str == "i")
	{
		ModifyItem(sword);
		ModifyitemName("Sword");
		str = "lookinventory";
	}

	//LOOK BOX, CHEST, CREATURES

	else if (str == "look box" || str == "check box")
	{
		str = "lookbox!";
	}
	else if (str == "look chest")
	{
		str = "lookchest!";
	}
	else if (str == "look misterious man" || str == "look misterious masked man")
	{
		str = "lookmisterious!";
	}
	else if (str == "look man")
	{
		str = "lookman!";
	}
	else if (str == "look body" || str == "look cadaver")
	{
		str = "lookwarrior!";
	}
	else if (str == "look toucan")
	{
		str = "looktoucan!";
	}
	else if (str == "look skeleton")
	{
		str = "lookskeleton!";
	}
	else if (str == "look dragon")
	{
		str = "lookdragon!";
	}

	//LOOK PLAYER

	else if (str == "look player"|| str == "look myself" || str == "look me")
	{
		ModifyDirection(stay);
		str = "lookplayer";
	}

	//LOOK ROOM
	else if (str == "look room")
	{
		ModifyDirection(stay);
		ModifyItem(sword);
		ModifyitemName("Sword");
		str = "lookroom";
	}

	//TALK TO MISTERIOUS MASKED MAN

	else if (str == "talk to man" || str == "talk to the man" || str == "talk man" || str == "talk to misterious man" || str == "talk to misterious masked man")
	{
		str = "talkman!";
	}

	//GO

	else if (str == "go north"|| str == "north"|| str == "n") 
	{
		ModifyDirection(north);
		str = "go!";
	}
	else if (str == "go south" || str == "south" || str == "s")
	{
		ModifyDirection(south);
		str = "go!";
	}
	else if (str == "go east" || str == "east" || str == "e")
	{
		ModifyDirection(east);
		str = "go!";
	}
	else if (str == "go west" || str == "west" || str == "w")
	{
		ModifyDirection(west);
		str = "go!";
	}
	

	//OPEN

	else if (str == "open door") 
	{
		str = "open!";
	}

	//KEYS

	else if (str == "use copper key")
	{
		ModifyitemName("Copper Key");
		str = "opencopper!";
	}
	else if (str == "use silver key")
	{
		ModifyitemName("Silver Key");
		str = "opensilver!";
	}

	//OPEN CHEST

	else if (str == "open chest")
	{
		ModifyitemName("Grenade");
		str = "openchest!";
	}

	//BUTTON

	else if (str == "press button")
	{
		str = "pressbutton!";
	}

	//SACK OF GRAIN

	else if (str == "use sack of grain")
	{
		ModifyitemName("Sack of grain");
		str = "sackofgrain!";
	}

	//GRENADE

	else if (str == "use grenade")
	{
		ModifyitemName("Grenade");
		str = "grenade!";
	}
	
	//PICK

	else if (str == "pick sword")
	{
		ModifyItem(sword);
		ModifyitemName("Sword");
		str = "pick!";
	}
	else if (str == "pick shield")
	{
		ModifyItem(shield);
		ModifyitemName("Wooden Shield");
		str = "pick!";
	}
	else if (str == "pick sack of grain")
	{
		ModifyItem(sack);
		ModifyitemName("Sack of grain");
		str = "pick!";
	}
	else if (str == "pick copper key")
	{
		ModifyItem(copper);
		ModifyitemName("Copper Key");
		str = "pick!";
	}
	else if (str == "pick silver key")
	{
		ModifyItem(silver);
		ModifyitemName("Silver Key");
		str = "pick!";
	}
	else if (str == "pick grenade")
	{
		ModifyItem(grenade);
		ModifyitemName("Grenade");
		str = "pick!";
	}
	else if (str == "pick orb")
	{
		ModifyItem(orb);
		ModifyitemName("Orb");
		str = "pick!";
	}

	//DROP

	else if (str == "drop sword")
	{
		ModifyItem(sword);
		ModifyitemName("Sword");
		str = "drop!";
	}
	else if (str == "drop shield")
	{
		ModifyItem(shield);
		ModifyitemName("Wooden Shield");
		str = "drop!";
	}
	else if (str == "drop sack of grain")
	{
		ModifyItem(sack);
		ModifyitemName("Sack of grain");
		str = "drop!";
	}
	else if (str == "drop copper key")
	{
		ModifyItem(copper);
		ModifyitemName("Copper Key");
		str = "drop!";
	}
	else if (str == "drop silver key")
	{
		ModifyItem(silver);
		ModifyitemName("Silver Key");
		str = "drop!";
	}
	else if (str == "drop grenade")
	{
		ModifyItem(grenade);
		ModifyitemName("Grenade");
		str = "drop!";
	}
	else if (str == "drop orb")
	{
		ModifyItem(orb);
		ModifyitemName("Orb");
		str = "drop!";
	}
	else if (str == "drop toucan")
	{
		str = "droptoucan!";
	}

	//PUT ITEM INTO BOX

	else if (str == "put sword into box")
	{
		ModifyItem(sword);
		ModifyitemName("Sword");
		str = "putinto";
	}
	else if (str == "put shield into box")
	{
		ModifyItem(shield);
		ModifyitemName("Wooden Shield");
		str = "putinto";
	}
	else if (str == "put sack of grain into box")
	{
		ModifyItem(sack);
		ModifyitemName("Sack of grain");
		str = "putinto";
	}
	else if (str == "put copper key into box")
	{
		ModifyItem(copper);
		ModifyitemName("Copper Key");
		str = "putinto";
	}
	else if (str == "put silver key into box")
	{
		ModifyItem(silver);
		ModifyitemName("Silver Key");
		str = "putinto";
	}
	else if (str == "put grenade into box")
	{
		ModifyItem(grenade);
		ModifyitemName("Grenade");
		str = "putinto";
	}
	else if (str == "put orb into box")
	{
		ModifyItem(orb);
		ModifyitemName("Orb");
		str = "putinto";
	}

	//GET ITEM FROM BOX

	else if (str == "get sword from box")
	{
		ModifyItem(sword);
		ModifyitemName("Sword");
		str = "getfrom";
	}
	else if (str == "get shield from box")
	{
		ModifyItem(shield);
		ModifyitemName("Wooden Shield");
		str = "getfrom";
	}
	else if (str == "get sack of grain from box")
	{
		ModifyItem(sack);
		ModifyitemName("Sack of grain");
		str = "getfrom";
	}
	else if (str == "get copper key from box")
	{
		ModifyItem(copper);
		ModifyitemName("Copper Key");
		str = "getfrom";
	}
	else if (str == "get silver key from box")
	{
		ModifyItem(silver);
		ModifyitemName("Silver Key");
		str = "getfrom";
	}
	else if (str == "get grenade from box")
	{
		ModifyItem(grenade);
		ModifyitemName("Grenade");
		str = "getfrom";
	}
	else if (str == "get orb from box")
	{
		ModifyItem(orb);
		ModifyitemName("Orb");
		str = "getfrom";
	}

	//EQUIP ITEM

	else if (str == "equip sword")
	{
		ModifyItem(sword);
		ModifyitemName("Sword");
		str = "equip!";
	}
	else if (str == "equip shield")
	{
		ModifyItem(shield);
		ModifyitemName("Wooden Shield");
		str = "equip!";
	}
	else if (str == "equip copper key")
	{
		ModifyItem(copper);
		ModifyitemName("Copper Key");
		str = "equip!";
	}
	else if (str == "equip silver key")
	{
		ModifyItem(silver);
		ModifyitemName("Silver Key");
		str = "equip!";
	}
	else if (str == "equip sack of grain")
	{
		ModifyItem(sack);
		ModifyitemName("Sack of grain");
		str = "equip!";
	}
	else if (str == "equip grenade")
	{
		ModifyItem(grenade);
		ModifyitemName("Grenade");
		str = "equip!";
	}
	else if (str == "equip orb")
	{
		ModifyItem(orb);
		ModifyitemName("Orb");
		str = "equip!";
	}

	//UNEQUIP ITEM

	else if (str == "unequip sword")
	{
		ModifyItem(sword);
		ModifyitemName("Sword");
		str = "unequip!";
	}
	else if (str == "unequip shield")
	{
		ModifyItem(shield);
		ModifyitemName("Wooden Shield");
		str = "unequip!";
	}
	else if (str == "equip copper key")
	{
		ModifyItem(copper);
		ModifyitemName("Copper Key");
		str = "unequip!";
	}
	else if (str == "equip silver key")
	{
		ModifyItem(silver);
		ModifyitemName("Silver Key");
		str = "unequip!";
	}
	else if (str == "equip sack of grain")
	{
		ModifyItem(sack);
		ModifyitemName("Sack of grain");
		str = "unequip!";
	}
	else if (str == "equip grenade")
	{
		ModifyItem(grenade);
		ModifyitemName("Grenade");
		str = "unequip!";
	}
	else if (str == "equip orb")
	{
		ModifyItem(orb);
		ModifyitemName("Orb");
		str = "unequip!";
	}

	//STATS

	else if (str == "stats")
	{
		str = "stats!";
	}

	//EQUIPMENT

	else if (str == "equipment" || str == "look equipment" || str == "check equipment")
	{
		str = "equipment!";
	}

	//TELEPORT (FOR DEVELOPER ONLY!!!)

	else if (str == "teleport 1")
	{
		str = "teleport 1";
		dir = 33;
	}
	else if (str == "teleport 2")
	{
		str = "teleport 2";
		dir = 33;
	}
	else if (str == "teleport 3")
	{
		str = "teleport 3";
		dir = 33;
	}

	//CHEAT

	else if (str == "photonman")
	{
		str = "photonman!";
	}

	//ELSE

	else
	{
		cout << "Unknown command" << endl << endl;
	}
}

Command::~Command(){};
