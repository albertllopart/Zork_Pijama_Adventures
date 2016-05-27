#include "ClassPlayer.h"

Player::Player(const char* name, const char* description) : Entity(name, description)
{
	position = Hall;

	for (int i = 0; i < 2; i++)
	{
		equipment.PushBack(false);
	}
	stats.PushBack(100); //HP
	stats.PushBack(0); //ATTACK
	stats.PushBack(0); //DEFENSE
}

int Player::CheckPosition()const
{
	return position;
}

void Player::ModifyPosition(int next)
{
	position = next;
}

bool Player::GetEquip(int item)const
{
	return true;
}

int Player::GetStat(int stat)const
{
	return stats[stat];
}

Player::~Player()
{
	
}