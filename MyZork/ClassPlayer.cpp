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

void Player::EquipUnequip(int item)
{
	if (equipment[item])
	{
		equipment[item] = false;
		if (item == 0)
		{
			stats[1] += -10;
		}
		else if (item == 1)
		{
			stats[2] += -10;
		}
	}
	else
	{
		equipment[item] = true;
		if (item == 0)
		{
			stats[1] += 10;
		}
		else if (item == 1)
		{
			stats[2] += 10;
		}
	}
}

bool Player::GetEquip(int item)const
{
	return equipment[item];
}

int Player::GetStat(int stat)const
{
	return stats[stat];
}

Player::~Player()
{
	
}