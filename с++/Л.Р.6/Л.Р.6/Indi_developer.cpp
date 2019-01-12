#include "Indi_developer.h"

int Indi_developer::get_count_game_project()const
{
	return i_count_game_project;
}

bool Indi_developer::set_count_game_project(int count_game_project)
{
	if (count_game_project < 0)
	{
		error_value();
		return false;
	}
	else
		i_count_game_project = count_game_project;

	return true;
}

void Indi_developer::show()const
{
	C_sharp_developer base_c_sharp_developer = (*this);
	Scenarist base_scenarist = (*this);

	base_c_sharp_developer.show();
	base_scenarist.show();

	cout << " оличество сделанных игровых проектов:" << i_count_game_project << endl;
}

Indi_developer::Indi_developer()
{
	i_count_game_project = 0;
}

Indi_developer::Indi_developer(int count_game_project, int count_screenplays, bool has_certificate_or_diploma_writer, short int experience, bool has_certificate_or_diploma_programmer, string name, short int age)
								:Scenarist(count_screenplays,has_certificate_or_diploma_writer,name,age), C_sharp_developer(experience,has_certificate_or_diploma_programmer,name,age), Human(name, age)
{
	i_count_game_project = count_game_project;
}

Indi_developer::~Indi_developer()
{
}