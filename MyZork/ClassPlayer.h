#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include "ClassEntity.h"
#include "ClassVector.h"

class Player:public Entity
{
private:

	Vector<bool> itemsP;
	Vector<bool> equipment;
	Vector<int> stats;
	uint itemCap;

	int position;
	enum location {Hall};

public:

	Player(const char* name, const char* description);
	~Player();

	int CheckPosition()const;
	void ModifyPosition(int next);
	void PickDrop(int item);
	void EquipUnequip(int item);
	bool GetItem(int item)const;
	bool GetEquip(int item)const;
	int GetStat(int stat)const;
	uint GetCap()const;

};

#endif