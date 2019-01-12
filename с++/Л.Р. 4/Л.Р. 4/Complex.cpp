#include "Complex.h"

std::ostream& operator<<(std::ostream& s, Complex value)
{
	if (value.image < 0)
		s << value.real << value.image << "i ";
	else
		s << value.real << '+' << value.image << "i ";

	return s;
}

void Complex::operator+=(Complex value)
{
	real += value.real;
	image += value.image;
}

Complex::Complex()
{
	real = 0;
	image = 0;
}

Complex::Complex(int new_real, int new_image)
{
	real = new_real;
	image = new_image;
}

void Complex::operator-=(Complex value)
{
	real -= value.real;
	image -= value.image;
}

Complex& Complex::operator=(Complex value)
{
	real = value.real;
	image = value.image;
	return *this;
}

void Complex::operator++(int value)
{
	real++;
	image++;
}

void Complex::operator--(int value)
{
	real--;
	image--;
}
 
Complex Complex::operator+(Complex value)
{
	Complex temp;

	temp.image = image + value.image;
	temp.real = real + value.real;

	return temp;
}

Complex Complex::operator-(Complex value)
{
	Complex temp;

	temp.image = image - value.image;
	temp.real = real - value.real;

	return temp;
}
