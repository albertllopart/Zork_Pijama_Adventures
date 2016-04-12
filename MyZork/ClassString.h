#ifndef CLASS_STRING
#define CLASS_STRING

#include <string.h>

class String
{
private:

	char* str = nullptr;
	unsigned int capacity;

public:

	String();
	String(const char* str);
	String(const String& str);
	~String();

	const char* GetStr()const;
	unsigned int GetLenght()const;
	int GetCapacity()const;
	bool Empty()const;

	bool operator ==(const String& str)const;
	bool operator ==(const char* str)const;
	void operator =(const String& str);
	void operator =(const char* str);

	bool SameLenght(const String& str)const;
	bool SameLenght(const char* str)const;
	bool IsShorter(const String& str)const;
	bool IsShorter(const char* str)const;
};

#endif