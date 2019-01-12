#include "C_sharp_developer.h"

short int C_sharp_developer::get_experience()const
{
	return c_experience;
}

bool C_sharp_developer::set_experience(short int experience)
{
	if (experience < 0)
	{
		error_value();
		return false;
	}
	else
		c_experience = experience;

	return true;
}

void C_sharp_developer::show()const
{
	Programmer base = (*this);
	base.show();
	cout << "Опыт разработки:" << c_experience << endl;
}

C_sharp_developer::C_sharp_developer()
{
	c_experience = 0;
}

C_sharp_developer::C_sharp_developer(short int experience, bool has_certificate_or_diploma_programmer, string name, short int age):Programmer(has_certificate_or_diploma_programmer, name, age)
{
	if (experience < 0)
	{
		error_value();
		c_experience = 0;
	}
	else
		c_experience = experience;

	c_experience = experience;
}

C_sharp_developer::~C_sharp_developer()
{
}