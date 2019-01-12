#include "sort.h"
#include "other functions.h"

int main()
{
	srand((unsigned int)time(NULL));
	system("chcp 1251");
	system("cls");

	const int size = 20;

	int mas_int[size];
	rand_mas(mas_int, size);

	double mas_double[size];
	rand_mas(mas_double, size);

	char mas_char[size];
	rand_mas(mas_char, size);

	cout << "int" << endl << endl;
	review_mas(mas_int, size);
	cout << endl;

	insert_sort_up(mas_int, size);
	review_mas(mas_int, size);
	cout << endl;

	selection_sort_down(mas_int, size);
	review_mas(mas_int, size);
	cout << endl << endl;

	cout << "double" << endl << endl;
	review_mas(mas_double, size);
	cout << endl;

	qsort_up(mas_double, 0, size-1);
	review_mas(mas_double, size);
	cout << endl;

	Shell_sort_down(mas_double, size);
	review_mas(mas_double, size);
	cout << endl << endl;

	cout << "char" << endl << endl;
	review_mas(mas_char, size);
	cout << endl;

	booble_sort_up(mas_char,size);
	review_mas(mas_char, size);
	cout << endl;

	Bender_sort_down(mas_char, size);
	review_mas(mas_char, size);
	cout << endl << endl;

	system("pause");
}
