#include "library.h"

int main(int argc, char *argv[])
{
	system("chcp 1251");
	system("cls");

	if (check_count_argc(argc) == false)//�������� �� ���������� ���������� ��������� ������
	{
		error_count_argc();
		return 1;
	}

	FILE *original_file;
	FILE *new_file;

	original_file = open_file(argv[1], "r");//�������� �����
	if (check_file(original_file) == false)//�������� �������� �� ����
	{
		error_open_file(argv[1]);
		return 2;
	}

	new_file = open_file(argv[2], "w");//�������� �����
	if (check_file(new_file) == false)//�������� �������� �� ����
	{
		error_open_file(argv[2]);
		close_file(original_file);
		return 3;
	}

	if (find_bracket_in_txt(original_file, new_file) == false)//������� ��������� ����� ������
	{
		error_remember();
		return 4;
	}

	close_file(original_file);//�������� �����
	close_file(new_file);//�������� �����

	printf_complete();

	return 0;
}