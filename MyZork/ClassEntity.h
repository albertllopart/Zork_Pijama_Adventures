#include "ClassString.h"

class Entity
{
private:

	String* name = nullptr;
	String* description = nullptr;

public:

	Entity();
	~Entity();

	void ModifyName(const String& str);
	void ModifyDescription(const String& str);
	void ModifyParameters(const char* str1, const char* str2);
	char* GetName()const;
	char* GetDescription()const;

};