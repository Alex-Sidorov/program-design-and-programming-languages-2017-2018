#include "library.h"


void input_string_value(string &str)
{
	cin.sync();
	cin >> str;
}

void input_int_value(int &value)
{
	do
	{
		cin >> value;

		if (cin.fail() || value < 0)//true ����� �� ������ ���
		{
			cout << "������. ��������� ����:";
			cin.clear();
			while (cin.get() != '\n');
			//cin.ignore('\n');//������� ����� �� ���������� ��������

		}
		else
			break;

	} while (1);
}