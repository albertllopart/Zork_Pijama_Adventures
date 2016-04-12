#include "ClassString.h"


String::String(){};

String::String(const char* str)
{
	capacity = strlen(str) + 1;
	this->str = new char[capacity];
	strcpy_s(this->str, capacity, str);
}

String::String(const String& str)
{
	capacity = strlen(str.str) + 1;
	this->str = new char[capacity];
	strcpy_s(this->str, capacity, str.str);
}

String::~String()
{
	delete[]str;
}

const char* String::GetStr()const
{
	return str;
}

unsigned int String::GetLenght()const
{
	return strlen(str);
}

bool String::Empty()const
{
	return GetLenght() == 0;
}

bool String::operator ==(const String& str)const
{
	return strcmp(this->str, str.str) == 0;
}

bool String::operator ==(const char* str)const
{
	return strcmp(this->str, str) == 0;
}

void String::operator = (const String& str)
{
	if (SameLenght(str))
	{
		strcpy_s(this->str, capacity, str.str);
	}
	else if (IsShorter(str))
	{
		int len = str.capacity + 1;
		strcpy_s(this->str, len, str.str);
		this->str[len] = 0;
	}
	else
	{
		capacity = str.capacity;
		delete[]this->str;
		this->str = new char[capacity];
		strcpy_s(this->str, capacity, str.str);
	}
}

void String::operator =(const char* str)
{
	if (SameLenght(str))
	{
		strcpy_s(this->str, capacity, str);
	}
	else if (IsShorter(str))
	{
		int len = strlen(str) + 1;
		strcpy_s(this->str, len, str);
		this->str[len] = 0;
	}
	else
	{
		capacity = strlen(str) + 1;
		delete[]this->str;
		this->str = new char[capacity];
		strcpy_s(this->str, capacity, str);
	}
}

bool String::SameLenght(const String& str)const
{
	return capacity == str.capacity;
}

bool String::SameLenght(const char* str)const
{
	return capacity == strlen(str);
}

bool String::IsShorter(const String& str)const
{
	return capacity > str.capacity;
}

bool String::IsShorter(const char* str)const
{
	return capacity > strlen(str);
}

int String::GetCapacity()const
{
	return capacity;
}
