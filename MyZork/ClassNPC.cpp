#include "ClassNPC.h"

NPC::NPC(const char* name, const char* description, int position, const char* dialog1, const char* dialog2, const char* dialog3, const char* dialog4, const char* dialog5, const char* dialog6, const char* dialog7) : Creature(name, description, position)
{
	this->dialog1 = new String(dialog1);
	this->dialog2 = new String(dialog2);
	this->dialog3 = new String(dialog3);
	this->dialog4 = new String(dialog4);
	this->dialog5 = new String(dialog5);
	this->dialog6 = new String(dialog6);
	this->dialog7 = new String(dialog7);

	bool talking = false;
}

const char* NPC::GetDialog(int dialog)const
{
	switch (dialog)
	{
	case 1:
		return dialog1->GetStr();
	case 2:
		return dialog2->GetStr();
	case 3:
		return dialog3->GetStr();
	case 4:
		return dialog4->GetStr();
	case 5:
		return dialog5->GetStr();
	case 6:
		return dialog6->GetStr();
	case 7:
		return dialog7->GetStr();
	}
	return "ooops";
}

NPC::~NPC()
{

}