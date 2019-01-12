#include "Place_of_work.h"

std::string Place_of_work::get_location()const
{
	return pow_location;
}

bool Place_of_work::value_presence()const
{
	return pow_presence;
}

void Place_of_work::show()const
{
	if (pow_presence == true)
		std::cout << "������� �����:" << pow_location << std::endl;
	else
		std::cout << "�������� ����� ���" << std::endl;
}

void Place_of_work::set_location(std::string location)
{
	if (location == "���" || location == "����" || location == "����" || location == "���" || location == "�����������" || location == "�����������" || location == "����������")
		pow_presence = false;
	else
		pow_presence = true;

	pow_location = location;
}

Place_of_work::Place_of_work(std::string location)
{
	pow_presence = true;
	pow_location = location;
}

Place_of_work::Place_of_work()
{
	pow_presence = false;
}

Place_of_work::~Place_of_work()
{
}