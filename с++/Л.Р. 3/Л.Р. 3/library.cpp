#include "library.h"

const matrix* check_obj_ptr(const matrix *obj)
{
	cout << endl << "�������� ������� � ������� �� ���������";
	return obj;
}

const matrix& check_obj_link(const matrix &obj)
{
	cout << endl << "�������� ������� � ������� �� cc����";
	return obj;
}

const matrix check_obj_value(const matrix obj)
{
	cout << endl << "�������� ������� � ������� �� ��������";
	return obj;
}