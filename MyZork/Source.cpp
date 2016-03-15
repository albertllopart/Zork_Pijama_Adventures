#include <stdio.h>
#include "ClassWorld.h"



int main()
{
	World dungeon;
	Player adventurer;
	dungeon.CreateWorld();
	char advName[25];

	cout << "Use the 'help' command to see your action options during the game" << endl << endl;
	cout << "Enter your name" << endl;
	gets_s(advName);
	adventurer.ModifyName(advName);

	cout << endl << "You wake up in a strange place you can't recognize. You can't remember what you were doing before falling unconscious." << endl << endl;
	dungeon.CheckRoom(0);

	while (dungeon.Continue())
	{
		char instruction[25];
		int dir = -1;
		gets_s(instruction);
		if (strcmp(instruction, "quit") == 0) dungeon.EndGame();
		else
		{
			Command command;
			command.ReadInstruction(instruction, dir);
			int position = adventurer.CheckPosition();
			dungeon.Execute(instruction, dir, position);
			adventurer.ModifyPosition(position);
		}
	}
}
