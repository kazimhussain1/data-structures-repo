#include <iostream>

using namespace std;

class NODE
{
public:

	int value;
	NODE *next;

};

class LinkedList
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
				ptr->next = NULL;
				start = ptr;

			}
			else
			{
				ptr->next = (NODE*)malloc(sizeof(NODE));
				ptr = ptr->next;
				ptr->value = value;
				ptr->next = NULL;
			}
		}
		else if (mode == 2)
		{
			NODE *ptr = (NODE*)malloc(sizeof(NODE));
			ptr->value = value;
			ptr->next = NULL;

			if (start == NULL)
			{
				start = ptr;
			}
			else
			{
				NODE *current = start;

				while (current->next != NULL)
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
		if (start)
		{
			while (current->next != NULL)
			{
				cout << current->value << endl;
				current = current->next;
			}
			cout << current->value;
		}
		else
		{
			cout << "No elements to print" << endl;
		}
	}
	bool search(int value)
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
				flag = 1;
			}
			return flag == 0 ? false : true;
		}
		else
		{
			cout << "Empty List" << endl;
			return false;
		}
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
		}
		else
		{
			previous = start;
			current = start->next;

			while (current->next != NULL)
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
	void BubbleSort()
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
			
			for(int i = 0;i < this->NumberOfElements();i++)
			{

				NODE *previous, *current = start;
				if (current->value > current->next->value)
				{
					NODE *temp = start->next;
					start->next = temp->next;
					temp->next = start;
					start = temp;
				}
				previous = start;
				current = start->next;
				while (current)
				{
					if (current->next != NULL)
					{
						if (current->value > current->next->value)
						{
							NODE *temp1, *temp2;
							temp1 = current->next;
							temp2 = temp1->next;

							previous->next = temp1;
							temp1->next = current;
							current->next = temp2;
						}
						else
						{
							current = current->next;

						}
						previous = previous->next;
					}
					else
					{
						current = current->next;
					}
				}
			}
			
		}
	}

	

private:
	NODE * start = NULL, *ptr;
	NODE * myNode;

};

