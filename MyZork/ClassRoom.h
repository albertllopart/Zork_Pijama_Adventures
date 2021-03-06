#ifndef CLASS_ROOM
#define CLASS_ROOM

#include "ClassEntity.h"
#include "ClassVector.h"

class Room:public Entity
{
private:

	Vector<int> options;
	Vector<int> doors;

	bool firstVisit;

public:

	Room();
	Room(const char* name, const char* description);

	int CheckOptions(int dir)const;
	int CheckDoors(int dir)const;

	bool NPCallow;

	void ModifyOptions(int n, int s, int e, int w);
	void ModifyDoors(int n, int s, int e, int w);

	void NoDescription();
	bool FirstVisit()const;

	~Room();
};

#endif

