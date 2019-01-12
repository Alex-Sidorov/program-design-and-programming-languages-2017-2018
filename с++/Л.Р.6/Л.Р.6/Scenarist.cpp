#include "Scenarist.h"

int Scenarist::get_count_screenplays()const
{
	return s_count_screenplays;
}

bool Scenarist::set_count_screenplays(int count_screenplays)
{
	if (count_screenplays < 0)
	{
		error_value();
		return false;
	}
	else
		s_count_screenplays = count_screenplays;

	return true;
}

void Scenarist::show()const
{
	Writer base = (*this);

	base.show();

	cout << "Количество написанных сценариев:" << s_count_screenplays << endl;
}

Scenarist::Scenarist(int count_screenplays, bool has_certificate_or_diploma_writer, string name, short int age) : Writer(has_certificate_or_diploma_writer,name, age)
{
	if (count_screenplays < 0)
	{
		error_value();
		s_count_screenplays = 0;
	}
	else
		s_count_screenplays = count_screenplays;

	s_count_screenplays = count_screenplays;
}

Scenarist::Scenarist()
{
	s_count_screenplays = 0;
}

Scenarist::~Scenarist()
{
}