#pragma once

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

struct stack
{
	char simvol;
	stack *next;
};

stack * create_stack(stack *head, char new_simvol);
bool check_stek(stack *temp);
stack * delete_elem_stack(stack *head);
void error_remember();
