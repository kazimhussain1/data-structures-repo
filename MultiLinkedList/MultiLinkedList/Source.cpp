#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	LinkedList myList;
	myList.insertNODE("BSCS 1st year Sec A");
	myList.insertNODE("BSCS 1st year Sec B");
	myList.insertNODE("BSCS 2nd year Sec A");
	myList.insertNODE("BSCS 2nd year Sec B");

	myList.insertSUBNODE(16101061, "BSCS 2nd year Sec A");
	myList.insertSUBNODE(16101065, "BSCS 2nd year Sec A");

	myList.PrintList();

	cout << "\n\n" << myList.search("BSCS 2nd year Sec B") << endl;

	//myList.Delete("BSCS 2nd year Sec A");
	myList.PrintList();

	getchar();
	system("sleep");
}