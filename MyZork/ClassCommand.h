#include <iostream>
#include <string>
#include "ClassString.h"

using namespace std;

class Command
{
private:

	enum dir {stay = -1, north, south, east, west};
	enum items {nothing = -1, sword, shield, sack, copper, silver, grenade, orb};
	int dir;
	int item;

public:

	Command();

	void ReadInstruction(String& str);
	void ModifyDirection(int dir);
	void ModifyItem(int item);
	int GetDirection()const;
	int GetItem()const;

	~Command();
};