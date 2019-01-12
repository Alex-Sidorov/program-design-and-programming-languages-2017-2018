#include "library.h"

int main()
{
	system("chcp 1251");
	system("cls");

	std::string name_file_one("file_one.txt");
	std::string name_file_two("file_two.txt");
	std::fstream file_one;
	std::fstream file_two;
	std::vector<int> count_simvols;

	open_file(file_one, name_file_one, std::ios_base::in);
	if (file_one.is_open() == false)
	{
		print_error(name_file_one);
		system("pause");
		return 1;
	}

	print_complete_file(name_file_one);

	char simvol = input_simvol();

	count_simvol_all_str(simvol, file_one, count_simvols);

	open_file(file_two, name_file_two, std::ios_base::out);

	write_in_file(file_one, file_two, count_simvols, simvol);
	if (file_two.is_open() == false)
	{
		print_error(name_file_two);
		error_write();
		system("pause");
		return 1;
	}

	print_complete_file(name_file_two);

	close_file(file_one);
	close_file(file_two);

	system("pause");
	return 0;
}