#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include "ClassEntity.h"

class Player:public Entity
{
private:

	int position;
	enum location {Hall};

public:

	Player(const char* name, const char* description);
	~Player();

	int CheckPosition()const;
	void ModifyPosition(int next);

};

#endif