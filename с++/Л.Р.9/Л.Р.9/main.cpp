#include "Student.h"
#include "library.h"
#include <fstream>

int main()
{
	system("chcp 1251");
	system("cls");

	Student obj1("Tom", "Engineer", 1000);
	Student obj2;
	std::fstream file;
	int menu = 0;

	print_menu();
	menu = input_menu();

	if (menu_switch(obj1, obj2, file, menu) == false)
	{
		std::cout << "Ошибка работы." << std::endl;
		system("pause");
		return 1;
	}

	return 0;
}