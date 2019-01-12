#pragma once

#include "Ñhief.h"
#include <iostream>
#include <string>

using namespace std;

class Departament
{
public:
	int get_count_workers()const;
	int get_chief_departament_count_people()const;
	string get_chief_departament_post()const;
	string get_chief_name()const;
	string get_name_departament()const;
	int get_chief_age()const;
	bool get_chief_departament_presence_place()const;
	string get_chief_departament_location_place()const;

	void set_name_departament(string name_departement);
	bool set_count_workers(int count_workers);
	bool set_chief_departament_count_people(int count_people);
	void set_chief_departament_post(string post);
	void set_chief_departament_place(string location);
	void set_chief_departament_name(string name);
	bool set_chief_departament_age(int age);

	virtual void show()const;

	Departament();
	Departament(string d_name_departament, int count_workers, string name_chief, short int age_chief, int chief_count_people, string post_chief, string place_chief);
	virtual ~Departament();

private:
	string d_name_departament;
	int d_count_workers;
	Chief d_chief_departement;

	void error_count_workers()const;
};