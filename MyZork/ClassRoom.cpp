#include "ClassRoom.h"

Room::Room(){};

Room::Room(const char* name, const char* description) : Entity(name, description)
{
	firstVisit = true;
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
	options.PushFront(w);
	options.PushFront(e);
	options.PushFront(s);
	options.PushFront(n);
}

void Room::ModifyDoors(int n, int s, int e, int w)
{
	doors.PushFront(w);
	doors.PushFront(e);
	doors.PushFront(s);
	doors.PushFront(n);
}

void Room::ModifyItems(int item1, int item2)
{
	for (int i = 0; i < 7; i++)
	{
		if (i == item1 || i == item2)
		{
			itemsR.PushBack(true);
		}
		else itemsR.PushBack(false);
	}
}

bool Room::GetItem(int item)const
{
	return itemsR[item];
}

void Room::PickDrop(int item)
{
	if (itemsR[item]) itemsR[item] = false;
	else itemsR[item] = true;
}

void Room::NoDescription()
{
	if (firstVisit) firstVisit = false;
}

bool Room::FirstVisit()const
{
	return firstVisit;
}

Room::~Room()
{
	
}