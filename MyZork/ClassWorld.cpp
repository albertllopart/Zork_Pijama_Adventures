#include "ClassWorld.h"

World::World(const char* str)
{
	rooms.PushBack(new Room("Hall", "It's an old fashioned hall, with loads of old panitings hanging on walls and a couple of rusty armors in the center. It's barely illuminated."));
	rooms.PushBack(new Room("West of hall", "Something smells rotten in this room. It's a lot darker than the hall. There's a misterious masked man in the center staring at you."));
	rooms.PushBack(new Room("North of Hall", "It's a small room with one door at each wall. There's a huge box in the center."));
	rooms.PushBack(new Room("SnS Room", "It's a small room with a strange switch on a wall. There's also a man laying on a blood paddle."));
	rooms.PushBack(new Room("Bathroom", "So this is actually a bathroom. Someone must've erased the 'h' on the entrance sign. Such a filthy prankster."));
	rooms.PushBack(new Room("Copper Room", "Every wall in this room is painted in copper, including both doors."));
	rooms.PushBack(new Room("Silver Room", "Every wall in this room is painted in silver but this time it's only the northern door the one painted the same way."));
	rooms.PushBack(new Room("Toucan Room", "There's a toucan holding something in his beak. He's laughing at your pijama."));
	rooms.PushBack(new Room("Crack Room", "It's completely empty. There's a suspicious crack on the northern wall."));
	rooms.PushBack(new Room("Grenade Room", "This room would be completely empty if there wasn't a chest right in the center of it."));
	rooms.PushBack(new Room("Dragon Room", "It smells like if something had been burning for days in here. You notice a huge dragon staring at you. His face doesn't look like the face of mercy."));
	rooms.PushBack(new Room("Orb Room", "There's a long passage that leads to something that looks like an altar. Something shines on it."));
	
	exits.PushBack(new Exit("A wooden door that leads to a western room."));
	exits.PushBack(new Exit("A huge door that leads to a northern room."));
	exits.PushBack(new Exit("You feel like there's gonna be something useful inside."));
	exits.PushBack(new Exit("There's a sing on the wall. It says 'Bat room'."));
	exits.PushBack(new Exit("This door leads deeper into this strange place. It has a strange locking mechanism."));
	exits.PushBack(new Exit("This door is made out of copper."));
	exits.PushBack(new Exit("You smell bird shit on the other side."));
	exits.PushBack(new Exit("A wooden door that leads to an eastern room."));
	exits.PushBack(new Exit("This door is made out of silver."));
	exits.PushBack(new Exit("There's a crack on the wall."));
	exits.PushBack(new Exit("It's a door made out of gold."));

	items.PushBack(new Item("Sword", "It's a sharp sword!"));
	items.PushBack(new Item("Wooden Shield", "It's a shield strong enough to resist some hits, but do not try to parry fire attacks with it!"));
	items.PushBack(new Item("Sack of grain", "It's a small sack full of grain."));
	items.PushBack(new Item("Copper Key", "It's a key made out of copper."));
	items.PushBack(new Item("Silver Key", "It's a key made out of silver."));
	items.PushBack(new Item("Grenade", "It's just a grenade. Were you really expecting a detailed description?"));
	items.PushBack(new Item("Orb", "It's a blue translucid orb with a shinny core."));

	adventurer = new Player(str, "You're wearing a warm pijaman and slippers.");
	box = new Box("Box", "It's a wooden box. You can store items in it.");

	playing = true;
}

void World::CreateWorld()
{
	
	rooms[0]->ModifyOptions(2, -1, -1, 1);
	rooms[0]->ModifyDoors(1, -1, -1, 0);
	rooms[0]->ModifyItems(-1, -1);

	rooms[1]->ModifyOptions(-1, -1, 0, -1); 
	rooms[1]->ModifyDoors(-1, -1, 0, -1);
	rooms[1]->ModifyItems(-1, -1);

	rooms[2]->ModifyOptions(5, 0, 4, 3);
	rooms[2]->ModifyDoors(4, 1, 3, 2);
	rooms[2]->ModifyItems(-1, -1);

	rooms[3]->ModifyOptions(-1, -1, 2, -1);
	rooms[3]->ModifyDoors(-1, -1, 2, -1);
	rooms[3]->ModifyItems(0, 1);

	rooms[4]->ModifyOptions(-1, -1, -1, 2);
	rooms[4]->ModifyDoors(-1, -1, -1, 3);
	rooms[4]->ModifyItems(3, -1);

	rooms[5]->ModifyOptions(6, 2, -1, -1);
	rooms[5]->ModifyDoors(5, 4, -1, -1);
	rooms[5]->ModifyItems(2, -1);

	rooms[6]->ModifyOptions(9, 5, 8, 7);
	rooms[6]->ModifyDoors(8, 5, 7, 6);
	rooms[6]->ModifyItems(-1, -1);

	rooms[7]->ModifyOptions(-1, -1, 6, -1);
	rooms[7]->ModifyDoors(-1, -1, 6, -1);
	rooms[7]->ModifyItems(4, -1);

	rooms[8]->ModifyOptions(10, -1, -1, 6);
	rooms[8]->ModifyDoors(9, -1, -1, 7);
	rooms[8]->ModifyItems(-1, -1);

	rooms[9]->ModifyOptions(-1, 6, -1, -1);
	rooms[9]->ModifyDoors(-1, 8, -1, -1);
	rooms[9]->ModifyItems(5, -1);

	rooms[10]->ModifyOptions(-1, 8, 11, -1);
	rooms[10]->ModifyDoors(-1, 9, 10, -1);
	rooms[10]->ModifyItems(-1, -1);

	rooms[11]->ModifyOptions(-1, -1, -1, 10);
	rooms[11]->ModifyDoors(-1, -1, -1, 10);
	rooms[11]->ModifyItems(6, -1);

	exits[5]->ModifyState();
	exits[8]->ModifyState();

}

void World::CheckRoom(int room)const
{
	cout << rooms[room]->GetName() << endl;
	if (rooms[room]->FirstVisit()) cout << rooms[room]->GetDescription() << endl, rooms[room]->NoDescription();

	int check = 0;

	for (int i = 0; i < 7; i++)
	{
		if (rooms[room]->GetItem(i)) check++;
	}
	if (check == 0)
	{
		cout << "This room contains no items." << endl << endl;
	}
	else if (check != 0)
	{
		cout << "This room contains ";
		if (check == 1)
		{
			for (int i = 0; i < 7; i++)
			{
				if (rooms[room]->GetItem(i)) cout << "one " << items[i]->GetName() << "." << endl << endl;
			}
		}
		else if (check > 1)
		{
			for (int i = 0; i < 7; i++)
			{
				if (rooms[room]->GetItem(i) && check > 1)
				{
					cout << "one " << items[i]->GetName() << ", ";
					check--;
				}
				else if (rooms[room]->GetItem(i) && check == 1)
				{
					cout << "and one " << items[i]->GetName() << "." << endl << endl;
					check--;
				}
			}
		}
	}
}

int World::CheckPosition()const
{
	return adventurer->CheckPosition();
}

void World::Move(int position)
{
	adventurer->ModifyPosition(position);
}
void World::Execute(const String& str, int dir, int item, int &position)const
{

	//LOOK ITEMS / EXITS

	if (str == "look!")
	{
		if (item != -1)
		{
			if (adventurer->GetItem(item))
			{
				cout << items[item]->GetDescription() << " It's in your inventory." << endl << endl;
			}
			else if (rooms[position]->GetItem(item))
			{
				cout << items[item]->GetDescription() << " It's on the floor." << endl << endl;
			}
			else
			{
				cout << "There's no such item around." << endl << endl;
			}
		}
		else if (dir != -1)
		{
			if (rooms[position]->CheckDoors(dir) != -1)
			{
				cout << exits[rooms[position]->CheckDoors(dir)]->GetDescription() << endl << endl;
			}
			else if (rooms[position]->CheckDoors(dir) == -1)
				cout << "There's no door in that direction." << endl << endl;
		}
	}

	//GO

	else if (str == "go!")
	{
		if (rooms[position]->CheckOptions(dir) != -1 && exits[rooms[position]->CheckDoors(dir)]->IsOpen())
		{
			position = rooms[position]->CheckOptions(dir);
			CheckRoom(position);
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

	//OPEN

	else if (str == "open!")
	{
		if (rooms[position]->CheckDoors(dir) != -1 && exits[rooms[position]->CheckDoors(dir)]->IsOpen() == false)
		{
			exits[rooms[position]->CheckDoors(dir)]->ModifyState();
			cout << "The door is now open." << endl << endl;
		}
		else if (rooms[position]->CheckDoors(dir) == -1)
		{
			cout << "There's no door in that direction." << endl << endl;
		}
		else
		{
			cout << "The door is already open." << endl << endl;
		}
	}

	//CLOSE

	else if (str == "close!")
	{
		if (rooms[position]->CheckDoors(dir) != -1 && exits[rooms[position]->CheckDoors(dir)]->IsOpen())
		{
			exits[rooms[position]->CheckDoors(dir)]->ModifyState();
			cout << "The door is now closed" << endl << endl;
		}
	}

	//LOOK ROOMS

	else if (str == "lookroom")
	{
		cout << rooms[position]->GetDescription() << endl;
		int check = 0;

		for (int i = 0; i < 7; i++)
		{
			if (rooms[position]->GetItem(i)) check++;
		}
		if (check == 0)
		{
			cout << "This room contains no items." << endl << endl;
		}
		else if (check != 0)
		{
			cout << "This room contains ";
			if (check == 1)
			{
				for (int i = 0; i < 7; i++)
				{
					if (rooms[position]->GetItem(i)) cout << "one " << items[i]->GetName() << "." << endl << endl;
				}
			}
			else if (check > 1)
			{
				for (int i = 0; i < 7; i++)
				{
					if (rooms[position]->GetItem(i) && check > 1)
					{
						cout << "one " << items[i]->GetName() << ", ";
						check--;
					}
					else if (rooms[position]->GetItem(i) && check == 1)
					{
						cout << "and one " << items[i]->GetName() << "." << endl << endl;
						check--;
					}
				}
			}
		}
	}

	//LOOK PLAYER

	else if (str == "lookplayer")
	{
		cout << adventurer->GetDescription() << endl << endl;
	}

	//LOOK INVENTORY

	else if (str == "lookinventory")
	{
		int check = 0;

		for (int i = 0; i < 7; i++)
		{
			if (adventurer->GetItem(i)) check++;
		}
		if (check == 0)
		{
			cout << "Your inventory is empty." << endl << endl;
		}
		else if (check != 0)
		{
			cout << "Your inventory contains ";
			if (check == 1)
			{
				for (int i = 0; i < 7; i++)
				{
					if (adventurer->GetItem(i)) cout << "one " << items[i]->GetName() << "." << endl << endl;
				}
			}
			else if (check > 1)
			{
				for (int i = 0; i < 7; i++)
				{
					if (adventurer->GetItem(i) && check > 1)
					{
						cout << "one " << items[i]->GetName() << ", ";
						check--;
					}
					else if (adventurer->GetItem(i) && check == 1)
					{
						cout << "and one " << items[i]->GetName() << "." << endl << endl;
						check--;
					}
				}
			}
		}
	}

	//LOOK BOX

	else if (str == "lookbox!")
	{
		if (position == 2)
		{
			cout << box->GetDescription();
			int check = 0;

			for (int i = 0; i < 7; i++)
			{
				if (box->GetItem(i)) check++;
			}
			if (check == 0)
			{
				cout << " It is empty." << endl << endl;
			}
			else if (check != 0)
			{
				cout << " It contains ";
				if (check == 1)
				{
					for (int i = 0; i < 7; i++)
					{
						if (box->GetItem(i)) cout << "one " << items[i]->GetName() << "." << endl << endl;
					}
				}
				else if (check > 1)
				{
					for (int i = 0; i < 7; i++)
					{
						if (box->GetItem(i) && check > 1)
						{
							cout << "one " << items[i]->GetName() << ", ";
							check--;
						}
						else if (box->GetItem(i) && check == 1)
						{
							cout << "and one " << items[i]->GetName() << "." << endl << endl;
							check--;
						}
					}
				}
			}
		}
		else
		{
			cout << "There's no such thing in this room!" << endl << endl;
		}
	}

	//PICK

	else if (str == "pick!")
	{
		if (adventurer->GetCap() < 4)
		{
			if (rooms[position]->GetItem(item))
			{
				adventurer->PickDrop(item);
				rooms[position]->PickDrop(item);
				cout << "You picked a " << items[item]->GetName() << endl << endl;
			}
			else cout << "There's no such item in this room!" << endl << endl;
		}
		else if (rooms[position]->GetItem(item) == false)
		{
			cout << "There's no such item in this room!" << endl << endl;
		}
		else cout << "Your inventory is full! Try dropping of storing something to free some space." << endl << endl;

	}

	//DROP

	else if (str == "drop!")
	{
		if (adventurer->GetItem(item))
		{
			adventurer->PickDrop(item);
			rooms[position]->PickDrop(item);
			cout << "You dropped the " << items[item]->GetName() << endl << endl;
		}
		else cout << "There's no such item in your inventory!" << endl << endl;
	}

	//PUT ITEM INTO BOX

	else if (str == "putinto")
	{
		if (position == 2)
		{
			if (adventurer->GetItem(item))
			{
				box->PickDrop(item);
				adventurer->PickDrop(item);
				cout << "You put the " << items[item]->GetName() << " into the box." << endl << endl;
			}
			else
			{
				cout << "There's not such item in your inventory!" << endl << endl;
			}
		}
		else
		{
			cout << "There's no box in here!" << endl << endl;
		}
	}

	//GET ITEM FROM BOX

	else if (str == "getfrom")
	{
		if (position == 2)
		{
			if (box->GetItem(item))
			{
				if (adventurer->GetCap() < 4)
				{
					adventurer->PickDrop(item);
					box->PickDrop(item);
					cout << "You got the " << items[item]->GetName() << " from the box." << endl << endl;
				}
				else
				{
					cout << "Your inventory is full! Try dropping of storing something to free some space." << endl << endl;
				}
			}
			else
			{
				cout << "There's no such item in the box!" << endl << endl;
			}
		}
		else
		{
			cout << "There's no box in here!" << endl << endl;
		}
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