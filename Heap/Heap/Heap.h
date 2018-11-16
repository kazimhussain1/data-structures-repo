#include<iostream>

using namespace std;

class Heap
{
public:
	Heap()
	{
		this->n = 10;
		this->myArray = new int[n];
		for (int i = 0; i < n; i++)
		{
			this->myArray[i] = -1;
		}
	}

	void Insert(int value, int index = 0)
	{
		if (index < this->n)
		{
			if (this->myArray[index] == -1)
			{
				myArray[index] = value;
				PrintArray();
				//heapify(CalcParent(index));
				heapify(index);
			}
			else
			{
				Insert(value, index + 1);
			}
		}
		else
		{
			//code for increasing size of myArray
		}
	}
	void heapify(int index)
	{
		if (index > 0)
		{
			int parent = CalcParent(index);

			if (myArray[index] > myArray[parent])
			{
				swap(myArray[index], myArray[parent]);
			}
			heapify(parent);
		}
	}

	void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	void heapDown(int index, int n)
	{
		int leftchild, rightchild;
		if (index <= n)
		{
			leftchild = CalcLeftChild(index);
			rightchild = CalcRightChild(index);
			if (myArray[leftchild] > myArray[index] && leftchild < n)
			{

				swap(myArray[leftchild], myArray[index]);
				heapDown(leftchild, n);

			}
			else if(myArray[rightchild] > myArray[index] && rightchild < n)
			{					
				swap(myArray[rightchild], myArray[index]);
				heapDown(rightchild, n);
		
			}
			
		}
	}

	void HeapSort(int len)
	{
		if (len > 0)
		{
			swap(myArray[0], myArray[len]);
			heapDown(0, len - 1);
			//PrintArray();
			HeapSort(len - 1);
		}
	}

	int CalcLeftChild(int index)
	{
		return 2 * index + 1;
	}
	int CalcRightChild(int index)
	{
		return 2 * index + 2;
	}
	int CalcLeftOrRightChild(int index)
	{
		
		return (myArray[2 * index + 1] == -1 )? (2 * index + 1) : (2 * index + 2);
	}

	int CalcParent(int index)
	{
		if (index == 0)
		{
			return 0;
		}
		if (index % 2 == 0)
		{
			return (index - 2) / 2;
		}
		else
		{
			return (index - 1) / 2;
		}
	}

	void PrintArray()
	{
		cout << "\n[";
		for (int i = 0; i < this->n; i++)
		{
			cout << this->myArray[i];
			if (i < this->n - 1)
				cout << ", ";
			else
				cout << "]" << endl;
		}
	}

private:
	int *myArray;
	int n;
};

