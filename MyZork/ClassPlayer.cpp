#include "ClassPlayer.h"

Player::Player(const char* name, const char* description) : Entity(name, description)
{
	position = Hall;
	itemCap = 0;

	for (int i = 0; i < 7; i++)
	{
		itemsP.PushBack(false);
	}
}

int Player::CheckPosition()const
{
	return position;
}

void Player::ModifyPosition(int next)
{
	position = next;
}

Player::~Player()
{
	
}