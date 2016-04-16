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

void Player::PickDrop(int item)
{
	if (itemsP[item]) itemsP[item] = false, itemCap--;
	else itemsP[item] = true, itemCap++;
}

bool Player::GetItem(int item)const
{
	return itemsP[item];
}

uint Player::GetCap()const
{
	return itemCap;
}

Player::~Player()
{
	
}