#include "Сhief.h"

int Chief::get_count_people()const
{
	return c_count_people;
}

string Chief::get_chief_location_place()const
{
	return chief_place.get_location();
}

bool Chief::get_chief_presence_place()const
{
	return chief_place.value_presence();
}

string Chief::get_chief_post()const
{
	return chief_post.get_post();
}

bool Chief::set_count_people(int count_people)
{
	try
	{
		if (count_people < 0) throw 1;
		c_count_people = count_people;
	}
	catch (int error)
	{
		error_count_people();
		return false;
	}
	return true;
}

void Chief::error_count_people()const
{
	cout << "Неверное число подчиненных" << endl;
}

void Chief::set_chief_post(string post)
{
	chief_post.set_post(post);
}

void Chief::set_chief_place(string location)
{
	chief_place.set_location(location);
}

void Chief::show()const
{
	Human::show();
	chief_place.show();
	chief_post.show();
	cout << "Число подчиненых:" << c_count_people << endl;
}

Chief::Chief() :Human()
{
	c_count_people = 1;
}

Chief::Chief(string name, short int age, int count_people, string location, string post) : Human(name, age), chief_place(location), chief_post(post)
{
	c_count_people = count_people;
}

Chief::~Chief()
{
}
