#include "Massiv.h"

void Massiv:: alloc_for_matrix(int row, int col)
{
	mas = alloc_for_new_matrix(row, col);
}

Complex** Massiv::alloc_for_new_matrix(int row, int col)const
{
	Complex **new_mas = nullptr;

	try
	{
		new_mas = new Complex*[col];
		for (int i = 0; i < col; i++)
		{
			new_mas[i] = new Complex[row];
		}
	}
	catch (bad_alloc)
	{
		error_alloc();
	}
	return new_mas;

}

Massiv::Massiv(int row, int col)
{
	cout << endl << "Конструктор инициализации" << endl;

	alloc_for_matrix(row, col);

	m_col = col;
	m_row = row;
	input_mas();
}

Massiv::Massiv(Complex **new_mas, int row, int col)
{
	mas = new_mas;
	m_col = col;
	m_row = row;
}

void Massiv::input_mas()const
{
	for (int i = 0; i < m_col; i++)
	{
		for (int j = 0; j < m_row; j++)
		{
			mas[i][j].real = rand_value();
			mas[i][j].image = rand_value();
		}
	}
}

int Massiv::rand_value()const
{
	return rand() % 100 - 50;
}

int Massiv::get_row()const
{
	return m_row;
}

int Massiv::get_col()const
{
	return m_col;
}

void Massiv::copy_Massiv(const Massiv &obj2)const
{
	for (int i = 0; i < m_col; i++)
	{
		for (int j = 0; j < m_row; j++)
		{
			mas[i][j] = obj2.mas[i][j];
		}
	}
}


Massiv::Massiv(const Massiv &obj)
{
	cout << endl << "Конструктор копирования" << endl;

	m_col = obj.get_col();
	m_row = obj.get_row();

	alloc_for_matrix(m_row, m_col);

}

void Massiv::error_alloc()const
{
	cout << endl << "память не выделилась" << endl;
}

Massiv :: ~Massiv()
{
	cout << endl << "Деструктор" << endl;
	delete[] mas;
}

double Massiv::module_value(Complex value)const
{
	return sqrt(value.image * value.image + value.real * value.real);
}

bool Massiv::compare_value(Complex value1, Complex value2)const
{
	if (module_value(value1) <= module_value(value2))
		return true;
	else
		return false;
}

void Massiv::error_show()const
{
	cout << endl << "элементов нет" << endl;
}

void Massiv::error_index()const
{
	cout << endl << "элемента нет" << endl;
}

void Massiv::error_objs()const
{
	cout << endl << "объекты не равны" << endl;
}

void Massiv::show()const
{
	if (m_col == 0 && m_row == 0)
		error_show();

	for (int i = 0; i < m_col; i++)
	{
		cout << endl;

		for (int j = 0; j < m_row; j++)
		{
			cout << mas[i][j];
		}
	}
}

Massiv& Massiv:: operator=(const Massiv &obj)
{
	if (*this == obj)
		return *this;

	this->~Massiv();
	m_row = obj.get_row();
	m_col = obj.get_col();

	alloc_for_matrix(m_row, m_col);

	this->copy_Massiv(obj);
	return *this;
}

bool Massiv:: operator == (const Massiv &obj)
{
	if (this == &obj)
		return true;
	else
		return false;
}

bool Massiv:: operator != (const Massiv &obj)
{
	if (this != &obj)
		return true;
	else
		return false;
}

Complex* Massiv:: operator [] (int index)
{

	if (index >= m_col || index < 0)
	{
		error_index();
		return nullptr;
	}
	else
		return mas[index];
}

void Massiv:: operator () (int col, int row, Complex value)
{

	if (col >= m_col || col < 0)
	{
		error_index();
		return;
	}
	
	mas[col][row] = value;
}

Massiv Massiv:: operator ++ (int value)
{
	Complex **temp = nullptr;

	temp = alloc_for_new_matrix(m_row, m_col);
	
	for (int i = 0; i < m_col; i++)
	{
		for (int j = 0; j < m_row; j++)
		{
			temp[i][j] = mas[i][j];
		}
	}

	for (int i = 0; i < m_col; i++)
	{
		for (int j = 0; j < m_row; j++)
		{
			mas[i][j]++;
		}
	}
	return Massiv(temp, m_row, m_col);
}

Massiv& Massiv:: operator ++ ()
{
	for (int i = 0; i < m_col; i++)
	{
		for (int j = 0; j < m_row; j++)
		{
			mas[i][j]++;
		}
	}
	return *this;
}

Massiv Massiv:: operator + (const Massiv &obj)
{
	if (get_col()!=obj.m_col || get_row() != obj.m_row)
	{
		error_objs();
		Massiv temp;
		return temp;
	}

	Complex **temp = nullptr;

	temp=alloc_for_new_matrix(m_row, m_col);

	for (int i = 0; i < m_col; i++)
	{
		for (int j = 0; j < m_row; j++)
		{
			temp[i][j] = mas[i][j] + obj.mas[i][j];
		}
	}

	return Massiv(temp,m_row,m_col);
}

double Massiv::summa()const
{
	double summa = 0;

	for (int i = 0; i < m_col; i++)
	{
		for (int j = 0; j < m_row; j++)
		{
			summa += module_value(mas[i][j]);
		}
	}
	return summa;
}

bool Massiv:: operator > (const Massiv &obj)const
{
	
	if (summa() > obj.summa())
		return true;
	else
		return false;
}

bool Massiv:: operator < (const Massiv &obj)const
{

	if (summa() < obj.summa())
		return true;
	else
		return false;
}

void* Massiv:: operator new(size_t count)
{
	return malloc(count);
}

void* Massiv:: operator new[](size_t count)
{
	return malloc(count);
}

void Massiv:: operator delete(void *pointer)
{
	free(pointer);
}

const Massiv& operator -- (const Massiv &obj)
{
	for (int i = 0; i < obj.m_col; i++)
	{
		for (int j = 0; j < obj.m_row; j++)
		{
			obj.mas[i][j]--;
		}
	}
	return obj;
}

Massiv operator -- (const Massiv &obj, int value)
{
	Complex **temp = nullptr;

	temp = obj.alloc_for_new_matrix(obj.get_row(), obj.get_col());

	for (int i = 0; i < obj.get_col(); i++)
	{
		for (int j = 0; j < obj.get_row(); j++)
		{
			temp[i][j] = obj.mas[i][j];
		}
	}

	for (int i = 0; i < obj.get_col(); i++)
	{
		for (int j = 0; j < obj.get_row(); j++)
		{
			obj.mas[i][j]--;
		}
	}
	return Massiv(temp, obj.get_row(), obj.get_col());
}

Massiv operator - (Massiv &obj, Complex value)
{
	Complex **temp = nullptr;

	temp = obj.alloc_for_new_matrix(obj.get_row(), obj.get_col());

	for (int i = 0; i < obj.get_col(); i++)
	{
		for (int j = 0; j < obj.get_row(); j++)
		{
			temp[i][j] = obj.mas[i][j];
		}
	}

	for (int i = 0; i < obj.get_col(); i++)
	{
		for (int j = 0; j < obj.get_row(); j++)
		{
			temp[i][j] = obj.mas[i][j] - value;
		}
	}
	return Massiv(temp, obj.get_row(), obj.get_col());
}

ostream& operator <<(ostream &s, const Massiv &obj)
{
	for (int i = 0; i < obj.m_col; i++)
	{
		s << endl;
		for (int j = 0; j < obj.m_row; j++)
		{
			s << obj.mas[i][j];
		}
	}
	return s;
}

Massiv::operator int()const
{
	return m_col*m_row;
}

Massiv::operator double()const
{
	return summa();
}

Massiv :: operator Complex()const
{
	Complex value;

	for (int i = 0; i < m_col; i++)
	{
		for (int j = 0; j < m_row; j++)
		{
			value += mas[i][j];
		}
	}
	return value;
}