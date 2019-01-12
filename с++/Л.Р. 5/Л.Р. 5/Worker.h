#pragma once

#include "Human.h"
#include "Departament.h"
#include "Place_of_work.h"
#include "Post.h"
#include "Speciality.h"
#include "Ñhief.h"

class Worker : public Human, public Post, public Speciality
{
public:

	short int get_experience()const;

	bool value_presence_place_worker()const;
	std::string get_location_worker()const;

	int get_chief_count_people()const;
	string get_chief_post()const;
	bool get_chief_presence_place()const;
	string get_chief_location_place()const;

	string get_chief_name()const;
	int get_chief_age()const;

	string get_name_departament_worker()const;
	int get_worker_departament_count_workers()const;

	void set_name_departament_worker(string name_departament);
	bool set_worker_departament_count_workers(int count_workers);

	void set_chief_name(string chief_name);
	bool set_chief_age(int chief_age);

	bool set_chief_count_people(int count_people);
	void set_chief_location_place(string chief_place);
	void set_chief_post(string chief_post);

	bool set_experience(short int experience);
	void set_location_worker(string location);

	void show()const;

	Worker();
	Worker(string name, short int experience, short int age, string post, string name_speciality, string location, string name_chief, int count_people, string location_chief, short int age_chief, string post_chief, string name_departament);
	virtual ~Worker();

private:
	short int w_experience;
	Place_of_work worker_place;
	Chief chief_worker;
	Departament worker_department;

	void error_value()const;
};