#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include "ClassEntity.h"
#include "ClassVector.h"

class Player:public Entity
{
private:

	Vector<bool> itemsP;
	uint itemCap;

	int position;
	enum location {Hall};

public:

	Player(const char* name, const char* description);
	~Player();

	int CheckPosition()const;
	void ModifyPosition(int next);
	void PickDrop(int item);
	bool GetItem(int item)const;
	uint GetCap()const;

};

#endif