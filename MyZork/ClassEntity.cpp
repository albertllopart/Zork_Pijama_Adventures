#include "ClassEntity.h"

Entity::Entity(){};

Entity::Entity(const char* name, const char* description)
{
	this->name = new String(name);
	this->description = new String(description);

	itemCap = 0;
}

Entity::Entity(const String& name, const String& description)
{
	this->name = new String(name);
	this->description = new String(description);

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

void Entity::ModifyDescription(const char* newdescription)
{
	*description = newdescription;
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

bool Entity::GetEquip(const String& item)const
{
	if (equipment.first == nullptr)
	{
		return false;
	}
	else
	{
		dList<Entity*>::dNode* temp = equipment.first;
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
