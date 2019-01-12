#include "library.h"

const matrix* check_obj_ptr(const matrix *obj)
{
	cout << endl << "Передача объекта в функции по указателю";
	return obj;
}

const matrix& check_obj_link(const matrix &obj)
{
	cout << endl << "Передача объекта в функции по ccылке";
	return obj;
}

const matrix check_obj_value(const matrix obj)
{
	cout << endl << "Передача объекта в функции по значению";
	return obj;
}