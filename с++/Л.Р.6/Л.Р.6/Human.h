#pragma once

#include <string>
#include <iostream>

using namespace std;

class Human
{
public:
	void set_name(string name);
	bool set_age(short int age);

	virtual void show()const;

	string get_name()const;
	short int get_age()const;

	Human(string name, short int age);
	Human();
	virtual ~Human();

private:
	string h_name;
	short int h_age;

protected:
	void error_value()const;
};