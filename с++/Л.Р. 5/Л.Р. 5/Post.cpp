#include "Post.h"

void Post::set_post(std::string post)
{
	p_post = post;
}

std::string Post::get_post()const
{
	return p_post;
}

void Post::show()const
{
	std::cout << "Должность:" << p_post << std::endl;
}

Post::Post(std::string post)
{
	p_post = post;
}

Post::Post()
{
	p_post = "Неизвестна";
}

Post::~Post()
{
}