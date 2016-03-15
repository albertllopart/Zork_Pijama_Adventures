#include "ClassRoom.h"

Room::Room()
{
	name = new char[25];
	description = new char[250];
}

int Room::CheckOptions(int dir)const
{
	return options[dir];
}

int Room::CheckDoors(int dir)const
{
	return doors[dir];
}

char* Room::CheckName()const
{
	return name;
}

char* Room::CheckDescription()const
{
	return description;
}

void Room::ModifyRoom(char name[25], char description[250])
{
	this->name = name;
	this->description = description;
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