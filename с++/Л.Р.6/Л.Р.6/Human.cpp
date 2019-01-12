#include "Human.h"

void Human::set_name(string name)
{
	h_name = name;
}

bool Human::set_age(short int age)
{
	if (age < 0)
	{
		error_value();
		return false;
	}
	else
		h_age = age;

	return true;
}

short int Human::get_age()const
{
	return h_age;
}

string Human::get_name()const
{
	return h_name;
}

void Human::show()const
{
	cout << "Имя:" << h_name << endl;

	if (h_age<0)
		cout << "Возраст:неизвестен" << h_age << endl;
	else
		cout << "Возраст:" << h_age << endl;
}

void Human::error_value()const
{
	cout << "Некоректное значение" << endl;
}

Human::Human()
{
	h_age = 0;
	h_name = "Имя";
}

Human::Human(string name, short int age)
{
	if (age < 0)
	{
		error_value();
		h_age = 0;
	}
	else
		h_age = age;

	h_name = name;
}

Human::~Human()
{
}