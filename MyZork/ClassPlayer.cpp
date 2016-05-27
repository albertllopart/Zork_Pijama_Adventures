#include "ClassPlayer.h"

Player::Player(const char* name, const char* description) : Entity(name, description)
{
	position = Hall;

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

void Player::EquipUnequip(const String& item)
{
	if (item == "Sword")
	{
		if (stats[1] == 0)
		{
			stats[1] = 10;
		}
		else stats[1] = 0;
	}
	else if (item == "Wooden Shield")
	{
		if (stats[2] == 0)
		{
			stats[2] = 10;
		}
		else stats[2] = 0;
	}
}

int Player::GetStat(int stat)const
{
	return stats[stat];
}

Player::~Player()
{
	
}