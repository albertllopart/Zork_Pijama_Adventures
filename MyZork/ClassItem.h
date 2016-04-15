#ifndef CLASS_ITEM
#define CLASS_ITEM

#include "ClassEntity.h"

class Item :public Entity
{
private:



public:

	Item();
	Item(const char* name, const char* description);
	~Item();

};

#endif