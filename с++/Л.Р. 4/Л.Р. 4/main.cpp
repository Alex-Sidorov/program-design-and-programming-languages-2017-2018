#include "Massiv.h"

int main()
{
	srand(time(NULL));
	system("chcp 1251");
	system("cls");

	Massiv obj(4, 4);
	obj.show();

	cout << endl;
	--obj;
	obj.show();

	cout << endl;
	(obj--).show();
	obj.show();

	++obj;
	obj.show();

	cout << endl;
	(obj++).show();
	obj.show();

	cout << endl;
	Massiv obj3(5, 5);
	obj3.show();

	cout << endl;
	obj = obj3;
	obj.show();

	cout << endl;
	if(obj==obj3)
		obj.show();

	cout << endl;
	if (obj != obj3)
		obj.show();

	cout << endl;
	cout << obj[1][2];

	Complex value{ 1,1 };
	obj(1, 2, value);
	cout << endl;
	cout << obj[1][2];

	Massiv obj2;

	cout << endl;
	obj2 = obj + obj3;
	obj2.show();
	
	cout << endl;
	if(obj>obj2)
		obj.show();
	else if(obj<obj2)
		obj2.show();

	
	/*Massiv *obj4 = new Massiv(2, 2);*/
	Massiv *obj4 = new Massiv[3];
	obj4->show();
	delete obj4;

	cout << endl;
	obj2.show();

	cout << endl;
	obj.show();

	obj2 = obj - value;
	cout << endl;
	obj2.show();
	
	cout << endl << endl << (Complex)obj << endl;
	cout << (double)obj << endl;
	cout << (int)obj << endl;
	
	obj.operator int();
	cout << endl;
	system("pause");
	return 0;
}