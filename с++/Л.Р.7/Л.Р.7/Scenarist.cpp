#include "Scenarist.h"

int Scenarist::count_project_in_year()const
{
	if (s_count_screenplays == 0)
		return 0;
	else
		return get_expirience() / s_count_screenplays;
}

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
	Writer::show();

	cout << "Количество написанных сценариев:" << s_count_screenplays << endl;
}

Scenarist::Scenarist(int count_screenplays, int expirience, string name) : Writer(count_screenplays,expirience, name)
{
	if (count_screenplays < 0)
	{
		error_value();
		s_count_screenplays = 0;
	}
	else
		s_count_screenplays = count_screenplays;
}

Scenarist::Scenarist()
{
	s_count_screenplays = 0;
}

Scenarist::~Scenarist()
{
}