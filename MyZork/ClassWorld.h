#ifndef CLASS_WORLD
#define CLASS_WORLD

#include "ClassRoom.h"
#include "ClassExit.h"
#include "ClassPlayer.h"
#include "ClassNPC.h"
#include "ClassEnemy.h"
#include "ClassCommand.h"
#include "ClassVector.h"
#include "Class List.h"

class World
{
private:

	Player* adventurer = nullptr;
	Entity* box = nullptr;
	Entity* chest = nullptr;
	NPC* misterious = nullptr;
	NPC* warrior = nullptr;
	NPC* toucan = nullptr;
	NPC* skeleton = nullptr;
	Enemy* dragon = nullptr;

	bool playing;
	
public:

	World(const char* str);
	~World();

	bool dead;
	bool fighting;

	Vector <Entity*> entities;

	void CheckRoom(int room);
	int CheckPosition()const;
	void Move(int position);
	void Execute(const String& str, int dir, const String& item, int pickdrop, int& position);
	bool Talking()const;
	void NPCMove(int direction);
	bool Continue()const;
	void DragonFight();

	void CreateWorld();
	void EndGame();
};

#endif