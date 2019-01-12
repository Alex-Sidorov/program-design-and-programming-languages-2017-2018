#pragma once

#include <stdio.h>
#include <conio.h>
#include "stack.h"

bool check_count_argc(int argc);
FILE *open_file(char *name_file, char *mode_file);
bool check_file(FILE *file);
void error_open_file(char *name_file);
void error_count_argc();
void close_file(FILE *file);
bool check_simvol(struct stack *head, char new_simvol);
bool find_bracket_in_txt(FILE *original_file, FILE *new_file);
int find_bracket_in_string(FILE *original_file);
bool find_position(FILE *original_file);
void printf_complete();
