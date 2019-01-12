#pragma once

#include <string>
#include <iostream>

class Place_of_work
{
public:

	void set_location(std::string location);

	bool value_presence()const;
	std::string get_location()const;

	virtual void show()const;

	Place_of_work();
	Place_of_work(std::string location);
	virtual ~Place_of_work();

private:
	bool pow_presence;
	std::string pow_location;
};