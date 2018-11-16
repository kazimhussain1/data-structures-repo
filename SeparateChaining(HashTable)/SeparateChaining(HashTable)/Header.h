#include <iostream>

using namespace std;

struct NODE
{
	int value;
	NODE *next = NULL;
};

class HashTable
{
public:
	int HashFunction(int value)
	{
		if (Table == NULL)
		{
			/*cout << "Table not initialized" << endl << "Enter size of table: ";
			cin >> n;*/
			n = 10;
			Table = new NODE*[n];
			for (int i = 0; i < n; i++)
			{
				Table[i] = new NODE;
				(Table[i])->value = -1;
			}
		}
		int index = value % n;
		return index;
	}
	void Insert(int value)
	{
		int index = HashFunction(value);
		if (Table[index]->value == -1)
		{
			Table[index]->value = value;
		}
		else
		{
			NODE *current = Table[index];
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = (NODE*)malloc(sizeof(NODE));
			current->next->value = value;
			current->next->next = NULL;

		}
	}
	
	int Search(int value)
	{
		int index = HashFunction(value);
		if (Table[index]->value == value)
		{
			cout << "FOUND" << endl;
			return Table[index]->value;
		}
		else
		{
			NODE *current = Table[index];
			while (current->next != NULL && current->value != value)
			{
				current = current->next;
			}
			if (current->value == value)
			{
				cout << "Found" << endl;
				return current->value;
			}
			else
			{
				cout << "Not Found" << endl;
				return -1;
			}
		}

	}
	void PrintTable()
	{
		cout << "\n[";
		for (int i = 0; i < n; i++)
		{
			cout << Table[i]->value;
			NODE *current = Table[i];
			while (current->next != NULL)
			{
				current = current->next;
				cout <<  ", " << current->value;
			}
			if (i < n - 1)
			{
				cout << ", ";
			}
		}
		cout << "]\n\n";
	}


private:
	NODE **Table = NULL;
	int n;
};