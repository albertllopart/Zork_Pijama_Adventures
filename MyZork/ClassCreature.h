#ifndef CLASS_CREATURE
#define CLASS_CREATURE

#include "ClassEntity.h"
#include "ClassVector.h"
#include "Class List.h"

class Creature :public Entity
{
private:

	int position;

public:

	Creature(const char* name, const char* description, int position);
	~Creature();

	int CheckPosition()const;
	void ModifyPosition(int next);
	
};

#endif