#pragma once

#include <iostream>
#include "Human.h"

class Programmer : public Human
{
public:
	int get_count_project()const;
	int get_expirience()const;

	bool set_count_project(int count_project);
	bool set_expirience(int expirience);

	int count_project_in_year()const;
	void show()const;

	Programmer();
	Programmer(int count_project, int expirience, string name);
	virtual ~Programmer();

private:
	int p_count_project;
	int p_expirience;

protected:
	void error_value()const;
};
