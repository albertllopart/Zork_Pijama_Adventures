#include "ClassEntity.h"

Entity::Entity(){};

Entity::Entity(const char* name, const char* description)
{
	this->name = new String(name);
	this->description = new String(description);

	for (int i = 0; i < 7; i++)
	{
		itemsP.PushBack(false);
	}
	itemCap = 0;
}

Entity::Entity(const String& name, const String& description)
{
	this->name = new String(name);
	this->description = new String(description);

	for (int i = 0; i < 7; i++)
	{
		itemsP.PushBack(false);
	}
	itemCap = 0;
}

Entity::Entity(const String& description)
{
	this->description = new String(description);
	itemCap = 0;
}	

Entity::~Entity()
{
	delete name;
	delete description;
}

void Entity::ModifyParameters(const char* str1, const char* str2)
{
	*name = str1;
	*description = str2;
}

const char* Entity::GetName()const
{
	return name->GetStr();
}

const char* Entity::GetDescription()const
{
	return description->GetStr();
}

int Entity::GetCap()const
{
	return itemCap;
}



bool Entity::GetItem(const String& item)const
{
	if (items.first == nullptr)
	{
		return false;
	}
	else
	{
		dList<Entity*>::dNode* temp = items.first;
		while (temp != nullptr)
		{
			if (item == temp->data->GetName())
			{
				return true;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	return false;
}
