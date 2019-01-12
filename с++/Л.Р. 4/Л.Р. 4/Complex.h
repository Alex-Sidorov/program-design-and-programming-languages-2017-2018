#pragma once

#include <iostream>

struct Complex
{
	int real = 0;
	int image = 0;

	Complex();
	Complex(int, int);
	friend std::ostream& operator <<(std::ostream& s, Complex value);
	void operator +=(Complex value);
	void operator -=(Complex value);
	Complex& operator =(Complex value);
	void operator ++(int value);
	void operator --(int value);
	Complex operator +(Complex value);
	Complex operator -(Complex value);
};