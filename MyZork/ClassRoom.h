#include<iostream>
#include<string>

using namespace std;

class Room
{
private:

	char* name = nullptr;
	char* description = nullptr;
	int options[4];
	int doors[4];

public:

	Room();

	char* CheckName()const;
	char* CheckDescription()const;
	int CheckOptions(int dir)const;
	int CheckDoors(int dir)const;

	void ModifyRoom(char nam[25], char descriptio[250]);
	void ModifyOptions(int n, int s, int e, int w);
	void ModifyDoors(int n, int s, int e, int w);

	~Room();
};

