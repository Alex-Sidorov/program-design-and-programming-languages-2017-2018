#include "Worker.h"

string Worker::get_location_worker()const
{
	return worker_place.get_location();
}

bool Worker::value_presence_place_worker()const
{
	return worker_place.value_presence();
}

short int Worker::get_experience()const
{
	return w_experience;
}

string Worker::get_chief_name()const
{
	return chief_worker.get_name();
}

int Worker::get_chief_age()const
{
	return chief_worker.get_age();
}

int Worker::get_chief_count_people()const
{
	return chief_worker.get_count_people();
}

string Worker::get_chief_location_place()const
{
	return chief_worker.get_chief_location_place();
}

bool Worker::get_chief_presence_place()const
{
	return chief_worker.get_chief_presence_place();
}

string Worker::get_chief_post()const
{
	return chief_worker.get_chief_post();
}

string Worker::get_name_departament_worker()const
{
	return worker_department.get_name_departament();
}

int  Worker::get_worker_departament_count_workers()const
{
	return worker_department.get_chief_departament_count_people();
}

void Worker::set_name_departament_worker(string name_departament)
{
	worker_department.set_name_departament(name_departament);
}

bool Worker::set_worker_departament_count_workers(int count_workers)
{
	chief_worker.set_count_people(count_workers);
	worker_department.set_count_workers(count_workers);
	return worker_department.set_chief_departament_count_people(count_workers);
}

void Worker::set_chief_name(string chief_name)
{
	worker_department.set_chief_departament_name(chief_name);
	chief_worker.set_name(chief_name);
}

bool Worker::set_chief_age(int age)
{
	chief_worker.set_age(age);
	return worker_department.set_chief_departament_age(age);
}

bool Worker::set_chief_count_people(int count_people)
{
	worker_department.set_chief_departament_count_people(count_people);
	worker_department.set_count_workers(count_people);
	return chief_worker.set_count_people(count_people);
}

void Worker::set_chief_location_place(string chief_place)
{
	worker_department.set_chief_departament_place(chief_place);
	chief_worker.set_chief_place(chief_place);
}

void Worker::set_chief_post(string chief_post)
{
	worker_department.set_chief_departament_post(chief_post);
	chief_worker.set_chief_post(chief_post);
}

void Worker::set_location_worker(string location)
{
	worker_place.set_location(location);
}

bool Worker::set_experience(short int experience)
{
	try
	{
		if (experience < 0) throw 1;
		w_experience = experience;
	}
	catch (int error)
	{
		error_value();
		return false;
	}
	return true;
	
}

void Worker::show()const
{
	cout << endl << "Работник:" << endl << endl;
	Human::show();
	Speciality::show();
	cout << "Опыт:" << w_experience << endl;
	Post::show();

	worker_place.show();

	cout << endl << "Начальник:" << endl << endl;
	chief_worker.show();
	cout << endl << "Отдел:" << worker_department.get_name_departament() << endl << endl;
	worker_department.show();

}

Worker::Worker(string name, short int experience, short int age, string post, string name_speciality, string location, string name_chief, int count_people, string location_chief, short int age_chief, string post_chief, string name_departament) 
				:Human(name, age), Post(post), Speciality(name_speciality),chief_worker(name_chief, age_chief, count_people, location_chief, post_chief), worker_place(location), worker_department(name_departament,count_people, name_chief, age_chief, count_people, post_chief, location_chief)
{
	w_experience = experience;
}

void Worker::error_value()const
{
	cout << "Некоректный Значение" << endl;
}

Worker::Worker()
{
	w_experience = 0;
}

Worker::~Worker()
{
}