#include<iostream>
#include "ClassEntity.h"

using namespace std;

class Room:public Entity
{
private:

	int options[4];
	int doors[4];

public:

	Room();

	int CheckOptions(int dir)const;
	int CheckDoors(int dir)const;

	void ModifyOptions(int n, int s, int e, int w);
	void ModifyDoors(int n, int s, int e, int w);

	~Room();
};

