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

		if (cin.fail() || value < 0)//true когда не верный тип
		{
			cout << "Ошибка. Повторите ввод:";
			cin.clear();
			while (cin.get() != '\n');
			//cin.ignore('\n');//очищает поток от оставшихся символов

		}
		else
			break;

	} while (1);
}