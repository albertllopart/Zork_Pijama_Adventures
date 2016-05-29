#include "ClassWorld.h"

World::World(const char* str)
{
	entities.PushBack(new Room(">>> HALL", "It's an old fashioned hall, with loads of old panitings hanging on walls and a couple of rusty armors in the center. It's barely illuminated."));
	entities.PushBack(new Room(">>> WEST OF HALL", "Something smells rotten in this room. It's a lot darker than the hall."));
	entities.PushBack(new Room(">>> NORTH OF HALL", "It's a small room with one door at each wall. There's a huge box in the center."));
	entities.PushBack(new Room(">>> LIVING ROOM", "It's a small room with a strange switch on a wall. There's also a man laying on a blood puddle."));
	entities.PushBack(new Room(">>> BATHROOM", "So this is actually a bathroom. Someone must've erased the 'h' on the entrance sign. Such a filthy prankster."));
	entities.PushBack(new Room(">>> COOPER ROOM", "Every wall in this room is painted in copper, including both doors."));
	entities.PushBack(new Room(">>> SILVER ROOM", "Every wall in this room is painted in silver but this time it's only the northern door the one painted the same way."));
	entities.PushBack(new Room(">>> BIRD ROOM", "This room has a high ceiling with a window at the top, but it's impossible to reach."));
	entities.PushBack(new Room(">>> SUSPICIOUSLY EMPTY ROOM", "It's completely empty. There's a suspicious crack on the northern wall."));
	entities.PushBack(new Room(">>> CHEST ROOM", "This room would be completely empty if there wasn't a chest right in the center of it."));
	entities.PushBack(new Room(">>> DRAGON ROOM", "It smells like if something had been burning for days in here. You notice a huge dragon staring at you. His face doesn't look like the face of mercy."));
	entities.PushBack(new Room(">>> ALTAR ROOM", "There's a long passage that leads to something that looks like an altar. Something shines on it."));
	
	entities.PushBack(new Exit("A wooden door."));
	entities.PushBack(new Exit("A huge door."));
	entities.PushBack(new Exit("You feel like there's gonna be something useful inside."));
	entities.PushBack(new Exit("There's a sing on the wall. It says 'Bat room'."));
	entities.PushBack(new Exit("This door leads deeper into this strange place. It has a strange locking mechanism."));
	entities.PushBack(new Exit("This door is made out of copper."));
	entities.PushBack(new Exit("You smell bird shit on the other side."));
	entities.PushBack(new Exit("A wooden door that leads to an eastern room."));
	entities.PushBack(new Exit("This door is made out of silver."));
	entities.PushBack(new Exit("There's a crack on the wall."));
	entities.PushBack(new Exit("It's a door made out of gold."));

	entities.PushBack(new Entity("Sword", "It's a sharp sword."));
	entities.PushBack(new Entity("Wooden Shield", "It's a shield strong enough to resist some hits, but do not try to parry fire attacks with it!"));
	entities.PushBack(new Entity("Sack of grain", "It's a small sack full of grain."));
	entities.PushBack(new Entity("Copper Key", "It's a key made out of copper."));
	entities.PushBack(new Entity("Silver Key", "It's a key made out of silver."));
	entities.PushBack(new Entity("Grenade", "It's just a grenade. Were you really expecting a detailed description?"));
	entities.PushBack(new Entity("Orb", "It's a blue translucid orb with a shinny core."));

	adventurer = new Player(str, "You're wearing a warm pijaman and slippers.", 0);
	box = new Entity("Box", "It's a wooden box. You can store items in it.");
	chest = new Entity("Chest", "It's a wooden chest. Luckily it isn't locked.");
	misterious = new NPC("Misterious", "It's a misterious masked man. He's staring at you.", 1, 
		". Don't worry, I will not do any harm to you. I guess you might be wondering how the hell you ended up here. Let's make a deal: I'll tell you everything you want to know if you bring me something I want so badly. It's a treasure that's been held in here for so long. You'll know what it is as soon as you find it. Will you help me?", 
		"Okay, do what you want, but you ain't getting outta here without my help. Cya.", 
		"Have you changed your mind? Will you help me?",
		"Great! Listen carefully: ", 
		"Prove your value first. Bring me a sword and I'll give you something you'll be needing sooner or later. Don't worry, you'll get to keep the sword. I opened the northern door of the Hall for you. Let's bounce!",
		"Nice sword you found there. I'm afraid it belonged to the last dude I sent on a quest. But don't worry, take this shield and you'll be fine. You've proven your value. Good luck on your quest!",
		"Are you really expecting me to say something else? This can only mean you still don't know about the lazyness of my programmer. Get outta here, you're on a quest!");
	warrior = new NPC("Warrior", "It's a dead body laying on a blood puddle.", 3, " ", " ", " ", " ", " ", " ", " ");
	toucan = new NPC("Toucan", "An annoying toucan.", 7, " ", " ", " ", " ", " ", " ", " ");
	skeleton = new NPC("Cool Skeleton", "It's a skeleton who's wearing a cape. He's so cool.", 11, " ", " ", " ", " ", " ", " ", " ");
	dragon = new Enemy("Dragon", "It's a huge dragon chained to the wall. There's a golden door behind it.", 10);

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
			cout << "This room contains one " << ((Room*)entities[room])->items.first->data->GetName();
			if (adventurer->CheckPosition() != misterious->CheckPosition())
			{
				cout << endl << endl;
			}
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
					cout << "and one " << temp->data->GetName();
					if (adventurer->CheckPosition() != misterious->CheckPosition())
					{
						cout << endl << endl;
					}
				}
			}
		}
	}
	else
	{
		cout << "This room contains no items.";
 		if (adventurer->CheckPosition() != misterious->CheckPosition())
		{
			cout << endl << endl;
		}
	}
	if (adventurer->CheckPosition() == misterious->CheckPosition())
	{
		cout << " There's a misterious masked man staring at you." << endl << endl;
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
void World::Execute(const String& str, int dir, const String& item, int pickdrop, int& position)const
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

	//CONVERSATION WITH MASKED MAN

	else if (str == "talkman!")
	{
		if (adventurer->CheckPosition() == misterious->CheckPosition() && misterious->state != 3)
		{
			char buffer[25] = "lel";
			String answer(buffer);
			misterious->talking = true;

			if (adventurer->GetItem("Sword") && misterious->state < 4)
			{
				misterious->state = 3;
			}

			while (misterious->talking)
			{
				switch (misterious->state)
				{
				case 0: //INTRODUCTION
					cout << "Hi, " << adventurer->GetName() << misterious->GetDialog(1) << endl << endl;
					while (1)
					{
						gets_s(buffer);
						answer = buffer;
						if (answer == "yes" || answer == "y" || answer == "sure" || answer == "yeah")
						{
							cout << misterious->GetDialog(4);
							misterious->state = 2;
							break;
						}
						else if (answer == "no" || answer == "n" || answer == "nope" || answer == "nah")
						{
							cout << misterious->GetDialog(2) << endl << endl;
							misterious->state = 1;
							misterious->talking = false;
							break;
						}
						else if (answer == "shortcut")
						{
							cout << "Skipping dialog" << endl << endl;
							misterious->state = 3;
							break;
						}
						else
						{
							cout << "Sorry, what did you say again?" << endl << endl;
						}
					}
					break;

				case 1: //QUESTION LOOP
					cout << misterious->GetDialog(3) << endl << endl;
					while (1)
					{
						gets_s(buffer);
						answer = buffer;
						if (answer == "yes" || answer == "y" || answer == "sure" || answer == "yeah")
						{
							cout << misterious->GetDialog(4);
							misterious->state = 2;
							break;
						}
						else if (answer == "no" || answer == "n" || answer == "nope" || answer == "nah")
						{
							cout << misterious->GetDialog(2) << endl << endl;
							misterious->state = 1;
							misterious->talking = false;
							break;
						}
						else if (answer == "shortcut")
						{
							cout << "Skipping dialog" << endl << endl;
							misterious->state = 3;
							break;
						}
						else
						{
							cout << "Sorry, what did you say again?" << endl << endl;
						}
					}
					break;

				case 2: //THE QUEST BEGINS!
					cout << misterious->GetDialog(5) << endl << endl;
					misterious->talking = false;
					break;

				case 3: //THE QUEST CONTINUES!
					cout << misterious->GetDialog(6) << endl << endl;
					misterious->talking = false;
					misterious->state = 4;
					break;

				case 4: //LAZY PROGRAMMER
					cout << misterious->GetDialog(7) << endl << endl;
					misterious->talking = false;
					misterious->state = 5;
					break;

				case 5: //JOKE
					cout << "Yes, my programmer writes 'lazyness' cause it's an even lazier way of writting 'laziness'. Now go!" << endl << endl;
					misterious->talking = false;
					misterious->state = 6;
					break;

				case 6: //JOKE
					cout << "Did you hear about the guy whose whole left side was cut off? He's all right now." << endl << endl;
					misterious->talking = false;
					misterious->state = 7;
					break;

				case 7: //JOKE
					cout << "I originally wasn't going to get a brain transplant, but then I changed my mind." << endl << endl;
					misterious->talking = false;
					misterious->state = 8;
					break;

				case 8: //...LOOP
					cout << "..." << endl << endl;
					misterious->talking = false;
					break;
				}
			}
		}
		else
		{
			cout << "He's not around." << endl << endl;
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
				cout << "This room contains one " << ((Room*)entities[position])->items.first->data->GetName();
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
						cout << "and one " << temp->data->GetName();
					}
				}
			}
		}
		else
		{
			cout << "This room contains no items";
		}
		if (adventurer->CheckPosition() == misterious->CheckPosition())
		{
			cout << " There's a misterious masked man staring at you.";
		}
		cout << endl << endl;
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

	//LOOK CHEST

	else if (str == "lookchest!")
	{
		if (adventurer->CheckPosition() == 9)
		{
			cout << chest->GetDescription() << endl << endl;
		}
		else
		{
			cout << "There's no chest in here." << endl << endl;
		}
	}

	//LOOK NPC'S

	else if (str == "lookmisterious!")
	{
		if (adventurer->CheckPosition() == misterious->CheckPosition())
		{
			cout << misterious->GetDescription() << endl << endl;
		}
		else
		{
			cout << "He's not around." << endl << endl;
		}
	}
	else if (str == "lookman!")
	{
		if (adventurer->CheckPosition() == misterious->CheckPosition())
		{
			cout << misterious->GetDescription() << endl << endl;
		}
		else if (adventurer->CheckPosition() == warrior->CheckPosition())
		{
			cout << warrior->GetDescription() << endl << endl;
		}
		else
		{
			cout << "There's no one around." << endl << endl;
		}
	}
	else if (str == "lookwarrior!")
	{
		if (adventurer->CheckPosition() == warrior->CheckPosition())
		{
			cout << warrior->GetDescription() << endl << endl;
		}
		else
		{
			cout << "There's no such thing in here." << endl << endl;
		}
	}
	else if (str == "looktoucan!")
	{
		if (adventurer->CheckPosition() == toucan->CheckPosition())
		{
			cout << toucan->GetDescription() << endl << endl;
		}
		else
		{
			cout << "There's no bird here." << endl << endl;
		}
	}
	else if (str == "lookskeleton!")
	{
		if (adventurer->CheckPosition() == skeleton->CheckPosition())
		{
			cout << skeleton->GetDescription() << endl << endl;
		}
		else
		{
			cout << "There's no skeleton here." << endl << endl;
		}
	}

	//LOOK ENEMIES

	else if (str == "lookdragon!")
	{
		if (adventurer->CheckPosition() == dragon->CheckPosition())
		{
			cout << dragon->GetDescription() << endl << endl;
		}
		else
		{
			cout << "There's no dragon in here. Wow, am I really this predictable?" << endl << endl;
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

	else if (str == "putinto")
	{
		if (position == 2)
		{
			if (adventurer->GetItem(item) && box->GetCap() < 3)
			{
				box->items.PushBack(entities[pickdrop]);
				adventurer->itemCap--;
				box->itemCap++;
				dList<Entity*>::dNode* temp = adventurer->items.first;
				for (; temp != nullptr; temp = temp->next)
				{
					if (item == temp->data->GetName())
					{
						adventurer->items.erase(temp);
						break;
					}
				}
				cout << "You put the " << entities[pickdrop]->GetName() << " into the box." << endl << endl;
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
					dList<Entity*>::dNode* temp = box->items.first;
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
									box->itemCap--;
									box->items.erase(temp);
									break;
								}
							}
							temp = temp->next;
						}
					}
					cout << "You got the " << entities[pickdrop]->GetName() << " from the box." << endl << endl;
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
			if (pickdrop == 23 || pickdrop == 24)
			{
				cout << "You equipped the " << entities[pickdrop]->GetName() << endl << endl;
				adventurer->equipment.PushBack(entities[pickdrop]);
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
				adventurer->EquipUnequip(item);
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
			cout << "You unequipped the " << entities[pickdrop]->GetName() << endl << endl;
			adventurer->items.PushBack(entities[pickdrop]);
			adventurer->itemCap++;
			dList<Entity*>::dNode* temp = adventurer->equipment.first;
			for (; temp != nullptr; temp = temp->next)
			{
				if (item == temp->data->GetName())
				{
					adventurer->equipment.erase(temp);
					break;
				}
			}
			adventurer->EquipUnequip(item);
		}
		else
		{
			cout << "You don't have that item equipped!" << endl << endl;
		}
	}

	//STATS

	else if (str == "stats!")
	{
		cout << "HP:       " << adventurer->GetStat(0) << endl;
		cout << "Attack:   " << adventurer->GetStat(1) << endl;
		cout << "Defense:  " << adventurer->GetStat(2) << endl << endl;
	}

	//TELEPORT (ONLY FOR DEVELOPER!!!)

	else if (str == "teleport 1")
	{
		position = 0;
	}
	else if (str == "teleport 2")
	{
		position = 6;
	}
	else if (str == "teleport 3")
	{
		position = 11;
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