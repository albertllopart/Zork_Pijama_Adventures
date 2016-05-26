#ifndef CLASS_ENTITY
#define CLASS_ENTITY

#include "ClassString.h"
#include "ClassVector.h"
#include "Class List.h"

class Entity
{
private:

	String* name = nullptr;
	String* description = nullptr;

	Vector<bool> itemsP;
	int itemCap;

public:

	Entity();
	Entity(const String& name, const String& description);
	Entity(const char* name, const char* description);
	Entity(const String& name);
	~Entity();

	dList <Entity*> items;

	void ModifyParameters(const char* str1, const char* str2);
	const char* GetName()const;
	const char* GetDescription()const;

	int GetCap()const;
	bool GetItem(char* item)const;

};

#endif