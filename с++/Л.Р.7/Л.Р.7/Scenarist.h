#pragma once
#include "Writer.h"

class Scenarist : public Writer
{
public:
	int get_count_screenplays()const;
	bool set_count_screenplays(int count_screenplays);

	int count_project_in_year()const;
	void show()const;

	Scenarist(int count_screenplays, int expirience, string name);
	Scenarist();
	virtual ~Scenarist();

private:
	int s_count_screenplays;
};
