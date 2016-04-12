#include <iostream>
#include <string>
#include "ClassString.h"

using namespace std;

class Command
{
private:

	enum dir {stay = -1, north, south, east, west};

public:

	Command(){};

	void ReadInstruction(String& str, int &dir)const;

	~Command(){};
};