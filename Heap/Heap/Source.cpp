#include<iostream>
#include"Heap.h"

using namespace std;

int main()
{
	Heap myHeap;

	myHeap.Insert(5);
	myHeap.Insert(7);
	myHeap.Insert(1);
	myHeap.Insert(2);
	myHeap.Insert(55);
	myHeap.Insert(35);
	myHeap.Insert(66);
	myHeap.Insert(57);
	myHeap.Insert(44);
	myHeap.Insert(101);

	myHeap.PrintArray();

	cout << "\n\n----------------------------------------------------------------\n\n";

	myHeap.HeapSort(9);

	myHeap.PrintArray();
	system("pause");
}