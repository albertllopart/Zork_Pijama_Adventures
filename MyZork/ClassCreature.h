#ifndef CLASS_CREATURE
#define CLASS_CREATURE

#include "ClassEntity.h"
#include "ClassVector.h"
#include "Class List.h"

class Creature :public Entity
{
private:


public:

	Creature(const char* name, const char* description, int position);
	~Creature();

	int position;

	int state;

	int CheckPosition()const;
	void ModifyPosition(int next);
	
};

#endif