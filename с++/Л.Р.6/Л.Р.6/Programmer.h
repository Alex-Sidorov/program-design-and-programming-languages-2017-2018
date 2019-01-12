#pragma once

#include "Human.h"

class Programmer : virtual public Human
{
public:
	bool has_certificate_or_diploma_programmer()const;
	void change_has_certificate_or_diploma_programmer(bool presence);

	virtual void show()const;

	Programmer();
	Programmer(bool presence, string name, short int age);
	virtual ~Programmer();

private:
	bool w_has_certificate_or_diploma_programmer;
};