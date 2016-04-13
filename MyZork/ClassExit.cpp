#include "ClassExit.h"

Exit::Exit(const String& description) : Entity(description)
{
	open = true;
};

bool Exit::IsOpen()const
{
	return open;
}

void Exit::ModifyState()
{
	if (open) open = false;
	else open = true;
}

Exit::~Exit()
{
	
}