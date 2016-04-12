#include <stdio.h>
#include "ClassWorld.h"
#include "ClassString.h"



int main()
{
	World dungeon;

	cout << "Use the 'help' command to see your action options during the game" << endl << endl;
	cout << "Enter your name" << endl;
	
	char PlayerName[25];
	gets_s(PlayerName);
	
	dungeon.CreateWorld(PlayerName);

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
			int position = dungeon.CheckPosition();
			dungeon.Execute(instruction, dir, position);
			dungeon.Move(position);
		}
	}
}
