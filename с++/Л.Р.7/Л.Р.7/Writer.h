#pragma once

#include <iostream>
#include "Human.h"

class Writer : public Human
{
public:
	int get_count_project()const;
	int get_expirience()const;

	bool set_count_project(int count_project);
	bool set_expirience(int expirience);

	int count_project_in_year()const;
	void show()const;

	Writer();
	Writer(int count_project, int expirience, string name);
	virtual ~Writer();

private:
	int w_count_project;
	int w_expirience;

protected:
	void error_value()const;
};