#include <stdio.h>
#include "ClassWorld.h"
#include "ClassString.h"
#include <time.h>
#include <Windows.h>
#include <conio.h>



int main()
{

	cout << "Use the 'help' command to see your action options during the game" << endl << endl;
	cout << "Enter your name" << endl;
	
	char PlayerName[25];
	gets_s(PlayerName);

	World dungeon(PlayerName);
	Command command;
	
	srand(time(NULL));

	dungeon.CreateWorld();

	char instruction[50];
	String order(instruction);
	int position = 0;
	int lastposition;
	int time = 0;
	int lapse = 0;

	cout << endl << "You wake up in a strange place you can't recognize. You can't remember what you were doing before falling unconscious." << endl << endl;
	dungeon.CheckRoom(0);

	while (dungeon.Continue())
	{
		time = GetTickCount();

		if (dungeon.Talking() == false && time >= lapse + 5000)
		{
			lapse = time;
			int direction = rand() % 4;
			dungeon.NPCMove(direction);
		}

		if (_kbhit())
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
				if (command.GetDirection() != -1 && order != "look!" && order != "open!" && order != "close!" && lastposition != position)
				{
					dungeon.CheckRoom(position);
				}
				if (dungeon.fighting)
				{
					dungeon.DragonFight();
					if (dungeon.dead)
					{
						while (1)
						{
							if (_kbhit())
							{
								dungeon.EndGame();
								break;
							}
						}
					}
				}
				if (dungeon.chasing)
				{
					dungeon.SkeletonChase();
					if (dungeon.dead)
					{
						while (1)
						{
							if (_kbhit())
							{
								dungeon.EndGame();
								break;
							}
						}
					}
				}
				if (dungeon.ending)
				{
					while (1)
					{
						if (_kbhit())
						{
							dungeon.EndGame();
							break;
						}
					}
				}
				command.ModifyDirection(-1);
				command.ModifyItem(-1);
			}
		}

	}
}
