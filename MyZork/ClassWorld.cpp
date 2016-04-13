#include "ClassWorld.h"

World::World(const char* str)
{
	names = new String[11];
	names[0] = "Hall";
	names[1] = "West of hall";
	names[2] = "North of hall";
	names[3] = "SnS Room";
	names[4] = "Bathroom";
	names[5] = "Copper Room";
	names[6] = "Silver Room";
	names[7] = "Toucan Room";
	names[8] = "Crack Room";
	names[9] = "Grenade Room";
	names[10] = "Dragon Room";
	names[11] = "Orb Room";

	descriptions = new String[11];
	descriptions[0] = "It's an old fashioned hall, with loads of old panitings hanging on walls and a couple of rusty armors in the center. It's barely illuminated.";
	descriptions[1] = "Something smells rotten in this room. It's a lot darker than the hall. There's a misterious masked man in the center staring at you.";
	descriptions[2] = "Its a small room with one door at each wall.";
	descriptions[3] = "It's a small room with a strange switch on a wall. There's also a man laying on a blood paddle.";
	descriptions[4] = "So this is actually a bathroom. Someone must've erased the 'h' on the entrance sign. Such a filthy prankster.";
	descriptions[5] = "Every wall in this room is painted in copper, including both doors.";
	descriptions[6] = "Every wall in this room is painted in silver but this time it's only the northern door the one painted the same way.";
	descriptions[7] = "There's a toucan holding something in his beak. He's laughing at your pijama.";
	descriptions[8] = "It's completely empty. There's a suspicious crack on the northern wall.";
	descriptions[9] = "This room would be completely empty if there wasn't a chest right in the center of it.";
	descriptions[10] = "It smells like if something had been burning for days in here. You notice a huge dragon staring at you. His face doesn't look like the face of mercy.";
	descriptions[11] = "There's a long passage that leads to something that looks like an altar. Something shines on it.";

	for (int i = 0; i < 12; i++)
	{
		rooms.PushBack(new Room(names[i], descriptions[i]));
	}

	//rooms.PushBack(new Room("caca", "de vaca"));
	
	descriptions[0] = "A wooden door that leads to a western room.";
	descriptions[1] = "A huge door that leads to a northern room.";
	descriptions[2] = "You feel like there's gonna be something useful inside.";
	descriptions[3] = "There's a sing on the wall. It says 'Bat room'.";
	descriptions[4] = "This door leads deeper into this strange place. It has a strange locking mechanism.";
	descriptions[5] = "This door is made out of copper.";
	descriptions[6] = "You smell bird shit on the other side.";
	descriptions[7] = "A wooden door that leads to an eastern room.";
	descriptions[8] = "This door is made out of silver.";
	descriptions[9] = "There's a crack on the wall.";
	descriptions[10] = "It's a door made out of gold.";

	for (int i = 0; i < 11; i++)
	{
		exits.PushBack(new Exit(descriptions[i]));
	}

	descriptions[0] = "You are wearing a warm pijama and slippers";

	adventurer = new Player(str, descriptions[0]);

	playing = true;
}

void World::CreateWorld()
{
	
	rooms[0]->ModifyOptions(2, -1, -1, 1);
	rooms[0]->ModifyDoors(1, -1, -1, 0);

	rooms[1]->ModifyOptions(-1, -1, 0, -1); 
	rooms[1]->ModifyDoors(-1, -1, 0, -1);

	rooms[2]->ModifyOptions(5, 0, 4, 3);
	rooms[2]->ModifyDoors(4, 1, 3, 2);

	rooms[3]->ModifyOptions(-1, -1, 2, -1);
	rooms[3]->ModifyDoors(-1, -1, 2, -1);

	rooms[4]->ModifyOptions(-1, -1, -1, 2);
	rooms[4]->ModifyDoors(-1, -1, -1, 3);

	rooms[5]->ModifyOptions(6, 2, -1, -1);
	rooms[5]->ModifyDoors(5, 4, -1, -1);

	rooms[6]->ModifyOptions(9, 5, 8, 7);
	rooms[6]->ModifyDoors(8, 5, 7, 6);

	rooms[7]->ModifyOptions(-1, -1, 6, -1);
	rooms[7]->ModifyDoors(-1, -1, 6, -1);

	rooms[8]->ModifyOptions(10, -1, -1, 6);
	rooms[8]->ModifyDoors(9, -1, -1, 7);

	rooms[9]->ModifyOptions(-1, 6, -1, -1);
	rooms[9]->ModifyDoors(-1, 8, -1, -1);

	rooms[10]->ModifyOptions(-1, 8, 11, -1);
	rooms[10]->ModifyDoors(-1, 9, 10, -1);

	rooms[11]->ModifyOptions(-1, -1, -1, 10);
	rooms[11]->ModifyDoors(-1, -1, -1, 10);

	exits[5]->ModifyState();
	exits[8]->ModifyState();

}

void World::CheckRoom(int i)const
{
	cout << rooms[i]->GetName() << endl << rooms[i]->GetDescription() << endl << endl;
}

int World::CheckPosition()const
{
	return adventurer[0].CheckPosition();
}

void World::Move(int position)
{
	adventurer[0].ModifyPosition(position);
}
void World::Execute(const String& str, int dir, int &position)const
{

	if (str == "look!")
	{
		if (rooms[position]->CheckDoors(dir) != -1)
		{
			cout << exits[rooms[position]->CheckDoors(dir)]->GetDescription() << endl << endl;
		}
		else if (rooms[position]->CheckDoors(dir) == -1)
			cout << "There's no door in that direction." << endl << endl;	
	}
	else if (str == "go!")
	{
		if (rooms[position]->CheckOptions(dir) != -1 && exits[rooms[position]->CheckDoors(dir)]->IsOpen())
		{
			position = rooms[position]->CheckOptions(dir);
			cout << rooms[position]->GetName() << endl << rooms[position]->GetDescription() << endl << endl;
		}
		else if (rooms[position]->CheckOptions(dir) == -1)
		{
			cout << "There's no room in that direction." << endl << endl;
		}
		else
		{
			cout << "The door is closed." << endl << endl;
		}
	}
	else if (str == "open!")
	{
		if (rooms[position]->CheckDoors(dir) != -1 && exits[rooms[position]->CheckDoors(dir)]->IsOpen() == false)
		{
			exits[rooms[position]->CheckDoors(dir)]->ModifyState();
			cout << "The door is now open." << endl << endl;
		}
		else
		{
			cout << "The door is already open." << endl << endl;
		}
	}
	else if (str == "close!")
	{
		if (rooms[position]->CheckDoors(dir) != -1 && exits[rooms[position]->CheckDoors(dir)]->IsOpen())
		{
			exits[rooms[position]->CheckDoors(dir)]->ModifyState();
			cout << "The door is now closed" << endl << endl;
		}
	}
	else if (str == "lookroom")
	{
		cout << rooms[position]->GetDescription() << endl << endl;
	}
	else if (str == "lookplayer")
	{
		cout << adventurer[0].GetDescription() << endl << endl;
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
	delete adventurer;
}