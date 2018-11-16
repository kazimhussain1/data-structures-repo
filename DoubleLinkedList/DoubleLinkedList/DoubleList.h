#include <iostream>

using namespace std;

struct NODE
{
public:

	int value;
	NODE *next;
	NODE *prev;

};

void insert(int value, NODE** start)
{
	
	NODE *ptr = (NODE*)malloc(sizeof(NODE));
	ptr->value = value;
	ptr->next = NULL;
	ptr->prev = NULL;

	if (*start == NULL)
	{
		*start = ptr;
	}
	else
	{
		NODE *current = *start;

		while (current->next != NULL)
		{
			current->next = current;
		}
		current->next = ptr;
		ptr->prev = current;
	}

	
}
void PrintList(NODE* start)
{
	NODE *current = start;
	while (current->next != NULL)
	{
		cout << current->value << endl;
		current = current->next;
	}
	cout << current->value;
}
NODE* search(int value, NODE* start)
{
	NODE *current = start;
	int flag = 0;
	while (current->next != NULL)
	{
		if (current->value == value)
		{
			flag = 1;
			break;
		}
		current = current->next;
	}
	if (current->value == value)
	{
		return current;
	}
	else
	{
		return NULL;
	}
}

void DeleteValue(int value, NODE** start)
{
	NODE *current = search(value, *start);

	if (current == *start)
	{
		*start = (*start)->next;
		free(current);
		if(*start != NULL)
			(*start)->prev = NULL;
		cout << "yoloy"<<endl;
	}
	else
	{
		if (current != NULL)
		{
			(current->prev)->next = current->next;
			(current->next)->prev = current->prev;
			free(current);
			cout << "poloy"<<endl;
		}
		else
		{
			cout << "moloy" << endl;
		}
	}
}