#include "Writer.h"

int Writer::count_project_in_year()const
{
	if (w_count_project == 0)
		return 0;
	else
		return w_expirience / w_count_project;
}

int Writer::get_count_project()const
{
	return w_count_project;
}

int Writer::get_expirience()const
{
	return w_expirience;
}

bool Writer::set_count_project(int count_project)
{
	if (count_project < 0)
	{
		error_value();
		return false;
	}
	else
		w_count_project = count_project;

	return true;
}

bool Writer::set_expirience(int expirience)
{
	if (expirience < 0)
	{
		error_value();
		return false;
	}
	else
		w_expirience = expirience;

	return true;
}

void Writer::error_value()const
{
	cout << "Некоректное значение" << endl;
}

void Writer::show()const
{
	Human::show();
	cout << "Количество законченных проектов:" << w_count_project << endl;
	cout << "Опыт работы(лет):" << w_expirience << endl;
}

Writer::Writer()
{
	w_expirience = 0;
	w_count_project = 0;
}

Writer::Writer(int count_project, int expirience, string name) : Human(name)
{
	if (expirience < 0)
	{
		error_value();
		w_expirience = 0;
	}
	else
		w_expirience = expirience;

	if (count_project < 0)
	{
		error_value();
		w_count_project = 0;
	}
	else
		w_count_project = count_project;
	
}

Writer::~Writer()
{
}