#include <iostream>

using namespace std;

class HashTable
{
public:
	int HashFunction(int value)
	{
		if (Table == NULL)
		{
			cout << "Table not initialized" << endl << "Enter size of table: " ;
			cin >> n;
			Table = new int[n];
			for (int i = 0; i < n; i++)
			{
				Table[i] = -1;
			}
		}
		int index = value % n;
		return index;
	}
	void Insert(int value)
	{
		int index = HashFunction(value);
		if (Table[index] == -1)
		{
			Table[index] = value;
		}
		else
		{
			LinearProbing(value, index);
		}
	}
	int LinearProbing(int value, int index)
	{
		int count=0;
		while (true)
		{
			index = (index + 1) % 10;
			if (Table[index] == -1)
			{
				Table[index] = value;
				return index;
			}
			count++;
			if (count >= n)
			{
				cout << "Hash Table Full" << endl;
				return index;
			}
		}
	}
	void QuadraticProbing(int value, int index)
	{
		int i = 1;
		int counter = 0;
		int local_index = index;
		while (true)
		{
			local_index = (index + i*i) % 10;
			if (Table[local_index] == -1)
			{
				Table[local_index] = value;
				break;
				
			}
			i++;
			counter++;
			if (counter >= 100)
			{
				break;
			}
		}
	}
	int Search(int value)
	{
		int index = HashFunction(value);
		if (Table[index] == value)
		{
			return Table[index];
		}

		int count = 0;
		while (true)
		{
			index = (index + 1) % n;
			if (Table[index] == value)
			{
				return Table[index];
			}
			count++;
			if (count >= n)
			{
				return -1;
			}
		}

	}
	void PrintTable()
	{
		cout << "\n[";
		for (int i = 0; i < n; i++)
		{
			cout << Table[i];
			if (i < n-1)
			{
				cout << ", ";
			}
		}
		cout << "]\n\n";
	}
	

private:
	int *Table = NULL;
	int n;
};

int main()
{
	HashTable myTable;
	myTable.Insert(5);
	myTable.Insert(77);
	myTable.Insert(99);
	myTable.Insert(77);
	myTable.Insert(88);
	myTable.Insert(88);
	myTable.PrintTable();

	cout << "\n\n" <<myTable.Search(105);

	system("pause");
}

