#include "ClassRoom.h"

Room::Room(){};

Room::Room(const char* name, const char* description) : Entity(name, description)
{
	firstVisit = true;
	NPCallow = false;
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