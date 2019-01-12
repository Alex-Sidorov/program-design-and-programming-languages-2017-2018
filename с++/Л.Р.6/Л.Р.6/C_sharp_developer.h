#pragma once

#include "Programmer.h"

class C_sharp_developer : public Programmer
{
public:
	short int get_experience()const;
	bool set_experience(short int experience);

	void show()const;

	C_sharp_developer(short int experience, bool has_certificate_or_diploma_programmer, string name, short int age);
	C_sharp_developer();
	virtual ~C_sharp_developer();

private:
	short int c_experience;
};