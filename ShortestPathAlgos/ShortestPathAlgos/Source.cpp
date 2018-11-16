#include <iostream>
#include <string>
#include "Graph.h"

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

	myGraph.InsertEdge('A', 'B', 3);
	myGraph.InsertEdge('A', 'C', 4);
	myGraph.InsertEdge('A', 'E', 1);
	myGraph.InsertEdge('B', 'I', 5);
	myGraph.InsertEdge('B', 'H', 1);
	myGraph.InsertEdge('C', 'D', 9);
	myGraph.InsertEdge('D', 'E', 4);
	myGraph.InsertEdge('E', 'F', 2);
	myGraph.InsertEdge('F', 'G', 5);
	myGraph.InsertEdge('G', 'H', 3);
	myGraph.InsertEdge('I', 'J', 7);
	myGraph.InsertEdge('J', 'K', 9);
	myGraph.InsertEdge('K', 'L', 5);
	myGraph.InsertEdge('K', 'M', 3);
	myGraph.InsertEdge('K', 'N', 2);
	myGraph.InsertEdge('L', 'N', 4);



	cout << myGraph.Cycle('A') << endl;


	myGraph.PrintGraph();

	cout << endl << "--------------------------------- PRIM'S MST ----------------------------------" << endl;

	myGraph.PrimsMST();

	Graph* PrimsGraph = myGraph.PrimsMST();

	PrimsGraph->PrintGraph();

	cout << endl << "--------------------------------- KRUSHKAL'S MST ----------------------------------" << endl;

	myGraph.KrushkalsMST();

	Graph* KrushkalsGraph = myGraph.PrimsMST();

	KrushkalsGraph->PrintGraph();

	cout << endl << "--------------------------------- DJIKSTRA SHORTEST PATH ----------------------------------" << endl;

	cout << myGraph.DjikstraShortestPath('A', 'L')<< endl;
	system("pause");
}