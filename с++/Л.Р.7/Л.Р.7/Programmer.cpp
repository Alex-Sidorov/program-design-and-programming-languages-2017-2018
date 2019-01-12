#include "Programmer.h"

int Programmer::count_project_in_year()const
{
	if (p_count_project == 0)
		return 0;
	else
		return p_expirience / p_count_project;
}

int Programmer::get_count_project()const
{
	return p_count_project;
}

int Programmer::get_expirience()const
{
	return p_expirience;
}

bool Programmer::set_count_project(int count_project)
{
	if (count_project < 0)
	{
		error_value();
		return false;
	}
	else
		p_count_project = count_project;

	return true;
}

bool Programmer::set_expirience(int expirience)
{
	if (expirience < 0)
	{
		error_value();
		return false;
	}
	else
		p_expirience = expirience;

	return true;
}

void Programmer::error_value()const
{
	cout << "Некоректное значение" << endl;
}

void Programmer::show()const
{
	Human::show();
	cout << "Количество законченных проектов:" << p_count_project << endl;
	cout << "Опыт работы(лет):" << p_expirience << endl;
}

Programmer::Programmer()
{
	p_expirience = 0;
	p_count_project = 0;
}

Programmer::Programmer(int count_project, int expirience, string name) : Human(name)
{
	if (expirience < 0)
	{
		error_value();
		p_expirience = 0;
	}
	else
		p_expirience = expirience;

	if (count_project < 0)
	{
		error_value();
		p_count_project = 0;
	}
	else
		p_count_project = count_project;

}

Programmer::~Programmer()
{
}