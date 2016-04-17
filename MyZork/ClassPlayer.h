#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include "ClassEntity.h"
#include "ClassVector.h"

class Player:public Entity
{
private:

	Vector<bool> equipment;
	Vector<int> stats;

	int position;
	enum location {Hall};

public:

	Player(const char* name, const char* description);
	~Player();

	int CheckPosition()const;
	void ModifyPosition(int next);
	void EquipUnequip(int item);
	bool GetEquip(int item)const;
	int GetStat(int stat)const;
	

};

#endif