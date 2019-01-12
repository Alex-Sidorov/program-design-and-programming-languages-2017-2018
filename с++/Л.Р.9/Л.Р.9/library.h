#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"

void show_reverse_file(std::fstream &stream);
void show_file(std::fstream &stream);
void print_menu();
int input_menu();

std::string find_record(std::fstream &stream, std::string str);

std::string delete_record(std::fstream &stream, std::string str);

bool menu_switch(Student &obj1, Student &obj2, std::fstream &stream, int menu);