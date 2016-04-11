#include "ClassRoom.h"

Room::Room()
{

}

int Room::CheckOptions(int dir)const
{
	return options[dir];
}

int Room::CheckDoors(int dir)const
{
	return doors[dir];
}

void Room::ModifyOptions(int n, int s, int e, int w)
{
	options[0] = n;
	options[1] = s;
	options[2] = e;
	options[3] = w;
}

void Room::ModifyDoors(int n, int s, int e, int w)
{
	doors[0] = n;
	doors[1] = s;
	doors[2] = e;
	doors[3] = w;
}

Room::~Room()
{
	
}