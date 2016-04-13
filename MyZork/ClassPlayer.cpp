#include "ClassPlayer.h"

Player::Player(const String& name, const String& description) : Entity(name, description)
{
	position = Hall;
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