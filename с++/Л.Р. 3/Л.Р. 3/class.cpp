#include "class.h"


matrix :: matrix(int row, int col)
{
	cout << endl << "Конструктор инициализации" << endl;
	
	try
	{
		mas = new complex*[col];
		for (int i = 0; i < col; i++)
		{
			mas[i] = new complex[row];
		}
	}
	catch(bad_alloc)
	{
		cout << endl << "память не выделилась" << endl;
	}
	
	m_col = col;
	m_row = row;
	input_mas();
}

matrix::matrix()
{
	cout << endl << "Конструктор по умолчанию" << endl;
	m_col = 0;
	m_row = 0;
	mas = nullptr;
}

void matrix::input_mas()
{
	srand(time(NULL));
	for (int i = 0; i < m_col; i++)
	{
		for (int j = 0; j < m_row; j++)
		{
			mas[i][j].real = rand_value();
			mas[i][j].image = rand_value();
		}
	}
}

int matrix::rand_value()const
{
	return rand() % 100 - 50;
}

int matrix::get_col()const
{
	return m_col;
}

int matrix::get_row()const
{
	return m_row;
}

void matrix::copy_matrix(const matrix &obj2)const
{
	for (int i = 0; i < m_col; i++)
	{
		for (int j = 0; j < m_row; j++)
		{
			mas[i][j] = obj2.mas[i][j];
		}
	}
}


matrix::matrix(const matrix &obj)
{
	cout << endl << "Конструктор копирования" << endl;

	this->m_col = obj.get_col();
	this->m_row = obj.get_row();

	try
	{
		this->mas = new complex*[m_col];
		for (int i = 0; i < m_col; i++)
		{
			mas[i] = new complex[m_row];
		}
	}
	catch (bad_alloc)
	{
		cout << endl << "память не выделилась" << endl;
	}

	copy_matrix(obj);
}

matrix :: ~matrix()
{
	cout << endl << "Деструктор" << endl;
	for (int i = 0; i < m_col; i++)
	{
		delete mas[i];
	}
	delete [] mas;
}

double matrix::module_value(complex value)const
{
	return sqrt(value.image * value.image + value.real + value.real);
}

bool matrix::compare_value(complex value1, complex value2)const
{
	if (module_value(value1) <= module_value(value2))
		return true;
	else
		return false;
}

void matrix::read_value(const int index_col, const int index_row)const
{
	if (index_col >= 0 && index_col < m_col && index_row >= 0 && index_row < m_row)
	{
		if (mas[index_col][index_row].image < 0)
			cout << endl << mas[index_col][index_row].real << mas[index_col][index_row].image << "i ";
		else
			cout << endl << mas[index_col][index_row].real << '+' << mas[index_col][index_row].image << "i ";
	}
	else
		error_read_write_value();
}

void matrix::write_value(const int index_col, const int index_row, complex value)const
{
	if (index_col >= 0 && index_col < m_col && index_row >= 0 && index_row < m_row)
	{
		mas[index_col][index_row].image = value.image;
		mas[index_col][index_row].real = value.real;
	}
	else
		error_read_write_value();
}

void matrix::error_show()const
{
	cout << endl << "элементов нет" << endl;
}

void matrix::error_read_write_value()const
{
	cout << endl << "элемента нет" << endl;
}

void matrix::show()const
{
	if (m_col == 0 && m_row == 0)
		error_show();

	for (int i = 0; i < m_col; i++)
	{
		cout << endl;

		for (int j = 0; j < m_row; j++)
		{
			if (mas[i][j].image < 0)
				cout << mas[i][j].real << mas[i][j].image << "i ";
			else
				cout << mas[i][j].real << '+' << mas[i][j].image << "i ";
		}

			
	}
}

void matrix::sort_up()const
{
	complex temp;
	int col1 = 0;
	int row1 = 0;
	int col2 = 0;
	int row2 = 0;

	for (int i = 0; i < m_col*m_row; i++)
	{
		row1 = 0;
		row2 = row1 + 1;
		col1 = 0;
		col2 = 0;

		while (1)
		{		
			if (compare_value(mas[col1][row1], mas[col2][row2]) == false)
			{
				temp = mas[col1][row1];
				mas[col1][row1] = mas[col2][row2];
				mas[col2][row2] = temp;
			}

			if (row1 + 1 == m_row)
			{
				col1++;
				row1 = 0;
			}
			else
				row1++;

			if (row2 + 1 == m_row)
			{
				col2++;
				row2 = 0;
			}
			else
				row2++;

			if (col2 >= m_col)
				break;

		}
	}
}

void matrix::sort_down()const
{
	complex temp;
	int col1 = 0;
	int row1 = 0;
	int col2 = 0;
	int row2 = 0;

	for (int i = 0; i < m_col*m_row; i++)
	{
		row1 = 0;
		row2 = row1 + 1;
		col1 = 0;
		col2 = 0;

		while (1)
		{
			if (compare_value(mas[col1][row1], mas[col2][row2]) == true)
			{
				temp = mas[col1][row1];
				mas[col1][row1] = mas[col2][row2];
				mas[col2][row2] = temp;
			}

			if (row1 + 1 == m_row)
			{
				col1++;
				row1 = 0;
			}
			else
				row1++;

			if (row2 + 1 == m_row)
			{
				col2++;
				row2 = 0;
			}
			else
				row2++;

			if (col2 >= m_col)
				break;

		}
	}
}