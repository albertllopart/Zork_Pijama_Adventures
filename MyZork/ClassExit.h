#ifndef CLASS_EXIT
#define CLASS_EXIT

#include "ClassEntity.h"


class Exit:public Entity
{
private:

	bool open;

public:

	Exit();
	~Exit();

	bool IsOpen()const;
	void ModifyState();

};

#endif