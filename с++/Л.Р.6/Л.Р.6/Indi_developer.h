#pragma once

#include "Scenarist.h"
#include "C_sharp_developer.h"

class Indi_developer : public Scenarist, public C_sharp_developer
{
public:
	int get_count_game_project()const;
	bool set_count_game_project(int count_game_project);

	void show()const;

	Indi_developer();
	Indi_developer(int count_game_project, int count_screenplays, bool has_certificate_or_diploma_writer, short int experience, bool has_certificate_or_diploma_programmer, string name, short int age);
	virtual ~Indi_developer();

private:
	int i_count_game_project;
};