#include <iostream>
#include "CircularList.h"

using namespace std;

int main()
{
	CircularList myList;
	myList.insert(4);
	myList.insert(7);
	myList.insert(11);
	myList.insert(55);
	myList.insert(99);

	myList.PrintList();

	myList.search(99) ? cout << "\n\nFound!!\n\n" << endl : cout << "\n\nNot Found!!\n\n" << endl;

	myList.Delete(4);
	myList.PrintList();

	getchar();
	system("sleep");
}