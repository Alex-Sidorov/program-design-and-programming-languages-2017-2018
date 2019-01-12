#include "library.h"

void open_file(std::fstream &file, std::string name_file, unsigned mode)
{
	file.open(name_file, mode);
}

void close_file(std::fstream &file)
{
	file.close();
}

void write_in_file(std::fstream &file_one, std::fstream &file_two, std::vector<int> count_simvols, char simvol)
{
	if (file_one.fail())
		file_one.clear();

	file_one.seekg(0);

	std::string temp;

	for (int i = 0; std::getline(file_one, temp); i++)
		file_two << temp << " Количество " << simvol << ":" << count_simvols[i] << std::endl;
}

void show_in_cmd(int number_str, std::string str, int count_simvols, char simvol)
{
	std::cout << std::endl << number_str << '.' << str << " Количество " << simvol << ":" << count_simvols << std::endl;
}

void count_simvol_all_str(char simvol, std::fstream &file_one, std::vector<int> &count_simvols)
{
	std::string temp;

	for (int i = 0; std::getline(file_one, temp); i++)
	{
		count_simvols.push_back(count_simvol_one_str(temp, simvol));
		show_in_cmd(i + 1, temp, count_simvols[i], simvol);
	}
}

int count_simvol_one_str(std::string str, char simvol)
{
	int count = 0;
	std::string::iterator index = str.begin();
	std::string temp;

	if (str.empty() != true)
	{
		while (1)
		{
			index=std::find(index, str.end(), simvol);
			if (index >= str.end())
				break;
			index++;
			count++;
		}
	}
	return count;
}

char input_simvol()
{	
	char simvol;

	std::cout << "Введите символ для подсчета:";
	std::cin >> simvol;

	return simvol;
}

void print_complete_file(std::string name_file)
{
	std::cout << "Файл " << name_file << " открыт" << std::endl;
}

void print_error(std::string name_file)
{
	std::cout << "Файл " << name_file << " открыть не удалось" << std::endl;
}

void error_write()
{
	std::cout << "Запись не возможна " << std::endl;
}


