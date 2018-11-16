#include <iostream>

#ifndef STACK_H
#define STACK_H

using namespace std;

struct NODE
{
	int value;
	NODE* prev;
};

void push(int value, NODE** TOP)
{
	NODE *ptr = (NODE*)malloc(sizeof(NODE));
	ptr->value = value;
	if(*TOP == NULL)
	{
		ptr->prev = NULL;
		*TOP = ptr;
	}
	else
	{
		ptr->prev = *TOP;

		*TOP = ptr;
	}
}

int pop(NODE** TOP)
{
	if ((*TOP) != NULL)
	{
		int value = (*TOP)->value;

		NODE* temp = *TOP;
		*TOP = (*TOP)->prev;
		free(temp);

		return value;
	}
	cout << "No value in stack" << endl;
	return -1;
	
}
int peek(NODE** TOP)
{
	if ((*TOP) != NULL)
	{
		int value = (*TOP)->value;

		return value;
	}
	cout << "No value in stack" << endl;
	return -1;
}

#endif // !STACK_H
