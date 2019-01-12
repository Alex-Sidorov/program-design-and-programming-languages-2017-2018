#pragma once

#include <iostream>
#include <string>

class Post
{
public:
	void set_post(std::string post);

	std::string get_post()const;

	virtual void show()const;

	Post(std::string post);
	Post();
	virtual ~Post();

private:
	std::string p_post;
};