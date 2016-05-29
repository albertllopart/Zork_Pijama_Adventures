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

	char instruction[50];
	String order(instruction);
	int position = 0;
	int lastposition;

	cout << endl << "You wake up in a strange place you can't recognize. You can't remember what you were doing before falling unconscious." << endl << endl;
	dungeon.CheckRoom(0);

	while (dungeon.Continue())
	{
		gets_s(instruction);
		order = instruction;

		if (order == "quit") dungeon.EndGame();
		else
		{
			lastposition = position;
			position = dungeon.CheckPosition();
			command.ReadInstruction(order);
			dungeon.Execute(order, command.GetDirection(), command.GetItemName(), command.GetItem(), position);
			dungeon.Move(position);
			if (command.GetDirection() != -1 && order != "look!" && order != "open!" && order != "close!" && lastposition != position)
			{
				dungeon.CheckRoom(position);
			}
			command.ModifyDirection(-1);
			command.ModifyItem(-1);
		}
	}
}
