#include "ClassCreature.h"

Creature::Creature(const char* name, const char* description, int position) : Entity(name, description)
{
	this->position = position;
	state = 0;
}

int Creature::CheckPosition()const
{
	return position;
}

void Creature::ModifyPosition(int next)
{
	position = next;
}

Creature::~Creature()
{

}