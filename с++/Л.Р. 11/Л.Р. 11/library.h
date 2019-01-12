#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

void open_file(std::fstream &file, std::string name_file, unsigned mode);

void close_file(std::fstream &file);

int count_simvol_one_str(std::string str, char simvol);

void write_in_file(std::fstream &file_one, std::fstream &file_two, std::vector<int> count_simvols, char simvol);

void show_in_cmd(int number_str, std::string str, int count_simvols, char simvol);

void count_simvol_all_str(char simvol, std::fstream &file_one, std::vector<int> &count_simvols);

char input_simvol();

void print_complete_file(std::string name_file);

void print_error(std::string name_file);

void error_write();