#include <iostream>
#include "ClassString.h"

using namespace std;

class Command
{
private:

	enum dir {stay = -1, north, south, east, west};
	enum items {nothing = -1, sword = 23, shield, sack, copper, silver, grenade, orb};
	int dir;
	int item;
	String itemName;

public:

	Command();

	void ReadInstruction(String& str);
	void ModifyDirection(int dir);
	void ModifyItem(int item);
	void ModifyitemName(const char* itemName);
	int GetDirection()const;
	int GetItem()const;
	const String& GetItemName()const;
	~Command();
};