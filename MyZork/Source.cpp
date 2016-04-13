#include <stdio.h>
#include "ClassWorld.h"
#include "ClassString.h"



int main()
{

	cout << "Use the 'help' command to see your action options during the game" << endl << endl;
	cout << "Enter your name" << endl;
	
	char PlayerName[25];
	gets_s(PlayerName);

	World dungeon(PlayerName);
	Command command;
	
	dungeon.CreateWorld();

	int dir = -1;
	char instruction[25];
	String order(instruction);
	int position;

	cout << endl << "You wake up in a strange place you can't recognize. You can't remember what you were doing before falling unconscious." << endl << endl;
	dungeon.CheckRoom(0);

	while (dungeon.Continue())
	{
		gets_s(instruction);
		order = instruction;

		if (order == "quit") dungeon.EndGame();
		else
		{
			position = dungeon.CheckPosition();
			command.ReadInstruction(order, dir);
			dungeon.Execute(order, dir, position);
			dungeon.Move(position);
		}
	}
}
