#pragma once

#include "Complex.h"
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

class Massiv
{
private:
	Complex **mas;
	int m_row;
	int m_col;

	void input_mas()const;
	int rand_value()const;
	double module_value(Complex value)const;
	bool compare_value(Complex value1, Complex value2)const;
	void copy_Massiv(const Massiv &obj2)const;
	void error_show()const;
	void error_alloc()const;
	void error_index()const;
	void error_objs()const;
	double summa()const;
	Complex** alloc_for_new_matrix(int row, int col)const;
	void alloc_for_matrix(int row, int col);

public:
	Massiv(int row = 1, int col = 1);
	Massiv(const Massiv &obj);
	Massiv(Complex **new_mas, int row, int col);
	~Massiv();
	void show()const;
	int get_row()const;
	int get_col()const;

	Massiv& operator = (const Massiv &obj);
	bool operator == (const Massiv &obj);
	bool operator != (const Massiv &obj);
	Complex* operator [](int index);
	void operator ()(int row, int col, Complex value);
	Massiv operator ++ (int value);
	Massiv& operator ++ ();
	Massiv operator + (const Massiv &obj);
	bool operator > (const Massiv &obj)const;
	bool operator < (const Massiv &obj)const;
	void* operator new(size_t count);
	void* operator new[](size_t count);
	void operator delete(void *pointer);

	friend const Massiv& operator -- (const Massiv &obj);
	friend Massiv operator -- (const Massiv &obj, int value);
	friend Massiv operator - (Massiv &obj, Complex value);
	friend Massiv operator - (Complex value, Massiv &obj) {}
		friend ostream& operator << (ostream &s, const Massiv &obj);

	operator int()const;
	operator double()const;
	operator Complex()const;
};