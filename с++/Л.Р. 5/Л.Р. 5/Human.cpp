#include "Human.h"

void Human::set_name(string name)
{
	h_name = name;
}

bool Human::set_age(short int age)
{
	try
	{
		if (age < 0) throw 1;
		h_age = age;
	}
	catch (int error)
	{
		error_value();
		return false;
	}
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
	cout << "���:" << h_name<<endl;

	if (h_age<0)
		cout << "�������:����������" << h_age << endl;
	else
		cout << "�������:" << h_age << endl;
}

void Human::error_value()const
{
	cout << "����������� ��������" << endl;
}

Human::Human()
{
	h_age = 0;
	h_name = "���";
}

Human::Human(string name, short int age)
{
	try
	{
		if (age < 0) throw 1;
		h_age = age;
	}
	catch (int error)
	{
		error_value();
		h_age = -1;
	}

	h_name = name;
}

Human::~Human()
{
}