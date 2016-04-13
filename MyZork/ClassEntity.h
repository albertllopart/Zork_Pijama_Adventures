#ifndef CLASS_ENTITY
#define CLASS_ENTITY

#include "ClassString.h"

class Entity
{
private:

	String* name = nullptr;
	String* description = nullptr;

public:

	Entity();
	Entity(const String& name, const String& description);
	Entity(const char* name, const char* description);
	Entity(const String& name);
	~Entity();

	void ModifyName(const String& str);
	void ModifyName(const char* str);
	void ModifyDescription(const String& str);
	void ModifyParameters(const char* str1, const char* str2);
	char* GetName()const;
	char* GetDescription()const;

};

#endif