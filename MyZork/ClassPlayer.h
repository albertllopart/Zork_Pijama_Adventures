#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include "ClassEntity.h"
#include "ClassVector.h"
#include "Class List.h"

class Player:public Entity
{
private:

	Vector<int> stats;

	int position;
	enum location {Hall};

public:

	Player(const char* name, const char* description);
	~Player();

	int CheckPosition()const;
	void ModifyPosition(int next);
	void EquipUnequip(const String& item);
	int GetStat(int stat)const;
	

};

#endif