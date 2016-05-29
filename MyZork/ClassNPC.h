#ifndef CLASS_NPC
#define CLASS_NPC

#include "ClassCreature.h"

class NPC :public Creature
{
private:

	String* dialog1;
	String* dialog2;
	String* dialog3;
	String* dialog4;
	String* dialog5;
	String* dialog6;
	String* dialog7;

public:

	NPC(const char* name, const char* description, int position, const char* dialog1, const char* dialog2, const char* dialog3, const char* dialog4, const char* dialog5, const char* dialog6, const char* dialog7);
	~NPC();

	bool talking;

	const char* GetDialog(int dialog)const;

};

#endif