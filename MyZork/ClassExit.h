#include <iostream>
#include <string>

using namespace std;

class Exit
{
private:

	char* description = nullptr;
	bool open;

public:

	Exit();

	char* CheckDescription()const;
	bool IsOpen()const;

	void ModifyExit(char description[250]);
	void ModifyState();

	~Exit();
};