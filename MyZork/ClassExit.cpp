#include "ClassExit.h"

Exit::Exit()
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