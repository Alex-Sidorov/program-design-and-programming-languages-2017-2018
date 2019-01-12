#include "class.h"
#include "library.h"

int main()
{
	system("chcp 1251");
	system("cls");

	char *p = new char[8];
	char n[] = { 'n', 'l' };
	int k=strlen(n);
	matrix obj1(2,2);
	obj1.show();

	matrix obj2;
	obj2.show();

	matrix obj3 = obj1;
	obj3.show();

	obj1.read_value(1, 1);
	obj1.read_value(1, 5);

	complex value{ 1,1 };

	obj1.write_value(1, 1, value);
	obj1.show();

	obj1.write_value(1, 5, value);

	obj1.sort_down();
	obj1.show();

	cout << "\n\n";

	obj1.sort_up();
	obj1.show();

	cout << endl << &check_obj_link(obj1) << endl;
	cout << endl << &check_obj_value(obj1) << endl;
	cout << endl << check_obj_ptr(&obj1) << endl;
	
	system("pause");
	return 0;
}