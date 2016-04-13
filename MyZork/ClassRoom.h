#ifndef CLASS_ROOM
#define CLASS_ROOM

#include "ClassEntity.h"

class Room:public Entity
{
private:

	int options[4];
	int doors[4];

public:

	Room();
	Room(const char* name, const char* description);
	Room(const String& name, const String& description);

	int CheckOptions(int dir)const;
	int CheckDoors(int dir)const;

	void ModifyOptions(int n, int s, int e, int w);
	void ModifyDoors(int n, int s, int e, int w);

	~Room();
};

#endif

