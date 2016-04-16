#ifndef CLASS_ROOM
#define CLASS_ROOM

#include "ClassEntity.h"
#include "ClassVector.h"

class Room:public Entity
{
private:

	Vector<int> options;
	Vector<int> doors;
	Vector<bool> itemsR;

	bool firstVisit;

public:

	Room();
	Room(const char* name, const char* description);

	int CheckOptions(int dir)const;
	int CheckDoors(int dir)const;

	void ModifyOptions(int n, int s, int e, int w);
	void ModifyDoors(int n, int s, int e, int w);
	void ModifyItems(int item1, int item2);
	bool GetItem(int item)const;
	void PickDrop(int item);
	void NoDescription();
	bool FirstVisit()const;

	~Room();
};

#endif

