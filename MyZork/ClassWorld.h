#ifndef CLASS_WORLD
#define CLASS_WORLD

#include "ClassRoom.h"
#include "ClassExit.h"
#include "ClassPlayer.h"
#include "ClassCommand.h"

class World
{
private:

	Room* rooms = nullptr;
	Exit* exits = nullptr;
	Player* adventurer = nullptr;

	bool playing;
	
public:

	World();
	~World();

	void CheckRoom(int i)const;
	int CheckPosition()const;
	void Move(int position);
	void Execute(const String& str, int dir, int &position)const;
	bool Continue()const;

	void CreateWorld(const char* str);
	void EndGame();
};

#endif