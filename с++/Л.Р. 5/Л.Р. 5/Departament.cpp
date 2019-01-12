#include "Departament.h"

int Departament::get_chief_departament_count_people()const
{
	return d_chief_departement.get_count_people();
}

int Departament::get_count_workers()const
{
	return d_count_workers;
}

string Departament::get_chief_departament_post()const
{
	return d_chief_departement.get_chief_post();
}

string Departament::get_chief_name()const
{
	return d_chief_departement.get_name();
}

string Departament::get_name_departament()const
{
	return d_name_departament;
}

string Departament::get_chief_departament_location_place()const
{
	return d_chief_departement.get_chief_location_place();
}

bool Departament::get_chief_departament_presence_place()const
{
	return d_chief_departement.get_chief_presence_place();
}

int Departament::get_chief_age()const
{
	return d_chief_departement.get_age();
}

void Departament::set_name_departament(string name_departament)
{
	d_name_departament = name_departament;
}

bool Departament::set_count_workers(int count_workers)
{
	try
	{
		if (count_workers < 1) throw 1;
		d_count_workers = count_workers;
	}
	catch (int error)
	{	
		error_count_workers();
		return false;
	}
	return true;
}

void Departament::error_count_workers()const
{
	cout << "Неверное число работников" << endl;
}

bool Departament::set_chief_departament_count_people(int count_people)
{
	return d_chief_departement.set_count_people(count_people);
}

void Departament::set_chief_departament_post(string post)
{
	d_chief_departement.set_chief_post(post);
}

void Departament::set_chief_departament_place(string location)
{
	d_chief_departement.set_chief_place(location);
}

void Departament::set_chief_departament_name(string name)
{
	d_chief_departement.set_name(name);
}

bool Departament::set_chief_departament_age(int age)
{
	return d_chief_departement.set_age(age);
}

void Departament::show()const
{
	cout  << "Начальник отдела:" << endl << endl;
	d_chief_departement.show();
	cout << endl << "Число работников в отделе:" << d_count_workers << endl;
}

Departament::Departament()
{
	d_name_departament = "Название отдела неизвестно";
	d_count_workers = 1;
}

Departament::Departament(string name_departament, int count_workers, string name_chief, short int age_chief, int chief_count_people, string post_chief, string place_chief)
						: d_chief_departement(name_chief, age_chief, chief_count_people, place_chief, post_chief)
{
	d_name_departament = name_departament;
	d_count_workers = count_workers;
}

Departament::~Departament()
{
}