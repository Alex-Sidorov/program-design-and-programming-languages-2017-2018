#include "library.h"

int main(int argc, char *argv[])
{
	system("chcp 1251");
	system("cls");

	if (check_count_argc(argc) == false)//проверка на количество аргументов командной строки
	{
		error_count_argc();
		return 1;
	}

	FILE *original_file;
	FILE *new_file;

	original_file = open_file(argv[1], "r");//открытие файла
	if (check_file(original_file) == false)//проверка открылся ли файл
	{
		error_open_file(argv[1]);
		return 2;
	}

	new_file = open_file(argv[2], "w");//открытие файла
	if (check_file(new_file) == false)//проверка открылся ли файл
	{
		error_open_file(argv[2]);
		close_file(original_file);
		return 3;
	}

	if (find_bracket_in_txt(original_file, new_file) == false)//функция обработки всего текста
	{
		error_remember();
		return 4;
	}

	close_file(original_file);//закрытие файла
	close_file(new_file);//закрытие файла

	printf_complete();

	return 0;
}