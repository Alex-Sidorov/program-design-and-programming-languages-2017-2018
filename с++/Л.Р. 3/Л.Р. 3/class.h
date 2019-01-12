#pragma once

#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

struct complex
{
	int real;
	int image;
};

class matrix
{
private:
	complex **mas;
	int m_row;
	int m_col;
	void input_mas();
	int rand_value()const;
	double module_value(complex value)const;
	bool compare_value(complex value1, complex value2)const;
	void copy_matrix(const matrix &obj2)const;
	void error_show()const;
	void error_read_write_value()const;

public:
	matrix(const int row, const int col);
	matrix();
	matrix(const matrix &obj);
	~matrix();
	int get_row()const;
	int get_col()const;
	void read_value(const int index_col, const int index_row)const;
	void write_value(const int index_col, const int index_row, complex value)const;
	void show()const;
	void sort_up()const;
	void sort_down()const;
};
