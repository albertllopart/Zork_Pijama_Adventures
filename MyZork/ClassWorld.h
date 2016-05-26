#ifndef CLASS_WORLD
#define CLASS_WORLD

#include "ClassRoom.h"
#include "ClassExit.h"
#include "ClassPlayer.h"
#include "ClassCommand.h"
#include "ClassVector.h"
#include "Class List.h"

class World
{
private:

	Vector <Entity*> entities;

	Player* adventurer = nullptr;
	Entity* box = nullptr;

	bool playing;
	
public:

	World(const char* str);
	~World();

	void CheckRoom(int room)const;
	int CheckPosition()const;
	void Move(int position);
	void Execute(const String& str, int dir, int item, int &position)const;
	bool Continue()const;

	void CreateWorld();
	void EndGame();
};

#endif