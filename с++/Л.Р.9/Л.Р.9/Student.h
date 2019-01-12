#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <ios>

class Student
{
public:
	void set_name(std::string _name);
	void set_name_speciality(std::string _name);
	bool set_stipend(int stipend);

	std::string get_name()const;
	std::string get_name_speciality()const;
	int get_stipend()const;

	void show()const;

	friend void operator <<(std::fstream &stream, Student &obj);
	friend void operator >>(std::fstream &stream, Student &obj);

	void read_text_file_in_binary_mode(std::fstream &stream);
	void write_text_file_in_binary_mode(std::fstream &stream);

	void read_binary_file(std::fstream &stream);
	void write_binary_file(std::fstream &stream);

	Student(std::string name, std::string name_speciality, int stipend);
	Student();

	virtual ~Student();


private:
	std::string _name;
	std::string _name_speciality;
	int _stipend;

	void error_value()const;
};