#include "Human.h"

void Human::set_name(string name)
{
	h_name = name;
}

string Human::get_name()const
{
	return h_name;
}

void Human::show()const
{
	cout << "���:" << h_name << endl;
}

Human::Human()
{
	h_name = "���";
}

Human::Human(string name)
{
	h_name = name;
}

Human::~Human()
{
}