#include <iostream>

using namespace std;

struct NODE
{
public:

	int value;
	NODE *next;
	NODE *prev;

};

class DoubleLinkedList
{
public:
	void insert(int value)
	{
		NODE *ptr = (NODE*)malloc(sizeof(NODE));
		ptr->value = value;
		ptr->next = NULL;
		ptr->prev = NULL;

		if (start == NULL)
		{
			start = ptr;
		}
		else
		{
			NODE *current = start;

			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = ptr;
			ptr->prev = current;
		}
	}
	void PrintList()
	{
		NODE *current = start;
		if (start)
		{
			while (current->next != NULL)
			{
				cout << "<<<<" << current << ">>>>" << endl;
				cout << "Value:     " << current->value << endl << "Previous:  " << current->prev << endl << "Next:      " << current->next << endl << endl;
				current = current->next;
			}
			cout << "<<<<" << current << ">>>>" << endl;
			cout << "Value:     " << current->value << endl << "Previous:  " << current->prev << endl << "Next:      " << current->next << endl << endl;

		}
		else
		{
			cout << "No elements to print" << endl;
		}
	}
	NODE* search(int value)
	{
		if (start)
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
		else
		{
			cout << "Empty List" << endl;
			return NULL;
		}
	}

	void Delete(int value)
	{
		NODE *current = search(value);

		if (start == NULL)
		{
			cout << "Empty List" << endl;
		}
		else if (current == start)
		{
			start = start->next;
			free(current);
			if (start != NULL)
				start->prev = NULL;
		}
		else if (current != NULL)
		{
			(current->prev)->next = current->next;
			(current->next)->prev = current->prev;
			free(current);
		}
		else
		{
			cout << "Item to be deleted Not present" << endl;
		}
	}
	int NumberOfElements()
	{
		NODE *current = start;
		if (current != NULL)
		{
			int result = 1;
			while (current->next != NULL)
			{
				result++;
				current = current->next;
			}
			return result;
		}
		else
		{
			return 0;
		}
	}
	void InsertionSort()
	{
		if (start == NULL)
		{
			cout << "Empty List" << endl;
		}
		else if (start->next == NULL)
		{
			cout << "Can't sort only one element." << endl;
		}
		else
		{
			NODE *iterator1 = start->next, *iterator2;
			while (iterator1)
			{
				iterator2 = iterator1;
				while (iterator2)
				{
					if (iterator2->value < iterator2->prev->value)
					{
						NODE *temp1, *temp2;
						temp1 = iterator2->prev;
						temp2 = temp1->prev;

						previous->next = temp1;
						temp1->next = current;
						current->next = temp2;

					}
					iterator2 = iterator2->prev;
				}
				iterator1 = iterator1->next;
			}

		}
	}
	

private:
	NODE * start = NULL, *ptr;
	NODE * myNode;

};

