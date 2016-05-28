#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include "ClassCreature.h"

class Player:public Creature
{
private:

	Vector<int> stats;

public:

	Player(const char* name, const char* description, int position);
	~Player();

	void EquipUnequip(const String& item);
	int GetStat(int stat)const;
	
};

#endif