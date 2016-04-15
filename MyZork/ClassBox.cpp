#include "ClassBox.h"

Box::Box(){};

Box::Box(const char* name, const char* description) : Entity(name, description)
{
	for (int i = 0; i < 7; i++)
	{
		itemsB.PushBack(false);
	}
}

Box::~Box(){};