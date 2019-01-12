#include "library.h"


void show_file(std::fstream &stream)
{
	std::string str;
	
	while (std::getline(stream, str))
	{
		std::cout.width(10);
		std::cout.fill('.');
		std::cout << str;
	}	
}

void show_reverse_file(std::fstream &stream)
{
	char temp;
	std::string str;

	while (std::getline(stream, str))
	{
		std::cout.width(10);
		std::cout.fill('.');

		for (int i = 0; i < str.size()/2; i++)
		{
			temp = str[i];
			str[i] = str[str.size() - 1 - i];
			str[str.size() - 1 - i] = temp;
		}

		std::cout << str;
	}
}

void print_menu()
{
	std::cout << "1.Записать объект в текстовый файл, открытого в обычном режиме" << std::endl;
	std::cout << "2.Прочитать данные в объект из текстового файл, открытого в обычном режиме" << std::endl;
	std::cout << "3.Записать объект в текстовый файл, открытого в бинарном режиме" << std::endl;
	std::cout << "4.Прочитать данные в объект из текстового файл, открытого в бинарном режиме" << std::endl;
	std::cout << "5.Записать объект в бинарный файл, открытого в бинарном режиме" << std::endl;
	std::cout << "6.Прочитать данные в объект из бинарного файл, открытого в бинарном режиме" << std::endl;
	std::cout << "7.Вывести данные из файла в прямом порядке" << std::endl;
	std::cout << "8.Вывести данные из файла в обратном порядке" << std::endl;
	std::cout << "9.Найти данные в файле и вывести если они есть" << std::endl;
	std::cout << "10.Удалить данные из файла и вывести их если они есть" << std::endl;
	std::cout << "11.Выйти" << std::endl << std::endl;
	std::cout << "Выберите действие:";

}

int input_menu()
{
	int menu = 0;
	do
	{
		std::cin >> menu;

		if (std::cin.fail() || menu < 1 || menu >11)
		{
			std::cout << "Ошибка. Повторите ввод:";
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		else
			break;

	} while (1);
	return menu;
}

std::string find_record(std::fstream &stream, std::string str)
{
	std::string temp;

	while (std::getline(stream, temp))
	{
		if (str == temp)
			return str;
	}

	return temp = "Нужный текст не найден.";
}

std::string delete_record(std::fstream &stream, std::string str)
{
	std::string str_delete;
	std::string temp_one;
	std::string temp_two;

	while (std::getline(stream, temp_one))
	{
		if (str == temp_one)
		{
			str_delete = temp_one;
			break;
		}			
		else
		{
			temp_two += temp_one;
			temp_two += '\n';
		}
	}

	if (str_delete.empty() != false)
		return str_delete = "Нужный текст для удаления не найден.";

	while (std::getline(stream, temp_one))
	{
		temp_two += temp_one;
		temp_two += '\n';
	}

	stream.close();
	stream.open("file.txt", std::ios_base::out);
	if (stream.is_open() == false) throw;

	stream << temp_two;
	return str_delete;
}

bool menu_switch(Student &obj1, Student &obj2, std::fstream &file, int menu)
{
	std::string str;

	switch (menu)
	{
	case 1:
		file.open("file.txt", std::ios_base::out);
		if (!file.is_open()) return false;

		file << obj1;
		file.close();
		return true;

	case 2:
		file.open("file.txt", std::ios_base::in);
		if (!file.is_open())	return false;

		file >> obj2;
		std::cout << std::endl;
		obj2.show();
		std::cout << std::endl;
		system("pause");
		file.close();
		return true;

	case 3:
		file.open("file.txt", std::ios_base::out, std::ios_base::binary);
		if (!file) return false;

		obj1.write_text_file_in_binary_mode(file);
		file.close();
		return true;

	case 4:
		file.open("file.txt", std::ios_base::in, std::ios_base::binary);
		if (!file) 	return false;

		obj2.read_text_file_in_binary_mode(file);
		obj2.show();
		std::cout << std::endl;
		system("pause");
		file.close();
		return true;

	case 5:
		file.open("file.bin", std::ios_base::out, std::ios_base::binary);
		if (!file) 	return false;

		obj1.write_binary_file(file);
		file.close();
		return true;

	case 6:
		file.open("file.bin", std::ios_base::in, std::ios_base::binary);
		if (!file) 	return false;

		obj2.read_binary_file(file);
		obj2.show();
		std::cout << std::endl;
		system("pause");
		file.close();
		return true;

	case 7:
		file.open("file.txt", std::ios_base::in);
		if (!file) 	return false;

		show_file(file);
		std::cout << std::endl;
		system("pause");
		file.close();
		return true;

	case 8:
		file.open("file.txt", std::ios_base::in);
		if (!file) 	return false;

		show_reverse_file(file);
		std::cout << std::endl;
		system("pause");
		file.close();
		return true;

	case 9:
		file.open("file.txt", std::ios_base::in);
		if (!file) 	return false;

		std::cout << "Введите запись которую хотите найти:";

		std::cin >> str;

		std::cout << std::endl;
		std::cout << find_record(file, str);
		std::cout << std::endl;
		system("pause");
		file.close();
		return true;

	case 10:
		file.open("file.txt", std::ios_base::in);
		if (!file) 	return false;

		std::cout << "Введите запись которую хотите удалить:";

		std::cin >> str;

		std::cout << std::endl;
		std::cout << delete_record(file, str);
		std::cout << std::endl;
		system("pause");
		file.close();
		return true;
	case 11:
		return true;
	}

}