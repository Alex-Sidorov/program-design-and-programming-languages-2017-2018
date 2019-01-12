#pragma once

#include <string>
#include <iostream>
#include "Human.h"
#include "Place_of_work.h"
#include "Post.h"

using namespace std;

class Chief:public Human
{
public:
	int get_count_people()const;
	string get_chief_post()const;
	bool get_chief_presence_place()const;
	string get_chief_location_place()const;
	
	bool set_count_people(int count_people);
	void set_chief_post(string post);
	void set_chief_place(string location);

	virtual void show()const;

	Chief();
	Chief(string name, short int age, int count_people,string location, string post);
	virtual ~Chief();

private:
	int c_count_people;
	Post chief_post;
	Place_of_work chief_place;

	void error_count_people()const;
};
