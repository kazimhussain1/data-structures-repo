#include <iostream>
#include <string>

using namespace std;


class SUBNODE
{
public:
	int RollNo;
	SUBNODE *next;
};

class NODE
{
public:
	string value;
	NODE *next;
	SUBNODE *head;
};


class LinkedList
{
public:
	void insertNODE(string value, int mode = 1)
	{
		if (mode = 1)
		{
			if (start == NULL)
			{
				ptr = new NODE;
				ptr->value = value;
				ptr->next = NULL;
				ptr->head = NULL;
				start = ptr;

			}
			else
			{
				ptr->next = new NODE;
				ptr = ptr->next;
				ptr->value = value;
				ptr->next = NULL;
				ptr->head = NULL;
			}
		}
		else if (mode == 2)
		{
			NODE *ptr = new NODE;
			ptr->value = value;
			ptr->next = NULL;
			ptr->head = NULL;

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
	void insertSUBNODE(int RollNo, string Class)
	{
		NODE **myClass = search(Class);
		if (myClass != NULL)
		{
			SUBNODE *temp = new SUBNODE;
			temp->RollNo = RollNo;
			temp->next = NULL;

			SUBNODE *current = (*myClass)->head;
			if (current)
			{
				(*myClass)->head;
				current = current->next;
			}
			
			while (current)
			{
				current = current->next;
			}
			current = temp;
		}

	}
	void PrintList()
	{
		NODE *current = start;
		while (current->next != NULL)
		{
			cout << current->value << endl;
			current = current->next;
		}
		cout << current->value;
	}
	NODE** search(string value)
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
		return flag == 0 ? NULL : &current;
	}

	void Delete(string value)
	{
		NODE *previous, *current = start;
		int flag = 0;
		if (current->value == value)
		{
			NODE *temp = start;
			start = start->next;
			delete temp;
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
				delete current;
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
