#include<iostream>
#include<string>
#include"Graph.h"

using namespace std;

int main()
{
	Graph myGraph;

	myGraph.InsertVertex('A');
	myGraph.InsertVertex('B');
	myGraph.InsertVertex('C');
	myGraph.InsertVertex('D');
	myGraph.InsertVertex('E');
	myGraph.InsertVertex('F');
	myGraph.InsertVertex('G');
	myGraph.InsertVertex('H');
	myGraph.InsertVertex('I');
	myGraph.InsertVertex('J');
	myGraph.InsertVertex('K');
	myGraph.InsertVertex('L');
	myGraph.InsertVertex('M');
	myGraph.InsertVertex('N');
	
	myGraph.InsertEdge('A', 'B');
	myGraph.InsertEdge('A', 'C');
	myGraph.InsertEdge('A', 'E');
	myGraph.InsertEdge('B', 'I');
	myGraph.InsertEdge('B', 'H');
	myGraph.InsertEdge('C', 'D');
	myGraph.InsertEdge('D', 'E');
	myGraph.InsertEdge('E', 'F');
	myGraph.InsertEdge('F', 'G');
	myGraph.InsertEdge('G', 'H');
	myGraph.InsertEdge('I', 'J');
	myGraph.InsertEdge('J', 'K');
	myGraph.InsertEdge('K', 'L');
	myGraph.InsertEdge('K', 'M');
	myGraph.InsertEdge('K', 'N');
	myGraph.InsertEdge('L', 'N');

	
	
	myGraph.PrintGraph();

	cout << "\n" << myGraph.Degree('K') << endl;


	cout << myGraph.Path('A', 'D') << endl;

	/*for (int i = 'A'; i <='N' ; i++)
	{
		cout << (char)i << ":\t" << myGraph.Cycle(i) << endl;
	}*/
	//cout << 'K' << ":\t" << myGraph.Cycle('K') << endl;

	system("pause");
}