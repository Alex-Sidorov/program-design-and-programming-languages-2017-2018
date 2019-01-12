#pragma once

#include <iostream>
#include <string>

using namespace std;

class detail;

class control
{
public:
	control();
	void change_mass(detail &obj, int mass);
	void input_mass(detail &obj);
};

class detail
{
	static int d_id;
	int d_unique_id;
	string d_name;
	int d_mass;
	

public:
	detail();
	detail(int id, string name, int);
	~detail();
	void input_id_and_name();
	friend void show(detail &obj);
	friend control;
};


