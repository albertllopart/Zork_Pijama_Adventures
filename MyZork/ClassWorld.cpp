#include "ClassWorld.h"

World::World(const char* str)
{
	dead = false;
	fighting = false;
	chasing = false;
	ending = false;

	entities.PushBack(new Room(">>> HALL", "It's an old fashioned hall, with loads of old paintings hanging on walls and a couple of rusty armors in the center. It's barely illuminated."));
	entities.PushBack(new Room(">>> WEST OF HALL", "Something smells rotten in this room. It's a lot darker than the hall."));
	entities.PushBack(new Room(">>> NORTH OF HALL", "It's a small room with one door at each wall. There's a huge box in the center."));
	entities.PushBack(new Room(">>> LIVING ROOM", "It's a small room with lots of torches. There's also a man laying on a blood puddle."));
	entities.PushBack(new Room(">>> BATHROOM", "So this is actually a bathroom. Someone must've erased the 'h' on the entrance sign. Such a filthy prankster. There's a suspicious button behind the toilet."));
	entities.PushBack(new Room(">>> COOPER ROOM", "Every wall in this room is painted in copper, including both doors."));
	entities.PushBack(new Room(">>> SILVER ROOM", "Every wall in this room is painted in silver but this time it's only the northern door the one painted the same way."));
	entities.PushBack(new Room(">>> BIRD ROOM", "This room has a high ceiling with a window at the top, but it's impossible to reach."));
	entities.PushBack(new Room(">>> SUSPICIOUSLY EMPTY ROOM", "It's completely empty. There's a suspicious crack on the northern wall."));
	entities.PushBack(new Room(">>> CHEST ROOM", "This room would be completely empty if there wasn't a chest right in the center of it."));
	entities.PushBack(new Room(">>> DRAGON ROOM", "It smells like if something had been burning for days in here."));
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
	entities.PushBack(new Entity("Orb", "It's a translucid blue orb with a shiny core."));
	entities.PushBack(new Entity("Toucan", "An annoying toucan."));

	adventurer = new Player(str, "You're wearing a warm pijaman and slippers.", 0);
	box = new Entity("Box", "It's a wooden box. You can store items in it.");
	chest = new Entity("Chest", "It's a wooden chest. Luckily it isn't locked.");
	misterious = new NPC("Misterious", "It's a misterious masked man. He's staring at you.", 1, 
		". Don't worry, I will not do any harm to you. I guess you might be wondering how the hell you ended up here. Let's make a deal: I'll tell you everything you want to know if you bring me something I want so badly. It's a treasure that's been held in here for so long. You'll know what it is as soon as you find it. Will you help me?", 
		"Okay, do what you want, but you ain't getting outta here without my help. Cya.", 
		"Have you changed your mind? Will you help me?",
		"Great! Listen carefully: ", 
		"Prove your value first. Bring me a sword and I'll give you something you'll be needing sooner or later. Don't worry, you'll get to keep the sword. I opened the northern door of the Hall for you. Be careful not to put yourself in dangerous situations while you aren't armed! Watch your step. Let's bounce!",
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
	((Room*)entities[0])->NPCallow = true;

	((Room*)entities[1])->ModifyOptions(-1, -1, 0, -1);
	((Room*)entities[1])->ModifyDoors(-1, -1, 12, -1);
	((Room*)entities[1])->NPCallow = true;

	((Room*)entities[2])->ModifyOptions(5, 0, 4, 3);
	((Room*)entities[2])->ModifyDoors(16, 13, 15, 14);
	((Room*)entities[2])->NPCallow = true;

	((Room*)entities[3])->ModifyOptions(-1, -1, 2, -1);
	((Room*)entities[3])->ModifyDoors(-1, -1, 14, -1);
	((Room*)entities[3])->items.PushBack(entities[23]);

	((Room*)entities[4])->ModifyOptions(-1, -1, -1, 2);
	((Room*)entities[4])->ModifyDoors(-1, -1, -1, 15);
	((Room*)entities[4])->items.PushBack(entities[26]);
	((Room*)entities[4])->NPCallow = true;

	((Room*)entities[5])->ModifyOptions(6, 2, -1, -1);
	((Room*)entities[5])->ModifyDoors(17, 16, -1, -1);
	((Room*)entities[5])->items.PushBack(entities[25]);

	((Room*)entities[6])->ModifyOptions(9, 5, 8, 7);
	((Room*)entities[6])->ModifyDoors(20, 17, 19, 18);

	((Room*)entities[7])->ModifyOptions(-1, -1, 6, -1);
	((Room*)entities[7])->ModifyDoors(-1, -1, 18, -1);

	((Room*)entities[8])->ModifyOptions(10, -1, -1, 6);
	((Room*)entities[8])->ModifyDoors(21, -1, -1, 19);

	((Room*)entities[9])->ModifyOptions(-1, 6, -1, -1);
	((Room*)entities[9])->ModifyDoors(-1, 20, -1, -1);

	((Room*)entities[10])->ModifyOptions(-1, 8, 11, -1);
	((Room*)entities[10])->ModifyDoors(-1, 21, 22, -1);

	((Room*)entities[11])->ModifyOptions(-1, -1, -1, 10);
	((Room*)entities[11])->ModifyDoors(-1, -1, -1, 22);
	((Room*)entities[11])->items.PushBack(entities[29]);

	((Exit*)entities[13])->ModifyState();
	((Exit*)entities[16])->ModifyState();
	((Exit*)entities[17])->ModifyState();
	((Exit*)entities[20])->ModifyState();
	((Exit*)entities[21])->ModifyState();

	chest->items.PushBack(entities[28]);

}

void World::CheckRoom(int room)
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
	else if (adventurer->position != 11)
	{
		cout << "This room contains no items.";
		if (adventurer->CheckPosition() != misterious->CheckPosition() && adventurer->CheckPosition() != toucan->CheckPosition())
		{
			cout << endl << endl;
		}
	}
	if (adventurer->CheckPosition() == misterious->CheckPosition())
	{
		cout << " There's a misterious masked man staring at you." << endl << endl;
	}
	if (adventurer->CheckPosition() == toucan->CheckPosition())
	{
		cout << " There's a toucan holding something in his beak, but you can't reach it either." << endl << endl;
	}
}

int World::CheckPosition()const
{
	return adventurer->CheckPosition();
}

bool World::Talking()const
{
	return misterious->talking;
}

void World::Move(int position)
{
	adventurer->ModifyPosition(position);
}

void World::NPCMove(int direction)
{
	int oldpos = 12;
	if (adventurer->CheckPosition() == misterious->position)
	{
		oldpos = adventurer->CheckPosition();
	}
	if (((Room*)entities[misterious->CheckPosition()])->CheckOptions(direction) != -1 && ((Exit*)entities[((Room*)entities[misterious->CheckPosition()])->CheckDoors(direction)])->IsOpen())
	{
		if (((Room*)entities[((Room*)entities[misterious->position])->CheckOptions(direction)])->NPCallow)
		{
			misterious->position = ((Room*)entities[misterious->position])->CheckOptions(direction);
			if (misterious->position == adventurer->CheckPosition())
			{
				cout << "A misterious masked man walked into the room." << endl << endl;
			}
			else if (oldpos != 12)
			{
				cout << "A misterious masked man left the room." << endl << endl;
			}
		}
	}
}

void World::DragonFight() // DRAGON FIGHT
{
	cout << "A huge dragon attacks you!" << endl << endl;
	dragon->fighting = true;

	char buffer[25] = "lel";
	String answer(buffer);

	while (dragon->fighting)
	{
		switch (dragon->state)
		{
		case 0: //DRAGON TURN
			cout << "The dragon throws a fireball at you at a conviniently set slow speed. What will you do? (dodge / attack / block / run)" << endl << endl;
			gets_s(buffer);
			answer = buffer;

			if (answer == "dodge")
			{
				cout << "You successfully dodged the fireball." << endl << endl;
				dragon->state = 1;
			}
			else if (answer == "attack")
			{
				cout << "You are too far away from the dragon. The fireball hit you." << endl << endl << "You are DEAD." << endl << endl << "Press any key to quit.";
				dragon->fighting = false;
				dead = true;
			}
			else if (answer == "block")
			{
				if (adventurer->GetEquip("Wooden Shield"))
				{
					cout << "You successfully blocked the fireball, but your shield burnt to ashes." << endl << endl;
					dList<Entity*>::dNode* temp = adventurer->equipment.first;
					String item("Wooden Shield");
					adventurer->itemCap--;
					adventurer->EquipUnequip(item);
					for (; temp != nullptr; temp = temp->next)
					{
						if (item == temp->data->GetName())
						{
							adventurer->equipment.erase(temp);
							break;
						}
					}
					dragon->state = 1;
				}
				else
				{
					cout << "You don't have a shield equipped. The fireball hit you." << endl << endl << "You are DEAD." << endl << endl << "Press any key to quit.";
					dragon->fighting = false;
					dead = true;
				}
			}
			else if (answer == "run")
			{
				cout << "You ran away safely to the room you came from" << endl << endl;
				dragon->fighting = false;
				fighting = false;
				Move(8);
				CheckRoom(8);
				dragon->state = 0;
			}
			else
			{
				cout << "The fireball hit you" << endl << endl << "You are DEAD." << endl << endl << "Press any key to quit.";
				dragon->fighting = false;
				dead = true;
			}
			break;

		case 1: //PLAYER TURN
			cout << "The dragon is preparing its next move. What will you do? (run / attack / move forward)" << endl << endl;
			gets_s(buffer);
			answer = buffer;

			if (answer == "run")
			{
				cout << "You ran away safely to the room you came from" << endl << endl;
				dragon->fighting = false;
				fighting = false;
				Move(8);
				CheckRoom(8);
				dragon->state = 0;
			}
			else if (answer == "attack")
			{
				cout << "You are too far away from the dragon." << endl << endl;
				dragon->state = 0;
			}
			else if (answer == "move forward")
			{
				cout << "You moved closer to the dragon." << endl << endl;
				dragon->state = 2;
			}
			else
			{
				cout << "You did nothing." << endl << endl;
				dragon->state = 0;
			}
			break;

		case 2: //DRAGON TURN (CC)
			cout << "The dragon tries to bite you. What will you do? (block / dodge / attack)" << endl << endl;
			gets_s(buffer);
			answer = buffer;

			if (answer == "block")
			{
				if (adventurer->GetEquip("Wooden Shield"))
				{
					cout << "You successfully blocked the attack, but your shield got crushed." << endl << endl;
					dList<Entity*>::dNode* temp = adventurer->equipment.first;
					String item("Wooden Shield");
					adventurer->itemCap--;
					adventurer->EquipUnequip(item);
					for (; temp != nullptr; temp = temp->next)
					{
						if (item == temp->data->GetName())
						{
							adventurer->equipment.erase(temp);
							break;
						}
					}
					dragon->state = 3;
				}
				else
				{
					cout << "You don't have a shield equipped. The dragon chopped your head." << endl << endl << "You are DEAD." << endl << endl << "Press any key to quit.";
					dragon->fighting = false;
					dead = true;
				}
			}
			else if (answer == "dodge")
			{
				cout << "You failed to dodge the attack. The dragon chopped your head." << endl << endl << "You are DEAD." << endl << endl << "Press any key to quit.";
				dragon->fighting = false;
				dead = true;
			}
			else if (answer == "attack")
			{
				cout << "The dragon was faster. Your head got chopped." << endl << endl << "You are DEAD." << endl << endl << "Press any key to quit.";
				dragon->fighting = false;
				dead = true;
			}
			else
			{
				cout << "The dragon chopped your head." << endl << endl << "You are DEAD." << endl << endl << "Press any key to quit.";
				dragon->fighting = false;
				dead = true;
			}
			break;

		case 3: //PLAYER TURN (CC)
			cout << "The dragon is preparing its next move. What will you do? (move away / attack)" << endl << endl;
			gets_s(buffer);
			answer = buffer;

			if (answer == "move away")
			{
				cout << "You moved away from the dragon." << endl << endl;
				dragon->state = 0;
			}
			else if (answer == "attack")
			{
				if (adventurer->GetEquip("Sword"))
				{
					cout << "You swung your sword over the dragon's neck and successfully chopped its head. The dragon is dead." << endl << endl;
					dragon->fighting = false;
					dragon->position = 12;
					fighting = false;
				}
				else
				{
					cout << "You don't have a sword equipped." << endl << endl;
					dragon->state = 2;
				}
			}
			else
			{
				cout << "You did nothing." << endl << endl;
				dragon->state = 2;
			}
			break;
		}
	}
}

void World::SkeletonChase()
{
	cout << "You start walking towards the altar but then a Cool Skeleton appears from nowhere. He's wearing a cool cape:" << endl;
	cout << "'Nyeh heh heh heh heh! I'm going to get the orb before you!'" << endl << endl;
	bool chase = true;

	char buffer[25] = "lel";
	String answer(buffer);

	while (chase)
	{
		switch (skeleton->state)
		{
		case 0:
			cout << "The skeleton starts running towards the altar. What will you do? (chase him / throw the sword at him)" << endl << endl;
			while (1)
			{
				gets_s(buffer);
				answer = buffer;

				if (answer == "chase him")
				{
					skeleton->state = 1;
					break;
				}
				else if (answer == "throw the sword at him" || answer == "throw sword")
				{
					skeleton->state = 2;
					break;
				}
				else
				{
					cout << "Make a decision, fast! (chase him / throw the sword at him)" << endl << endl;
				}
			}
			break;

		case 1:
			cout << "You're chasing the skeleton. You can almost touch his cape. What will you do? (pull the cape / continue to chase)" << endl << endl;
			while (1)
			{
				gets_s(buffer);
				answer = buffer;

				if (answer == "pull the cape")
				{
					skeleton->state = 4;
					break;
				}
				else if (answer == "continue to chase")
				{
					skeleton->state = 5;
					break;
				}
				else
				{
					cout << "Make a decision, fast! (pull the cape / continue to chase)" << endl << endl;
				}
			}
			break;

		case 2:
			cout << "You threw your sword at the skeleton. You knocked his head off. He's now unconscious. What will you do? (move forward)" << endl << endl;
			while (1)
			{
				gets_s(buffer);
				answer = buffer;

				if (answer == "move forward")
				{
					cout << "You started moving towards the altar, but suddently you activated a pitfall trap." << endl << endl << "You are DEAD." << endl << endl << "Press any key to quit.";
					dead = true;
					chase = false;
					break;
				}
				else
				{
					cout << "You decided to move forward anyway. You started moving towards the altar, but suddently you activated a pitfall trap." << endl << endl << "You are DEAD." << endl << endl << "Press any key to quit.";
					dead = true;
					chase = false;
					break;
				}
			}
			break;

		case 4:
			cout << "You pulled the skeleton's cape. You caused him to fall to the ground. He's now unconscious. What will you do? (move forward)" << endl << endl;
			while (1)
			{
				gets_s(buffer);
				answer = buffer;

				if (answer == "move forward")
				{
					cout << "You started moving towards the altar, but suddently you activated a pitfall trap." << endl << endl << "You are DEAD." << endl << endl << "Press any key to quit.";
					dead = true;
					chase = false;
					break;
				}
				else
				{
					cout << "You decided to move forward anyway. You started moving towards the altar, but suddently you activated a pitfall trap." << endl << endl << "You are DEAD." << endl << endl << "Press any key to quit.";
					dead = true;
					chase = false;
					break;
				}
			}
			break;

		case 5:
			cout << "The skeleton activated a pitfall trap. He's now unconscious. What will you do? (jump over the trap / move forward)" << endl << endl;
			while (1)
			{
				gets_s(buffer);
				answer = buffer;

				if (answer == "jump over the trap")
				{
					cout << "You got to the altar." << endl << endl;
					skeleton->position = 12;
					adventurer->items.PushBack(entities[30]);
					chase = false;
					chasing = false;
					((Room*)entities[11])->ModifyDescription("There's an altar with a shiny orb on top.");
					break;
				}
				else if (answer == "move forward")
				{
					cout << "You fell into the trap like an idiot." << endl << endl << "You are DEAD" << endl << endl << "Press any key to quit.";
					dead = true;
					chase = false;
					break;
				}
				else
				{
					cout << "Make a decision (jump over the trap / move forward)" << endl << endl;
				}
			}
			break;
		}
	}
}
void World::Execute(const String& str, int dir, const String& item, int pickdrop, int& position)
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
						cout << entities[i]->GetDescription() << endl << endl;
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
		if (adventurer->CheckPosition() == 11 && dir == 3)
		{
			cout << "There's no going back now!" << endl << endl;
		}
		else if (((Room*)entities[position])->CheckOptions(dir) != -1 && ((Exit*)entities[((Room*)entities[position])->CheckDoors(dir)])->IsOpen())
		{
			position = ((Room*)entities[position])->CheckOptions(dir);
			Move(position);
			if (adventurer->CheckPosition() == dragon->position)
			{
				fighting = true;
			}
			if (adventurer->CheckPosition() == skeleton->position)
			{
				chasing = true;
			}
		}
		else if (((Room*)entities[position])->CheckOptions(dir) == -1)
		{
			cout << "There's no room in that direction." << endl << endl;
		}
		else if (adventurer->CheckPosition() == 8)
		{
			cout << "There's no room in that direction" << endl << endl;
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

			if (adventurer->GetItem("Sword") && misterious->state < 4  || adventurer->GetEquip("Sword") && misterious->state < 4)
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
							((Exit*)entities[13])->ModifyState();
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
							((Exit*)entities[13])->ModifyState();
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
					cout << "You recieved a Wooden Shield!" << endl << endl;
					adventurer->items.PushBack(entities[24]);
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
		switch (position)
		{
		case 0:
			cout << "It is locked with a mechanism you don't understand." << endl << endl;
			break;

		case 2:
			cout << "It is locked with a mechanism you don't understand." << endl << endl;
			break;

		case 5:
			if (((Exit*)entities[17])->IsOpen() == false && adventurer->GetItem("Copper Key"))
			{
				((Exit*)entities[17])->ModifyState();
				cout << "You used the Copper Key to open the Copper Door" << endl << endl;
				adventurer->itemCap--;
				dList<Entity*>::dNode* temp = adventurer->items.first;
				String key("Copper Key");
				for (; temp != nullptr; temp = temp->next)
				{
					if (key == temp->data->GetName())
					{
						adventurer->items.erase(temp);
						break;
					}
				}
			}
			else if (((Exit*)entities[17])->IsOpen())
			{
				cout << "The door is already open." << endl << endl;
			}
			else
			{
				cout << "You need the Copper Key to open this door." << endl << endl;
			}
			break;

		case 6:
			if (((Exit*)entities[20])->IsOpen() == false && adventurer->GetItem("Silver Key"))
			{
				((Exit*)entities[20])->ModifyState();
				cout << "You used the Silver Key to open the Silver Door" << endl << endl;
				adventurer->itemCap--;
				dList<Entity*>::dNode* temp = adventurer->items.first;
				String key("Silver Key");
				for (; temp != nullptr; temp = temp->next)
				{
					if (key == temp->data->GetName())
					{
						adventurer->items.erase(temp);
						break;
					}
				}
			}
			else if (((Exit*)entities[20])->IsOpen())
			{
				cout << "The door is already open." << endl << endl;
			}
			else
			{
				cout << "You need the Silver Key to open this door." << endl << endl;
			}
			break;

		default:
			cout << "There's are no locked doors nearby." << endl << endl;
			break;
		}
	}

	//KEYS

	else if (str == "opencopper!")
	{
		if (adventurer->GetItem(item))
		{
			if (adventurer->CheckPosition() == 5)
			{
				if (((Exit*)entities[17])->IsOpen() == false)
				{
					((Exit*)entities[17])->ModifyState();
					cout << "You used the Copper Key to open the Copper Door" << endl << endl;
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
				}
				else if (((Exit*)entities[17])->IsOpen())
				{
					cout << "The door is already open." << endl << endl;
				}
			}
			else
			{
				cout << "There is no use for that in here." << endl << endl;
			}
		}
		else
		{
			cout << "You don't have that item in your inventory." << endl << endl;
		}
	}

	else if (str == "opensilver!")
	{
		if (adventurer->GetItem(item))
		{
			if (adventurer->CheckPosition() == 6)
			{
				if (((Exit*)entities[20])->IsOpen() == false)
				{
					((Exit*)entities[20])->ModifyState();
					cout << "You used the Silver Key to open the Silver Door" << endl << endl;
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
				}
				else if (((Exit*)entities[17])->IsOpen())
				{
					cout << "The door is already open." << endl << endl;
				}
			}
			else
			{
				cout << "There is no use for that in here." << endl << endl;
			}
		}
		else
		{
			cout << "You don't have that item in your inventory." << endl << endl;
		}
	}

	//OPEN CHEST

	else if (str == "openchest!")
	{
		if (adventurer->CheckPosition() == 9 && chest->GetItem(item))
		{
			cout << "You got a Grenade from the chest!" << endl << endl;
			adventurer->items.PushBack(entities[28]);
			adventurer->itemCap++;
			dList<Entity*>::dNode* temp = chest->items.first;
			for (; temp != nullptr; temp = temp->next)
			{
				if (item == temp->data->GetName())
				{
					chest->items.erase(temp);
					break;
				}
			}
		}
		else if (adventurer->CheckPosition() == 9 && chest->GetItem(item) == false)
		{
			cout << "How can you pretend to open something that's already open?" << endl << endl;
		}
		else
		{
			cout << "There's no chest in here." << endl << endl;
		}
	}

	//BUTTON

	else if (str == "pressbutton!")
	{
		if (adventurer->CheckPosition() == 4)
		{
			((Exit*)entities[16])->ModifyState();
			if (((Exit*)entities[16])->IsOpen())
			{
				cout << "You feel like you opened some door somewhere." << endl << endl;
			}
			else
			{
				cout << "You feel like you closed some door somewhere." << endl << endl;
			}
		}
		else
		{
			cout << "There's no such thing nearby." << endl << endl;
		}
	}

	//SACK OF GRAIN

	else if (str == "sackofgrain!")
	{
		if (adventurer->GetItem(item))
		{
			if (adventurer->CheckPosition() == 7)
			{
				cout << "You put the Sack of grain on the floor. The toucan noticed it, dropped what he was holding, grabbed the Sack and got away through the window." << endl << endl;
				toucan->ModifyPosition(12);
				((Room*)entities[position])->items.PushBack(entities[27]);
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
			}
			else
			{
				cout << "Nothing happened." << endl << endl;
			}
		}
		else
		{
			cout << "You don't have that in your inventory." << endl << endl;
		}
	}

	//GRENADE

	else if (str == "grenade!")
	{
		if (adventurer->GetItem(item))
		{
			if (adventurer->CheckPosition() == 8)
			{
				cout << "You threw the grenade against the wall. The explosion caused the wall to fall to pieces leaving a hole behind it." << endl << endl;
				adventurer->itemCap--;
				((Exit*)entities[21])->ModifyState();
				((Exit*)entities[21])->ModifyDescription("A huge hole that leads deeper into this strange place.");
				((Room*)entities[8])->ModifyDescription("It's completely empty. There's a huge hole in the northern wall.");
				dList<Entity*>::dNode* temp = adventurer->items.first;
				for (; temp != nullptr; temp = temp->next)
				{
					if (item == temp->data->GetName())
					{
						adventurer->items.erase(temp);
						break;
					}
				}
			}
			else
			{
				cout << "You better don't use it here." << endl << endl;
			}
		}
		else
		{
			cout << "You don't have that in your inventory." << endl << endl;
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
			cout << "This room contains no items.";
		}
		if (adventurer->CheckPosition() == misterious->CheckPosition())
		{
			cout << " There's a misterious masked man staring at you.";
		}
		if (adventurer->CheckPosition() == toucan->CheckPosition())
		{
			cout << " There's a toucan holding something in his beak, but you can't reach it either.";
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
		if (adventurer->CheckPosition() == 11 && item == "Orb")
		{
			cout << "You can't pick the orb because you're carrying too much toucan" << endl << endl;
		}
		else
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

	//DROP TOUCAN

	else if (str == "droptoucan!")
	{
		cout << "Toucan: What a horrible pijama!" << endl << endl << "The toucan flew around the room for a while, grabbed the orb and then flew away through a hole in the ceiling." << endl << endl << "<<< THE END >>>" << endl << endl;
		cout << "Zork: Pijama adventures. A zork by Albert Llopart";

		ending = true;
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
		Move(position);
	}
	else if (str == "teleport 2")
	{
		position = 6;
		Move(position);
	}
	else if (str == "teleport 3")
	{
		position = 11;
		Move(position);
		chasing = true;
	}

	//CHEAT

	else if (str == "photonman!")
	{
		adventurer->items.PushBack(entities[23]);
		adventurer->items.PushBack(entities[24]);
		adventurer->items.PushBack(entities[25]);
		adventurer->items.PushBack(entities[26]);
		adventurer->items.PushBack(entities[27]);
		adventurer->items.PushBack(entities[28]);
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
	delete dragon;
	delete skeleton;
	delete toucan;
	delete warrior;
	delete misterious;
	delete chest;
	delete box;
	delete adventurer;
}