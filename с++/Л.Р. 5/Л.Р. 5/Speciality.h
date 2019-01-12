#pragma once

#include <string>
#include <iostream>

class Speciality
{
public:

	std::string get_name_speciality()const;
	void set_name_speciality(std::string name_speciality);

	virtual void show()const;

	Speciality();
	Speciality(std::string name_speciality);
	virtual ~Speciality();

private:
	std::string s_name_speciality;
};