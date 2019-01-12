#pragma once
#include "Writer.h"

class Scenarist : public Writer
{
public:
	int get_count_screenplays()const;
	bool set_count_screenplays(int count_screenplays);

	void show()const;

	Scenarist(int count_screenplays, bool has_certificate_or_diploma_writer, string name, short int age);
	Scenarist();
	virtual ~Scenarist();

private:
	int s_count_screenplays;
};
