#include "ClassWorld.h"

World::World()
{
	rooms = new Room[12];
	exits = new Exit[11];
	adventurer = new Player[1];
	playing = true;
}

void World::CreateWorld(const char* str)
{
	adventurer[0].ModifyName(str);

	rooms[0].ModifyParameters("Hall", "It's an old fashioned hall, with loads of old panitings hanging on walls and a couple of rusty armors in the center. It's barely illuminated.");
	rooms[0].ModifyOptions(2, -1, -1, 1);
	rooms[0].ModifyDoors(1, -1, -1, 0);

	rooms[1].ModifyParameters("West of hall", "Something smells rotten in this room. It's a lot darker than the hall. There's a misterious masked man in the center staring at you.");
	rooms[1].ModifyOptions(-1, -1, 0, -1);
	rooms[1].ModifyDoors(-1, -1, 0, -1);

	rooms[2].ModifyParameters("North of hall", "Its a small room with one door at each wall.");
	rooms[2].ModifyOptions(5, 0, 4, 3);
	rooms[2].ModifyDoors(4, 1, 3, 2);

	rooms[3].ModifyParameters("SnS room", "It's a small room with a strange switch on a wall. There's also a man laying on a blood paddle.");
	rooms[3].ModifyOptions(-1, -1, 2, -1);
	rooms[3].ModifyDoors(-1, -1, 2, -1);

	rooms[4].ModifyParameters("Bathroom", "So this is actually a bathroom. Someone must've erased the 'h' on the entrance sign. Such a filthy prankster.");
	rooms[4].ModifyOptions(-1, -1, -1, 2);
	rooms[4].ModifyDoors(-1, -1, -1, 3);

	rooms[5].ModifyParameters("Copper room", "Every wall in this room is painted in copper, including both doors.");
	rooms[5].ModifyOptions(6, 2, -1, -1);
	rooms[5].ModifyDoors(5, 4, -1, -1);

	rooms[6].ModifyParameters("Silver room", "Every wall in this room is painted in silver but this time it's only the northern door the one painted the same way.");
	rooms[6].ModifyOptions(9, 5, 8, 7);
	rooms[6].ModifyDoors(8, 5, 7, 6);

	rooms[7].ModifyParameters("Toucan room", "There's a toucan holding something in his beak. He's laughing at your pijama.");
	rooms[7].ModifyOptions(-1, -1, 6, -1);
	rooms[7].ModifyDoors(-1, -1, 6, -1);

	rooms[8].ModifyParameters("Crack room", "It's completely empty. There's a suspicious crack on the northern wall.");
	rooms[8].ModifyOptions(10, -1, -1, 6);
	rooms[8].ModifyDoors(9, -1, -1, 7);

	rooms[9].ModifyParameters("Grenade room", "This room would be completely empty if there wasn't a chest right in the center of it.");
	rooms[9].ModifyOptions(-1, 6, -1, -1);
	rooms[9].ModifyDoors(-1, 8, -1, -1);

	rooms[10].ModifyParameters("Dragon room", "It smells like if something had been burning for days in here. You notice a huge dragon staring at you. His face doesn't look like the face of mercy.");
	rooms[10].ModifyOptions(-1, 8, 11, -1);
	rooms[10].ModifyDoors(-1, 9, 10, -1);

	rooms[11].ModifyParameters("Orb room", "There's a long passage that leads to something that looks like an altar. Something shines on it.");
	rooms[11].ModifyOptions(-1, -1, -1, 10);
	rooms[11].ModifyDoors(-1, -1, -1, 10);


	exits[0].ModifyDescription("A wooden door that leads to a western room.");

	exits[1].ModifyDescription("A huge door that leads to a northern room.");

	exits[2].ModifyDescription("You feel like there's gonna be something useful inside.");

	exits[3].ModifyDescription("There's a sing on the wall. It says 'Bat room'.");

	exits[4].ModifyDescription("This door leads deeper into this strange place. It has a strange locking mechanism.");

	exits[5].ModifyDescription("This door is made out of copper.");
	exits[5].ModifyState();

	exits[6].ModifyDescription("You smell bird shit on the other side.");

	exits[7].ModifyDescription("A wooden door that leads to an eastern room.");

	exits[8].ModifyDescription("This door is made out of silver.");
	exits[8].ModifyState();

	exits[9].ModifyDescription("There's a crack on the wall.");

	exits[10].ModifyDescription("It's a door made out of gold.");
}

void World::CheckRoom(int i)const
{
	cout << rooms[i].GetName() << endl << rooms[i].GetDescription() << endl << endl;
}

int World::CheckPosition()const
{
	return adventurer[0].CheckPosition();
}

void World::Move(int position)
{
	adventurer[0].ModifyPosition(position);
}
void World::Execute(char instruction[25], int dir, int &position)const
{

	if (strcmp(instruction,"look") == 0)
	{
		if (rooms[position].CheckDoors(dir) != -1)
		{
			cout << exits[rooms[position].CheckDoors(dir)].GetDescription() << endl << endl;
		}
		else if (rooms[position].CheckDoors(dir) == -1)
			cout << "There's no door in that direction." << endl << endl;	
	}
	else if (strcmp(instruction, "go") == 0)
	{
		if (rooms[position].CheckOptions(dir) != -1 && exits[rooms[position].CheckDoors(dir)].IsOpen())
		{
			position = rooms[position].CheckOptions(dir);
			cout << rooms[position].GetName() << endl << rooms[position].GetDescription() << endl << endl;
		}
		else if (rooms[position].CheckOptions(dir) == -1)
		{
			cout << "There's no room in that direction." << endl << endl;
		}
		else
		{
			cout << "The door is closed." << endl << endl;
		}
	}
	else if (strcmp(instruction, "open") == 0)
	{
		if (rooms[position].CheckDoors(dir) != -1 && exits[rooms[position].CheckDoors(dir)].IsOpen() == false)
		{
			exits[rooms[position].CheckDoors(dir)].ModifyState();
			cout << "The door is now open." << endl << endl;
		}
		else
		{
			cout << "The door is already open." << endl << endl;
		}
	}
	else if (strcmp(instruction, "close") == 0)
	{
		if (rooms[position].CheckDoors(dir) != -1 && exits[rooms[position].CheckDoors(dir)].IsOpen())
		{
			exits[rooms[position].CheckDoors(dir)].ModifyState();
			cout << "The door is now closed" << endl << endl;
		}
	}
	else if (strcmp(instruction, "lookroom") == 0)
	{
		cout << rooms[position].GetDescription() << endl << endl;
	}
}

bool World::Continue()const
{
	return playing;
}

void World::EndGame()
{
	playing = false;
}

World::~World()
{
	delete[]rooms;
	delete[]exits;
	delete[]adventurer;
}