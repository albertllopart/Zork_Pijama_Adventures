#include "ClassCommand.h"

void Command::ReadInstruction(char instr[25], int &dir)const
{

	//HELP

	if (strcmp(instr, "help") == 0)
	{
		cout << "Move using the 'n', 's', 'e', 'w' keys, 'north/south/east/west' or 'go + north/south/east/west' commands." << endl;
		cout << "Check door descriptions using 'look + north/south/east/west', player description using 'look + player/me/myself' or room descriptions using 'look room' command" << endl;
		cout << "Open and close doors by using the 'open/close + direction' command" << endl;
		cout << "Use 'quit' command to quit the game" << endl << endl;
		dir = stay;
	}

	//LOOK

	else if (strcmp(instr, "look north") == 0) 
	{
		dir = north;
		strcpy(instr, "look");
	}
	else if (strcmp(instr, "look south") == 0) 
	{
		dir = south;
		strcpy(instr, "look");
	}
	else if (strcmp(instr, "look east") == 0) 
	{
		dir = east;
		strcpy(instr, "look");
	}
	else if (strcmp(instr, "look west") == 0) 
	{
		dir = west;
		strcpy(instr, "look");
	}
	else if (strcmp(instr, "look player") == 0 || strcmp(instr, "look myself") == 0 || strcmp(instr, "look me") == 0)
	{
		dir = stay;
		cout << "You're wearing a warm pijama and slippers." << endl << endl;
	}
	else if (strcmp(instr, "look room") == 0)
	{
		dir = stay;
		strcpy(instr, "lookroom");
	}

	//GO

	else if (strcmp(instr, "go north") == 0 || strcmp(instr, "north") == 0 || strcmp(instr, "n") == 0) 
	{
		dir = north;
		strcpy(instr, "go");
	}
	else if (strcmp(instr, "go south") == 0 || strcmp(instr, "south") == 0 || strcmp(instr, "s") == 0) 
	{
		dir = south;
		strcpy(instr, "go");
	}
	else if (strcmp(instr, "go east") == 0 || strcmp(instr, "east") == 0 || strcmp(instr, "e") == 0) 
	{
		dir = east;
		strcpy(instr, "go");
	}
	else if (strcmp(instr, "go west") == 0 || strcmp(instr, "west") == 0 || strcmp(instr, "w") == 0) 
	{
		dir = west;
		strcpy(instr, "go");
	}

	//OPEN

	else if (strcmp(instr, "open north") == 0) 
	{
		dir = north;
		strcpy(instr, "open");
	}
	else if (strcmp(instr, "open south") == 0) 
	{
		dir = south;
		strcpy(instr, "open");
	}
	else if (strcmp(instr, "open east") == 0) 
	{
		dir = east;
		strcpy(instr, "open");
	}
	else if (strcmp(instr, "open west") == 0) 
	{
		dir = west;
		strcpy(instr, "open");
	}

	//CLOSE

	else if (strcmp(instr, "close north") == 0) 
	{
		dir = north;
		strcpy(instr, "close");
	}
	else if (strcmp(instr, "close south") == 0) 
	{
		dir = south;
		strcpy(instr, "close");
	}
	else if (strcmp(instr, "close east") == 0) 
	{
		dir = east;
		strcpy(instr, "close");
	}
	else if (strcmp(instr, "close west") == 0) 
	{
		dir = west;
		strcpy(instr, "close");
	}

	//ELSE

	else
	{
		cout << "Unknown command" << endl << endl;
		dir = stay;
	}
}
