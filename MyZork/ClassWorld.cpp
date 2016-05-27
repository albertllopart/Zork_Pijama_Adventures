#include "ClassWorld.h"

World::World(const char* str)
{
	entities.PushBack(new Room("Hall", "It's an old fashioned hall, with loads of old panitings hanging on walls and a couple of rusty armors in the center. It's barely illuminated."));
	entities.PushBack(new Room("West of hall", "Something smells rotten in this room. It's a lot darker than the hall. There's a misterious masked man in the center staring at you."));
	entities.PushBack(new Room("North of Hall", "It's a small room with one door at each wall. There's a huge box in the center."));
	entities.PushBack(new Room("SnS Room", "It's a small room with a strange switch on a wall. There's also a man laying on a blood paddle."));
	entities.PushBack(new Room("Bathroom", "So this is actually a bathroom. Someone must've erased the 'h' on the entrance sign. Such a filthy prankster."));
	entities.PushBack(new Room("Copper Room", "Every wall in this room is painted in copper, including both doors."));
	entities.PushBack(new Room("Silver Room", "Every wall in this room is painted in silver but this time it's only the northern door the one painted the same way."));
	entities.PushBack(new Room("Toucan Room", "There's a toucan holding something in his beak. He's laughing at your pijama."));
	entities.PushBack(new Room("Crack Room", "It's completely empty. There's a suspicious crack on the northern wall."));
	entities.PushBack(new Room("Grenade Room", "This room would be completely empty if there wasn't a chest right in the center of it."));
	entities.PushBack(new Room("Dragon Room", "It smells like if something had been burning for days in here. You notice a huge dragon staring at you. His face doesn't look like the face of mercy."));
	entities.PushBack(new Room("Orb Room", "There's a long passage that leads to something that looks like an altar. Something shines on it."));
	
	entities.PushBack(new Exit("A wooden door that leads to a western room."));
	entities.PushBack(new Exit("A huge door that leads to a northern room."));
	entities.PushBack(new Exit("You feel like there's gonna be something useful inside."));
	entities.PushBack(new Exit("There's a sing on the wall. It says 'Bat room'."));
	entities.PushBack(new Exit("This door leads deeper into this strange place. It has a strange locking mechanism."));
	entities.PushBack(new Exit("This door is made out of copper."));
	entities.PushBack(new Exit("You smell bird shit on the other side."));
	entities.PushBack(new Exit("A wooden door that leads to an eastern room."));
	entities.PushBack(new Exit("This door is made out of silver."));
	entities.PushBack(new Exit("There's a crack on the wall."));
	entities.PushBack(new Exit("It's a door made out of gold."));

	entities.PushBack(new Entity("Sword", "It's a sharp sword!"));
	entities.PushBack(new Entity("Wooden Shield", "It's a shield strong enough to resist some hits, but do not try to parry fire attacks with it!"));
	entities.PushBack(new Entity("Sack of grain", "It's a small sack full of grain."));
	entities.PushBack(new Entity("Copper Key", "It's a key made out of copper."));
	entities.PushBack(new Entity("Silver Key", "It's a key made out of silver."));
	entities.PushBack(new Entity("Grenade", "It's just a grenade. Were you really expecting a detailed description?"));
	entities.PushBack(new Entity("Orb", "It's a blue translucid orb with a shinny core."));

	adventurer = new Player(str, "You're wearing a warm pijaman and slippers.");
	box = new Entity("Box", "It's a wooden box. You can store items in it.");

	playing = true;
}

void World::CreateWorld()
{
	
	((Room*)entities[0])->ModifyOptions(2, -1, -1, 1);
	((Room*)entities[0])->ModifyDoors(13, -1, -1, 12);

	((Room*)entities[1])->ModifyOptions(-1, -1, 0, -1);
	((Room*)entities[1])->ModifyDoors(-1, -1, 12, -1);

	((Room*)entities[2])->ModifyOptions(5, 0, 4, 3);
	((Room*)entities[2])->ModifyDoors(16, 13, 15, 14);

	((Room*)entities[3])->ModifyOptions(-1, -1, 2, -1);
	((Room*)entities[3])->ModifyDoors(-1, -1, 14, -1);
	((Room*)entities[3])->items.PushBack(entities[23]);
	((Room*)entities[3])->items.PushBack(entities[24]);

	((Room*)entities[4])->ModifyOptions(-1, -1, -1, 2);
	((Room*)entities[4])->ModifyDoors(-1, -1, -1, 15);
	((Room*)entities[4])->items.PushBack(entities[26]);

	((Room*)entities[5])->ModifyOptions(6, 2, -1, -1);
	((Room*)entities[5])->ModifyDoors(17, 16, -1, -1);
	((Room*)entities[5])->items.PushBack(entities[25]);

	((Room*)entities[6])->ModifyOptions(9, 5, 8, 7);
	((Room*)entities[6])->ModifyDoors(20, 17, 19, 18);

	((Room*)entities[7])->ModifyOptions(-1, -1, 6, -1);
	((Room*)entities[7])->ModifyDoors(-1, -1, 18, -1);
	((Room*)entities[7])->items.PushBack(entities[27]);

	((Room*)entities[8])->ModifyOptions(10, -1, -1, 6);
	((Room*)entities[8])->ModifyDoors(21, -1, -1, 19);

	((Room*)entities[9])->ModifyOptions(-1, 6, -1, -1);
	((Room*)entities[9])->ModifyDoors(-1, 20, -1, -1);
	((Room*)entities[9])->items.PushBack(entities[28]);

	((Room*)entities[10])->ModifyOptions(-1, 8, 11, -1);
	((Room*)entities[10])->ModifyDoors(-1, 21, 22, -1);

	((Room*)entities[11])->ModifyOptions(-1, -1, -1, 10);
	((Room*)entities[11])->ModifyDoors(-1, -1, -1, 22);
	((Room*)entities[11])->items.PushBack(entities[29]);

	((Exit*)entities[17])->ModifyState();
	((Exit*)entities[20])->ModifyState();

}

void World::CheckRoom(int room)const
{
	cout << ((Room*)entities[room])->GetName() << endl;
	if (((Room*)entities[room])->FirstVisit()) cout << ((Room*)entities[room])->GetDescription() << endl, ((Room*)entities[room])->NoDescription();

	if (((Room*)entities[room])->items.first != nullptr)
	{
		if (((Room*)entities[room])->items.first->next == nullptr)
		{
			cout << "This room contains one " << ((Room*)entities[room])->items.first->data->GetName() << endl << endl;
		}
		else
		{
			dList<Entity*>::dNode* temp = ((Room*)entities[room])->items.first;
			cout << "This room contains one " << ((Room*)entities[room])->items.first->data->GetName() << ", ";
			while (temp->next != nullptr)
			{
				if (temp->next->next != nullptr)
				{
					temp = temp->next;
					cout << "one " << temp->data->GetName() << ", ";
				}
				else
				{
					temp = temp->next;
					cout << "and one " << temp->data->GetName() << endl << endl;
				}
			}
		}
	}
	else
	{
		cout << "This room contains no items" << endl << endl;
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
void World::Execute(const String& str, int dir, const String& item, int pickdrop, int &position)const
{

	//LOOK ITEMS / EXITS

	if (str == "look!")
	{
		if (dir == -1)
		{
			if (adventurer->GetItem(item))
			{
				for (int i = 23; i < 30; i++)
				{
					if (item == entities[i]->GetName())
					{
						cout << entities[i]->GetDescription() << " It's in your inventory." << endl << endl;
					}
				}
			}
			else if (((Room*)entities[position])->GetItem(item))
			{
				for (int i = 23; i < 30; i++)
				{
					if (item == entities[i]->GetName())
					{
						cout << entities[i]->GetDescription() << " It's on the floor." << endl << endl;
					}
				}
			}
			else
			{
				cout << "There's no such item around." << endl << endl;
			}
		}
		else if (dir != -1)
		{
			if (((Room*)entities[position])->CheckDoors(dir) != -1)
			{
				cout << ((Exit*)entities[((Room*)entities[position])->CheckDoors(dir)])->GetDescription() << endl << endl;
			}
			else if (((Room*)entities[position])->CheckDoors(dir) == -1)
				cout << "There's no door in that direction." << endl << endl;
		}
	}

	//GO

	else if (str == "go!")
	{
		if (((Room*)entities[position])->CheckOptions(dir) != -1 && ((Exit*)entities[((Room*)entities[position])->CheckDoors(dir)])->IsOpen())
		{
			position = ((Room*)entities[position])->CheckOptions(dir);
			CheckRoom(position);
		}
		else if (((Room*)entities[position])->CheckOptions(dir) == -1)
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
		if (((Room*)entities[position])->CheckDoors(dir) != -1 && ((Exit*)entities[((Room*)entities[position])->CheckDoors(dir)])->IsOpen() == false)
		{
			((Exit*)entities[((Room*)entities[position])->CheckDoors(dir)])->ModifyState();
			cout << "The door is now open." << endl << endl;
		}
		else if (((Room*)entities[position])->CheckDoors(dir) == -1)
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
		if (((Room*)entities[position])->CheckDoors(dir) != -1 && ((Exit*)entities[((Room*)entities[position])->CheckDoors(dir)])->IsOpen())
		{
			((Exit*)entities[((Room*)entities[position])->CheckDoors(dir)])->ModifyState();
			cout << "The door is now closed" << endl << endl;
		}
	}

	//LOOK ROOMS

	else if (str == "lookroom")
	{
		cout << ((Room*)entities[position])->GetDescription() << endl;
		int check = 0;

		if (((Room*)entities[position])->items.first != nullptr)
		{
			if (((Room*)entities[position])->items.first->next == nullptr)
			{
				cout << "This room contains one " << ((Room*)entities[position])->items.first->data->GetName() << endl << endl;
			}
			else
			{
				dList<Entity*>::dNode* temp = ((Room*)entities[position])->items.first;
				cout << "This room contains one " << ((Room*)entities[position])->items.first->data->GetName() << ", ";
				while (temp->next != nullptr)
				{
					if (temp->next->next != nullptr)
					{
						temp = temp->next;
						cout << "one " << temp->data->GetName() << ", ";
					}
					else
					{
						temp = temp->next;
						cout << "and one " << temp->data->GetName() << endl << endl;
					}
				}
			}
		}
		else
		{
			cout << "This room contains no items" << endl << endl;
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
		if (adventurer->items.first != nullptr)
		{
			if (adventurer->items.first->next == nullptr)
			{
				cout << "Your inventory contains one " << adventurer->items.first->data->GetName() << endl << endl;
			}
			else
			{
				dList<Entity*>::dNode* temp = adventurer->items.first;
				cout << "Your inventory contains one " << adventurer->items.first->data->GetName() << ", ";
				while (temp->next != nullptr)
				{
					if (temp->next->next != nullptr)
					{
						temp = temp->next;
						cout << "one " << temp->data->GetName() << ", ";
					}
					else
					{
						temp = temp->next;
						cout << "and one " << temp->data->GetName() << endl << endl;
					}
				}
			}
		}
		else
		{
			cout << "Your inventory contains no items" << endl << endl;
		}
	}

	//LOOK BOX

	else if (str == "lookbox!")
	{
		if (position == 2)
		{
			cout << box->GetDescription();
			if (box->items.first != nullptr)
			{
				if (box->items.first->next == nullptr)
				{
					cout << "It contains one " << box->items.first->data->GetName() << endl << endl;
				}
				else
				{
					dList<Entity*>::dNode* temp = box->items.first;
					cout << "It contains one " << box->items.first->data->GetName() << ", ";
					while (temp->next != nullptr)
					{
						if (temp->next->next != nullptr)
						{
							temp = temp->next;
							cout << "one " << temp->data->GetName() << ", ";
						}
						else
						{
							temp = temp->next;
							cout << "and one " << temp->data->GetName() << endl << endl;
						}
					}
				}
			}
			else
			{
				cout << " It is empty." << endl << endl;
			}
		}
		else
		{
			cout << "There's no such thing in this room!" << endl << endl;
		}
	}

	//LOOK EQUIPMENT

	else if (str == "equipment!")
	{
		if (adventurer->equipment.first != nullptr)
		{
			if (adventurer->equipment.first->next == nullptr)
			{
				cout << "You have a " << adventurer->equipment.first->data->GetName() << " equipped." << endl << endl;
			}
			else
			{
				cout << "Your have a " << adventurer->equipment.first->data->GetName() << " and a " << adventurer->equipment.first->next->data->GetName() << " equipped." << endl << endl;
			}
		}
		else
		{
			cout << "You don't have anything equipped." << endl << endl;
		}
	}

	//PICK

	else if (str == "pick!")
	{
		if (((Room*)entities[position])->GetItem(item) == false)
		{
			cout << "There's no such item in this room!" << endl << endl;
		}
		else
		{
			if (adventurer->GetCap() > 2)
			{
				cout << "Your inventory is full! Consider dropping, storing or equipping something to free some space." << endl << endl;
			}
			else
			{
				dList<Entity*>::dNode* temp = ((Room*)entities[position])->items.first;
				if (temp != nullptr)
				{
					while (temp != nullptr)
					{
						if (item == temp->data->GetName())
						{
							if (temp != nullptr)
							{
								adventurer->items.PushBack(temp->data);
								adventurer->itemCap++;
								((Room*)entities[position])->items.erase(temp);
								break;
							}
						}
						temp = temp->next;
					}
				}
				cout << "You picked a " << entities[pickdrop]->GetName() << endl << endl;
			}
		}
	}

	//DROP

	else if (str == "drop!")
	{
		if (adventurer->GetItem(item) == false)
		{
			cout << "There's no such item in your inventory!" << endl << endl;
		}
		else
		{
			((Room*)entities[position])->items.PushBack(entities[pickdrop]);
			adventurer->itemCap--;
			dList<Entity*>::dNode* temp = adventurer->items.first;
			for (; temp != nullptr; temp = temp->next)
			{
				if (item == temp->data->GetName())
				{
					adventurer->items.erase(temp);
					break;
				}
			}
			cout << "You dropped the " << entities[pickdrop]->GetName() << endl << endl;
		}
	}

	//PUT ITEM INTO BOX

	/*else if (str == "putinto")
	{
		if (position == 2)
		{
			if (adventurer->GetItem(item) && box->GetCap() < 3)
			{
				box->PickDrop(item);
				adventurer->PickDrop(item);
				cout << "You put the " << entities[item + 23]->GetName() << " into the box." << endl << endl;
			}
			else if (adventurer->GetItem(item) && box->GetCap() > 2)
			{
				cout << "The box is full!" << endl << endl;
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
				if (adventurer->GetCap() < 3)
				{
					adventurer->PickDrop(item);
					box->PickDrop(item);
					cout << "You got the " << entities[item + 23]->GetName() << " from the box." << endl << endl;
				}
				else
				{
					cout << "Your inventory is full! Consider dropping, storing or equipping something to free some space." << endl << endl;
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

	//EQUIP ITEM

	else if (str == "equip!")
	{
		if (adventurer->GetItem(item))
		{
			if (item == 0 || item == 1)
			{
				cout << "You equipped the " << entities[item + 23]->GetName() << endl << endl;
				adventurer->EquipUnequip(item);
				adventurer->PickDrop(item);
			}
			else
			{
				cout << "You can't equip that!" << endl << endl;
			}
		}
		else
		{
			cout << "There's no such item in your inventory!" << endl << endl;
		}
	}

	//UNEQUIP ITEM

	else if (str == "unequip!")
	{
		if (adventurer->GetEquip(item))
		{
			cout << "You unequipped the " << entities[item + 23]->GetName() << endl << endl;
			adventurer->EquipUnequip(item);
			adventurer->PickDrop(item);
		}
		else
		{
			cout << "You don't have that item equipped!" << endl << endl;
		}
	}*/

	//STATS

	else if (str == "stats!")
	{
		cout << "HP:       " << adventurer->GetStat(0) << endl;
		cout << "Attack:   " << adventurer->GetStat(1) << endl;
		cout << "Defense:  " << adventurer->GetStat(2) << endl << endl;
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
	delete box;
	delete adventurer;
}