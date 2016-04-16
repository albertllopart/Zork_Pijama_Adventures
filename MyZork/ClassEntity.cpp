#include "ClassEntity.h"

Entity::Entity(){};

Entity::Entity(const char* name, const char* description)
{
	this->name = new String(name);
	this->description = new String(description);
}

Entity::Entity(const String& name, const String& description)
{
	this->name = new String(name);
	this->description = new String(description);
}

Entity::Entity(const String& description)
{
	this->description = new String(description);
}

Entity::~Entity()
{
	delete name;
	delete description;
}

void Entity::ModifyName(const String& str)
{
	*name = str;
}

void Entity::ModifyName(const char* str)
{
	*name = str;
}

void Entity::ModifyDescription(const String& str)
{
	*description = str;
}

void Entity::ModifyParameters(const char* str1, const char* str2)
{
	*name = str1;
	*description = str2;
}

const char* Entity::GetName()const
{
	return (char*)name->GetStr();
}

const char* Entity::GetDescription()const
{
	return (char*)description->GetStr();
}