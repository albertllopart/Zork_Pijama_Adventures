#ifndef CLASS_ENEMY
#define CLASS_ENEMY

#include "ClassCreature.h"

class Enemy :public Creature
{
private:



public:

	Enemy(const char* name, const char* description, int position);
	~Enemy();

};

#endif