#include <iostream>

#ifndef STACK_H
#define STACK_H

using namespace std;


struct VertexNODE
{
	char name;
	bool visited = false;
	void *header = NULL;
	int count = 0;
	VertexNODE* nextVertex = NULL;
};

struct NODE
{
	VertexNODE* value;
	NODE* prev;
};

class Stack
{
public:

	void push(VertexNODE* value)
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

	VertexNODE* pop()
	{
		if (TOP != NULL)
		{
			VertexNODE* value = TOP->value;

			NODE* temp = TOP;
			TOP = TOP->prev;
			free(temp);

			return value;
		}
		//cout << "No value in stack" << endl;
		return NULL;

	}
	VertexNODE* peek()
	{
		if (TOP != NULL)
		{
			VertexNODE* value = TOP->value;

			return value;
		}
		//cout << "No value in stack" << endl;
		return NULL;
	}

private:
	NODE * TOP = NULL;
};
#endif // !STACK_H
