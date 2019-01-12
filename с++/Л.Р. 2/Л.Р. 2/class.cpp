#include "class.h"
#include "library.h"

int detail::d_id = 0;

detail::detail()
{
    cout << endl << "Конструктор по умолчанию для класса detail" << endl;
	d_unique_id = d_id + 1;
	d_name = "obj";
	d_mass = 0;
	d_id = d_unique_id;
}

detail::detail(int id, string name, int mass)
{
    cout << endl << "Конструктор инициализации" << endl;
	d_unique_id = id;
	d_name = name;
	d_mass = mass;
	d_id = d_unique_id;
}

detail::~detail() { cout << endl << "Деструктор " << d_name << endl; }

void show(detail &obj)
{
	cout << endl << "Id детали:" << obj.d_unique_id << endl;
	cout << "Наименование детали:" << obj.d_name << endl;
	cout << "Вес детали:" << obj.d_mass << endl << endl;
}

control::control()
{
	cout << endl << "Конструктор по умолчанию для класса control" << endl;
}

void control:: change_mass(detail &obj, int mass)
{
    cout << endl << "Изменение веса " << obj.d_name << endl;
	obj.d_mass = mass;
}

void detail::input_id_and_name()
{
	cout << endl << "Введите id:";
	input_int_value(d_unique_id);

	d_id = d_unique_id;

	cout << endl << "Введите name:";
	input_string_value(d_name);
}


void control::input_mass(detail &obj)
{
	cout << endl << "Введите массу:";
	input_int_value(obj.d_mass);
}