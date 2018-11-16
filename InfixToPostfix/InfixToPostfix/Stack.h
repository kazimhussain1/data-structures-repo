#include <iostream>

#ifndef STACK_H
#define STACK_H

using namespace std;

struct NODE
{
	char value;
	NODE* prev;
};

class Stack
{
public:

	void push(int value)
	{
		NODE *ptr = (NODE*)malloc(sizeof(NODE));
		ptr->value = value;
		if (TOP == NULL)
		{
			ptr->prev = NULL;
			TOP = ptr;
		}
		else
		{
			ptr->prev = TOP;

			TOP = ptr;
		}
	}

	int pop()
	{
		if (TOP != NULL)
		{
			int value = TOP->value;

			NODE* temp = TOP;
			TOP = TOP->prev;
			free(temp);

			return value;
		}
		cout << "No value in stack" << endl;
		return -1;

	}
	int peek()
	{
		if (TOP != NULL)
		{
			int value = TOP->value;

			return value;
		}
		cout << "No value in stack" << endl;
		return -1;
	}

private:
	NODE * TOP = NULL;
};
#endif // !STACK_H
