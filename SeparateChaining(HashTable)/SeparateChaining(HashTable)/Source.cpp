#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	HashTable myTable;

	myTable.Insert(1);
	myTable.Insert(2);
	myTable.Insert(3);
	myTable.Insert(4);
	myTable.Insert(9);
	myTable.Insert(59);
	myTable.Insert(21);
	myTable.Insert(81);
	myTable.Insert(22);
	myTable.Insert(33);
	myTable.Insert(44);
	myTable.Insert(55);
	myTable.Insert(66);
	myTable.Insert(99);

	myTable.Search(21);

	myTable.PrintTable();

	system("pause");
}