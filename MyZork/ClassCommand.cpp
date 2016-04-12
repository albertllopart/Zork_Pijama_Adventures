#include "ClassCommand.h"

void Command::ReadInstruction(String& str, int &dir)const
{

	//HELP

	if (str == "help")
	{
		cout << "Move using the 'n', 's', 'e', 'w' keys, 'north/south/east/west' or 'go + north/south/east/west' commands." << endl;
		cout << "Check door descriptions using 'look + north/south/east/west', player description using 'look + player/me/myself' or room descriptions using 'look room' command" << endl;
		cout << "Open and close doors by using the 'open/close + direction' command" << endl;
		cout << "Use 'quit' command to quit the game" << endl << endl;
		dir = stay;
	}

	//LOOK

	else if (str == "look north") 
	{
		dir = north;
		str = "look!";
	}
	else if (str == "look south") 
	{
		dir = south;
		str = "look!";
	}
	else if (str == "look east") 
	{
		dir = east;
		str = "look!";
	}
	else if (str == "look west") 
	{
		dir = west;
		str = "look!";
	}
	else if (str == "look player"|| str == "look myself" || str == "look me")
	{
		dir = stay;
		str = "lookplayer";
	}
	else if (str == "look room")
	{
		dir = stay;
		str = "lookroom";
	}

	//GO

	else if (str == "go north"|| str == "north"|| str == "n") 
	{
		dir = north;
		str = "go!";
	}
	else if (str == "go south" || str == "south" || str == "s")
	{
		dir = south;
		str = "go!";
	}
	else if (str == "go east" || str == "east" || str == "e")
	{
		dir = east;
		str = "go!";
	}
	else if (str == "go west" || str == "west" || str == "w")
	{
		dir = west;
		str = "go!";
	}
	

	//OPEN

	else if (str == "open north") 
	{
		dir = north;
		str = "open!";
	}
	else if (str == "open south")
	{
		dir = south;
		str = "open!";
	}
	else if (str == "open east")
	{
		dir = east;
		str = "open!";
	}
	else if (str == "open west")
	{
		dir = west;
		str = "open!";
	}

	//CLOSE

	else if (str == "close north") 
	{
		dir = north;
		str = "close!";
	}
	else if (str == "close south")
	{
		dir = south;
		str = "close!";
	}
	else if (str == "close east")
	{
		dir = east;
		str = "close!";
	}
	else if (str == "close west")
	{
		dir = west;
		str = "close!";
	}

	//ELSE

	else
	{
		cout << "Unknown command" << endl << endl;
		dir = stay;
	}
}
