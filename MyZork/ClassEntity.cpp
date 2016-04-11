#include "ClassEntity.h"

Entity::Entity()
{
	name = new String();
	description = new String();
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
void Entity::ModifyDescription(const String& str)
{
	*description = str;
}
void Entity::ModifyParameters(const char* str1, const char* str2)
{
	*name = str1;
	*description = str2;
}

char* Entity::GetName()const
{
	return (char*)name->GetStr();
}
char* Entity::GetDescription()const
{
	return (char*)description->GetStr();
}