#ifndef CLASS_BOX
#define CLASS_BOX

#include "ClassEntity.h"
#include "ClassVector.h"

class Box:public Entity
{
private:

	Vector<bool> itemsB;

public:

	Box();
	Box(const char* name, const char* description);
	~Box();

};

#endif