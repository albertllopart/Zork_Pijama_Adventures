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
	return (char*)name->GetStr();
}

const char* Entity::GetDescription()const
{
	return (char*)description->GetStr();
}

int Entity::GetCap()const
{
	return itemCap;
}

void Entity::PickDrop(int item)
{
	if (itemsP[item]) itemsP[item] = false, itemCap--;
	else itemsP[item] = true, itemCap++;
}

bool Entity::GetItem(char* item)const
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
			if (temp->data->GetName() == item)
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
