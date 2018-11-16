#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
 graph g1(14);
 string result;
 g1.addVertex("A");
 g1.addVertex("B");
 g1.addVertex("C");
 g1.addVertex("D");
 g1.addVertex("E");
 g1.addVertex("F");
 g1.addVertex("G");
 g1.addVertex("H");
 g1.addVertex("I");
 g1.addVertex("J");
 g1.addVertex("K");
 g1.addVertex("L");
 g1.addVertex("M");
 g1.addVertex("N");
 g1.addEdge("A","B",1);
 g1.addEdge("A","C",5);
 g1.addEdge("A","E",4);
 g1.addEdge("B","I",8);
 g1.addEdge("B","H",3);
 g1.addEdge("C","D",2);
 g1.addEdge("D","E",9);
 g1.addEdge("E","F",2);
 g1.addEdge("G","F",10);
 g1.addEdge("H","G",7);
 g1.addEdge("I","J",12);
 g1.addEdge("J","K",3);
 g1.addEdge("K","L",11);
 g1.addEdge("K","M",10);
 g1.addEdge("K","N",6);
 g1.addEdge("L","N",13);
 g1.Display();
 int cycle = g1.IsCycle("A");
 cout<<cycle;
 cout<<endl<<endl<<endl;
 result = g1.constructPath("A","N");
 cout<<result<<"\n\n";
 string DFS = g1.DFS_Traversal(&g1);
 cout<<DFS<<endl<<endl;
 string BFS = g1.BFS_Traversal(&g1);
 cout<<BFS<<endl<<endl;
system("pause");
}