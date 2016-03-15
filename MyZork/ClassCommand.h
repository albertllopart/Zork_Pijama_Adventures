#include <iostream>
#include <string>

using namespace std;

class Command
{
private:

	enum dir {stay = -1, north, south, east, west};

public:

	Command(){};

	void ReadInstruction(char instr[25], int &dir)const;

	~Command(){};
};