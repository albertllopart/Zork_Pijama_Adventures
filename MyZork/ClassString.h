#include <string.h>

class String
{
private:

	char* str = nullptr;
	unsigned int capacity;

public:

	String(const char* str);
	String(const String& str);
	~String();

	const char* GetStr()const;
	unsigned int GetLenght()const;
	bool Empty()const;

	bool operator ==(const String& str)const;
	bool operator ==(const char* str)const;
	void operator =(const String& str);
	void operator =(const char* str);

	bool SameLenght(const String& str);
	bool SameLenght(const char* str);
	bool IsShorter(const String& str);
	bool IsShorter(const char* str);
	int GetCapacity();
};