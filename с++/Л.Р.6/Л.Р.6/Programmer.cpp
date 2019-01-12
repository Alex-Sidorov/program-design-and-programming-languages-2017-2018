#include "Programmer.h"

bool Programmer::has_certificate_or_diploma_programmer()const
{
	return w_has_certificate_or_diploma_programmer;
}

void Programmer::change_has_certificate_or_diploma_programmer(bool presence)
{
	w_has_certificate_or_diploma_programmer = presence;
}

void Programmer::show()const
{
	Human base = (*this);
	base.show();

	if (w_has_certificate_or_diploma_programmer == true)
		cout << "Есть сертификат или диплом программиста." << endl;
	else
		cout << "Нет сертификата или диплома программиста." << endl;
}

Programmer::Programmer()
{
	w_has_certificate_or_diploma_programmer = false;
}

Programmer::Programmer(bool presence, string name, short int age) :Human(name, age)
{
	w_has_certificate_or_diploma_programmer = presence;
}

Programmer::~Programmer()
{
}
