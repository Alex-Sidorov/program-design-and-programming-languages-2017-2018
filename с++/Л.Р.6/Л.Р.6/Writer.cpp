#include "Writer.h"

bool Writer::has_certificate_or_diploma_writer()const
{
	return w_has_certificate_or_diploma_writer;
}

void Writer::change_has_certificate_or_diploma_writer(bool presence)
{
	w_has_certificate_or_diploma_writer = presence;
}

void Writer::show()const
{
	Human base = (*this);
	base.show();

	if (w_has_certificate_or_diploma_writer == true)
		cout << "Есть сертификат или диплом писателя." << endl;
	else
		cout << "Нет сертификата или диплома писателя." << endl;
}

Writer::Writer()
{
	w_has_certificate_or_diploma_writer = false;
}

Writer::Writer(bool presence, string name, short int age)  : Human(name, age)
{
	w_has_certificate_or_diploma_writer = presence;
}

Writer::~Writer()
{
}