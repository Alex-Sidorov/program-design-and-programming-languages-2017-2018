#include "library.h"

bool check_count_argc(int argc)
{
	return argc > 2 ? true : false;
}

FILE *open_file(char *name_file, char *mode_file)
{
	FILE *file;

	fopen_s(&file, name_file, mode_file);

	return file;
}

void close_file(FILE *file)
{
	fclose(file);
}

bool check_file(FILE *file)
{
	return file ? true : false;
}

void error_open_file(char *name_file)
{
	printf("������ �������� ����� %s.\n\n", name_file);
}

void error_count_argc()
{
	printf("\n\n�������� ���������� ���������� ��������� ������.\n\n");
}

void printf_complete()
{
	printf("������ ��������� ���������");
}

int find_bracket_in_string(FILE *original_file)
{
	char simvol = 0;
	stack *head = nullptr;

	while (simvol != '\n' && !feof(original_file))
	{
		fscanf_s(original_file, "%c", &simvol);

		if (simvol == '(')
		{
			head = create_stack(head, simvol);//���������� ������� � ����
			if (head == nullptr)
				return 1;
		}
		else if (simvol == ')')
		{
			if (check_simvol(head, simvol) == false)//�������� �� ���������� �������������� ������
			{
				while (check_stek(head) != false)//�������� ���� �� ������ ���� ����
					head = delete_elem_stack(head);//�������� ������� �����

				return 3;
			}
			else
				head = delete_elem_stack(head);//�������� ������� �����
		}
			
		else if (simvol == '[')
		{
			head = create_stack(head, simvol);//���������� ������� � ����
			if (head == nullptr)
				return 1;
		}
		else if (simvol == ']')
		{
			if (check_simvol(head, simvol) == false)//�������� �� ���������� �������������� ������
			{
				while (check_stek(head) != false)//�������� ���� �� ������ ���� ����
					head = delete_elem_stack(head);//�������� ������� �����

				return 3;
			}
			else
				head = delete_elem_stack(head);//�������� ������� �����
		}
		else if (simvol == '{')
		{
			head = create_stack(head, simvol);//���������� ������� � ����
			if (head == nullptr)
				return 1;
		}
		else if (simvol == '}')
		{
			if (check_simvol(head, simvol) == false)//�������� �� ���������� �������������� ������
			{
				while (check_stek(head) != false)//�������� ���� �� ������ ���� ����
					head = delete_elem_stack(head);//�������� ������� �����

				return 3;
			}
			else
				head = delete_elem_stack(head);//�������� ������� �����
		}
	}

	if (check_stek(head) != false)//�������� �� ������������� �����
	{
		while (check_stek(head) != false)//�������� ���� �� ������ ���� ���������� ����
			head = delete_elem_stack(head);//�������� ������� �����
		return 2;
	}

	return 0;
}

bool find_bracket_in_txt(FILE *original_file, FILE *new_file)
{
	int number_str = 0;
	int result = 0;

	while (!feof(original_file))
	{
		number_str++;
		result = find_bracket_in_string(original_file);//���������� ��������� ������ �� �������

		if (result == 0 && !feof(original_file))
			fprintf(new_file, "%d.���������\n", number_str);
		else if (result == 1)
			return false;
		else if (result == 2)
			fprintf(new_file, "%d.�� ���������\n", number_str);
		else if(result ==3)
		{
			fprintf(new_file, "%d.�� ���������\n", number_str);

			if (find_position(original_file) == false)//������� �� ��������� ������
				break;
		}
	}
	return true;
}

bool find_position(FILE *original_file)
{
	char simvol = 0;

	while (simvol != '\n' && !feof(original_file))
		fscanf_s(original_file, "%c", &simvol);

	if (feof(original_file))
		return false;
	else
		return true;
}

bool check_simvol(stack *head, char new_simvol)
{
	switch (new_simvol)
	{
	case ')':
		if (check_stek(head) == false || head->simvol != '(')
			return false;
		else
			return true;
	case ']':
		if (check_stek(head) == false || head->simvol != '[')
			return false;
		else
			return true;
	case '}':
		if (check_stek(head) == false || head->simvol != '{')
			return false;
		else
			return true;
	}
}