#include "Student.h"

void Student::set_name(std::string name)
{
	_name = name;
}

void Student::set_name_speciality(std::string name)
{
	_name_speciality = name;
}

bool Student::set_stipend(int stipend)
{
	if (stipend >= 0)
	{
		_stipend = stipend;
		return true;
	}
	else
	{
		error_value();
		return false;
	}
}

void Student::error_value()const
{
	std::cout << "Некоректное значение.";
}

std::string Student::get_name()const
{
	return _name;
}

std::string Student::get_name_speciality()const
{
	return _name_speciality;
}

int Student::get_stipend()const
{
	return _stipend;
}

void operator <<(std::fstream &stream, Student &obj)
{
	stream << obj._name << std::endl << obj._name_speciality << std::endl << obj._stipend;
}

void operator >>(std::fstream &stream, Student &obj)
{
	std::getline(stream, obj._name);
	std::getline(stream, obj._name_speciality);
	stream >> obj._stipend;
}

void Student::read_text_file_in_binary_mode(std::fstream &stream)
{
	int step = 0;
	char simvol;

	_name = "";
	while (1)
	{
		simvol = stream.get();
		if (simvol == '\n')
			break;
		_name.push_back(simvol);
		step++;
	}

	_name_speciality = "";
	step = 0;
	while (1)
	{
		simvol = stream.get();
		if (simvol == '\n')
			break;
		_name_speciality.push_back(simvol);
		step++;
	}

	stream.read((char*)&_stipend, sizeof(int));
}

void Student::write_text_file_in_binary_mode(std::fstream &stream)
{
	for (int i = 0; i < _name.size(); i++)
	{
		stream.put(_name[i]);
	}

	stream.put('\n');
	for (int i = 0; i < _name_speciality.size(); i++)
	{
		stream.put(_name_speciality[i]);
	}

	stream.put('\n');
	//stream.write((char*)&_stipend, sizeof(int));	
	stream.write(reinterpret_cast<char*>(&_stipend), sizeof(int));
}

void Student::read_binary_file(std::fstream &stream)
{
	size_t size_str = 0;
	char simvol = 0;

	stream.read((char*)&size_str, sizeof(size_t));
	
	_name = "";

	for (int i = 0; i < size_str; i++)
	{
		stream.read((char*)&simvol, sizeof(char));
		_name.push_back(simvol);
	}

	stream.read((char*)&size_str, sizeof(size_t));

	_name_speciality = "";

	for (int i = 0; i < size_str; i++)
	{
		stream.read((char*)&simvol, sizeof(char));
		_name_speciality.push_back(simvol);
	}

	stream.read((char*)&_stipend, sizeof(int));
}

void Student::show()const
{
	std::cout<<"Имя:" << _name << std::endl;
	std::cout << "Название специальности:" << _name_speciality << std::endl;
	std::cout << "Размер стипендии:" << _stipend << std::endl;
}

void Student::write_binary_file(std::fstream &stream)
{
	size_t size = _name.size() + 1;
	stream.write((char*)&size, sizeof(size_t));
	stream.write(_name.c_str(), sizeof(size));
	
	size = _name_speciality.size() + 1;
	stream.write((char*)&size, sizeof(size_t));

	for (int i = 0; i < size; i++)
		stream.write((char*)&_name_speciality[i], sizeof(char));

	stream.write((char*)&_stipend, sizeof(int));
}

Student::Student()
{
	_name = "Имя";
	_name_speciality = "Название специальности";
	_stipend = 0;
}

Student::Student(std::string name, std::string name_speciality, int stipend)
{
	_name = name;
	_name_speciality = name_speciality;

	if (stipend >= 0)
		_stipend = stipend;
	else
	{
		error_value();
		_stipend = 0;
	}
}

Student::~Student()
{

}