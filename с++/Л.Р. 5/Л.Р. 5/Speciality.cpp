#include "Speciality.h"

std::string Speciality::get_name_speciality()const
{
	return s_name_speciality;
}

void Speciality::set_name_speciality(std::string name_speciality)
{
	s_name_speciality = name_speciality;
}

void Speciality::show()const
{
	std::cout << "Специальность:" << s_name_speciality << std::endl;
}

Speciality::Speciality()
{
	s_name_speciality = "Название специальности";
}

Speciality::Speciality(std::string name_speciality)
{
	s_name_speciality = name_speciality;
}

Speciality::~Speciality()
{

}