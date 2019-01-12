#pragma once

#include <iostream>
#include "Human.h"

class Writer : virtual public Human
{
public:
	bool has_certificate_or_diploma_writer()const;
	void change_has_certificate_or_diploma_writer(bool presence);

	void show()const;

	Writer();
	Writer(bool presence, string name, short int age);
	virtual ~Writer();

private:
	bool w_has_certificate_or_diploma_writer;
};