#include "class.h"
#include "library.h"

int detail::d_id = 0;

detail::detail()
{
    cout << endl << "����������� �� ��������� ��� ������ detail" << endl;
	d_unique_id = d_id + 1;
	d_name = "obj";
	d_mass = 0;
	d_id = d_unique_id;
}

detail::detail(int id, string name, int mass)
{
    cout << endl << "����������� �������������" << endl;
	d_unique_id = id;
	d_name = name;
	d_mass = mass;
	d_id = d_unique_id;
}

detail::~detail() { cout << endl << "���������� " << d_name << endl; }

void show(detail &obj)
{
	cout << endl << "Id ������:" << obj.d_unique_id << endl;
	cout << "������������ ������:" << obj.d_name << endl;
	cout << "��� ������:" << obj.d_mass << endl << endl;
}

control::control()
{
	cout << endl << "����������� �� ��������� ��� ������ control" << endl;
}

void control:: change_mass(detail &obj, int mass)
{
    cout << endl << "��������� ���� " << obj.d_name << endl;
	obj.d_mass = mass;
}

void detail::input_id_and_name()
{
	cout << endl << "������� id:";
	input_int_value(d_unique_id);

	d_id = d_unique_id;

	cout << endl << "������� name:";
	input_string_value(d_name);
}


void control::input_mass(detail &obj)
{
	cout << endl << "������� �����:";
	input_int_value(obj.d_mass);
}