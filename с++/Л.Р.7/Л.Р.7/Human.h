#pragma once

#include <string>
#include <iostream>

using namespace std;

class Human
{
public:
	void set_name(string name);
	string get_name()const;

	virtual void show()const;
	virtual int count_project_in_year()const = 0;

	Human(string name);
	Human();
	virtual ~Human();

private:
	string h_name;
};
