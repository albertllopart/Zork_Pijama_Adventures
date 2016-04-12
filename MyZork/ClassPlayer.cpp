#include "ClassPlayer.h"

Player::Player()
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