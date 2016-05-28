#ifndef CLASS_NPC
#define CLASS_NPC

#include "ClassCreature.h"

class NPC :public Creature
{
private:



public:

	NPC(const char* name, const char* description, int position);
	~NPC();

};

#endif