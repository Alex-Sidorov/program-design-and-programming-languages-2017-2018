#include "stack.h"


stack * create_stack(stack *head, char new_simvol)
{
	stack *temp = (stack*)calloc(1, sizeof(stack));
	if (check_stek(temp) == false)//проверка на существование стека
	{
		head = delete_elem_stack(head);
		error_remember();
	}
	else
	{
		temp->simvol = new_simvol;

		temp->next = head;
		head = temp;
	}

	return head;
}

bool check_stek(stack *temp)
{
	return temp ? true : false;
}

stack * delete_elem_stack(stack *head)
{
	stack *temp;

	if (head != nullptr)
	{
		temp = head;
		head = head->next;
		free(temp);
	}

	return head;
}

void error_remember()
{
	printf("Ошибка создания стека.\n\n");
}