#include "ClassExit.h"

Exit::Exit()
{
	description = new char[250];
	open = false;
};

bool Exit::IsOpen()const
{
	return open;
}

char* Exit::CheckDescription()const
{
	return description;
}

void Exit::ModifyExit(char description[250])
{
	this->description = description;
}

void Exit::ModifyState()
{
	if (open) open = false;
	else open = true;
}

Exit::~Exit()
{
	
}