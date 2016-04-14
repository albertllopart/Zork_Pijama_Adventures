#ifndef CLASS_WORLD
#define CLASS_WORLD

#include "ClassRoom.h"
#include "ClassExit.h"
#include "ClassPlayer.h"
#include "ClassCommand.h"
#include "ClassVector.h"

class World
{
private:

	Vector <Room*> rooms;
	Vector <Exit*> exits;

	Player* adventurer = nullptr;

	bool playing;
	
public:

	World(const char* str);
	~World();

	void CheckRoom(int i)const;
	int CheckPosition()const;
	void Move(int position);
	void Execute(const String& str, int dir, int &position)const;
	bool Continue()const;

	void CreateWorld();
	void EndGame();
};

#endif