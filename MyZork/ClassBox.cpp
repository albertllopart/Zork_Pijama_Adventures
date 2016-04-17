#include "ClassBox.h"

Box::Box(){};

Box::Box(const char* name, const char* description) : Entity(name, description)
{
	for (int i = 0; i < 7; i++)
	{
		itemsB.PushBack(false);
	}
}

void Box::PickDrop(int item)
{
	if (itemsB[item]) itemsB[item] = false;
	else itemsB[item] = true;
}

bool Box::GetItem(int item)const
{
	return itemsB[item];
}

Box::~Box(){};