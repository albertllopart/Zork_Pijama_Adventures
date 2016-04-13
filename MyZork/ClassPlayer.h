#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include "ClassEntity.h"

class Player:public Entity
{
private:

	int position;
	enum location {Hall};

public:

	Player(const String& name, const String& description);
	~Player();

	int CheckPosition()const;
	void ModifyPosition(int next);

};

#endif