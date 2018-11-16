#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	DoubleLinkedList myList;
	myList.insert(99);
	myList.insert(7);
	myList.insert(55);
	myList.insert(11);
	myList.insert(55);

	myList.PrintList();

	myList.search(2) ? cout << "\n\nFound!!\n\n" << endl : cout << "\n\nNot Found!!\n\n" << endl;

	myList.Delete(4);
	myList.Delete(11);
	myList.Delete(99);
	myList.PrintList();

	getchar();
	system("sleep");
}