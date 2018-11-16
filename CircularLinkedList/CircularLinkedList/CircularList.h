#include <iostream>

using namespace std;

struct NODE
{
	int value;
	NODE *next;
};

class CircularList
{
public:
	void insert(int value, int mode = 1)
	{
		if (mode = 1)
		{
			if (start == NULL)
			{
				ptr = (NODE*)malloc(sizeof(NODE));
				ptr->value = value;
				ptr->next = ptr;
				start = ptr;

			}
			else
			{
				NODE *previous = ptr;
				ptr->next = (NODE*)malloc(sizeof(NODE));
				ptr = ptr->next;
				previous->next = ptr;
				ptr->value = value;
				ptr->next = start;
			}
		}
		else if (mode == 2)
		{
			NODE *ptr = (NODE*)malloc(sizeof(NODE));
			ptr->value = value;
			ptr->next = start;

			if (start == NULL)
			{
				start = ptr;
			}
			else
			{
				NODE *current = start;

				while (current->next != start)
				{
					current->next = current;
				}
				current->next = ptr;
			}

		}
	}
	void PrintList()
	{
		NODE *current = start;
		while (current->next != start)
		{
			cout << current->value << endl;
			current = current->next;
		}
		cout << current->value;
	}
	bool search(int value)
	{
		NODE *current = start;
		int flag = 0;
		while (current->next != start)
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
			flag = 1;
		}
		return flag == 0 ? false : true;
	}

	void Delete(int value)
	{
		NODE *previous, *current = start;
		int flag = 0;
		if (current->value == value)
		{
			NODE *temp = start;
			start = start->next;
			free(temp);
			ptr->next = start;
		}
		else
		{
			previous = start;
			current = start->next;

			while (current->next != start)
			{
				if (current->value == value)
				{
					break;
				}
				previous = previous->next;
				current = current->next;
			}
			if (current->value == value)
			{
				previous->next = current->next;
				free(current);
			}
			else
			{
				cout << "No such value exists" << endl;
			}
		}
	}
private:
	NODE * start = NULL, *ptr;
	NODE * myNode;

};