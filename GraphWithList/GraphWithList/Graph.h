#include<iostream>
#include<queue>
//#include"stack.h"

using namespace std;

struct VertexNODE
{
	char name;
	bool visited = false;
	void *header = NULL;
	int count = 0;
	VertexNODE* nextVertex = NULL;
};
struct EdgeNODE
{
	VertexNODE* address = NULL;
	EdgeNODE* nextEdge;
};

class Graph
{
public:
	Graph()
	{
		this->root = NULL;
		this->HelperVariableForInsertEdge = 0;
	}
		
	void InsertVertex(char name)
	{
		VertexNODE *temp = new VertexNODE();
		temp->name = name;
		temp->visited = false;
		temp->header = NULL;
		temp->count = 0;
		temp->nextVertex = NULL;
		if (this->root == NULL)
		{
			root = temp;
		}
		else
		{
			VertexNODE * current = root;
			while (current->nextVertex != NULL)
			{
				current = current->nextVertex;
			}
			current->nextVertex = temp;
		}
		
	}

	VertexNODE * searchVertex(char name)
	{
		VertexNODE * current = root;
		while (current->nextVertex != NULL && current->name != name)
		{
			current = current->nextVertex;
		}
		if (current->name == name)
		{
			return current;
		}
		else
		{
			return NULL;
		}
	}

	void InsertEdge(char VertexName, char EdgeName)
	{
		EdgeNODE *temp = new EdgeNODE();

		VertexNODE *Vertex = searchVertex(VertexName);
		VertexNODE *Edge = searchVertex(EdgeName);

		temp->address = Edge;
		temp->nextEdge = NULL;

		if (Vertex->header == NULL)
		{
			Vertex->header = temp;
		}
		else
		{
			EdgeNODE *current = (EdgeNODE*)Vertex->header;
			while (current->nextEdge != NULL)
			{
				current = current->nextEdge;
			}
			current->nextEdge = temp;
		}
		Vertex->count++;
		if (HelperVariableForInsertEdge == 0)
		{
			HelperVariableForInsertEdge = !HelperVariableForInsertEdge;
			InsertEdge(EdgeName, VertexName);
		}
		else// (HelperVariableForInsertEdge == 1)
		{
			HelperVariableForInsertEdge = !HelperVariableForInsertEdge;
		}
		
		
	}
	EdgeNODE* Isconnected(char Vertex1, char Vertex2)
	{
		VertexNODE *myVertex = searchVertex(Vertex1);

		EdgeNODE *current = (EdgeNODE*)myVertex->header;
		
		bool flag = 0;
		while (current != NULL)
		{
			if (current->address->name == Vertex2)
			{
				flag = 1;
				current = current->nextEdge;
				break;
			}
		}
		if (flag)
		{
			return current;
		}
		else
		{
			return NULL;
		}
	}
	string Path(char Source, char Destination, VertexNODE* delimiter = NULL)
	{
		string path;
		if (Source == Destination)
		{
			path = Destination;
			return path;
		}

		VertexNODE *SourceVertex = searchVertex(Source);
		VertexNODE *DestinationVertex = searchVertex(Destination);

		SourceVertex->visited = true;

		EdgeNODE *current = (EdgeNODE*)SourceVertex->header;

		while (current)
		{
			if (current->address->visited == false)
			{
				string temp;
				temp = Path(current->address->name, Destination, delimiter);
				if (temp == "No Path")
				{

				}
				else
				{
					path += Source;
					path += temp;
					if (path[0] == Source)
					{
						ResetVisited();
					}
					return path;
					
				}
			}
			else if (current->address == DestinationVertex && delimiter != SourceVertex)
			{
				path += Source;
				path += Destination;
				return path;
			}
			current = current->nextEdge;
		}
		return "No Path";

	}
	string Cycle(char Vertex)
	{
		string path;

		VertexNODE *SourceVertex = searchVertex(Vertex);
		VertexNODE *DestinationVertex = searchVertex(Vertex);

		SourceVertex->visited = true;

		EdgeNODE *current = (EdgeNODE*)SourceVertex->header;

		while (current)
		{
			if (current->address->visited == false)
			{
				string temp;
				temp = Path(current->address->name, Vertex, current->address);
				if (temp == "No Path")
				{

				}
				else
				{
					path += Vertex;
					path += temp;
					
					return path;
				}
			}
			current = current->nextEdge;
		}
		ResetVisited();
		return "No Cycle";
	}

	void ResetVisited()
	{
		VertexNODE* current = this->root;

		while (current)
		{
			current->visited = false;
			current = current->nextVertex;
		}
	}

	int Degree(char name)
	{
		VertexNODE *myVertex = searchVertex(name);

		int degree = 0;
		for (int i = 0; i < myVertex->count; i++)
		{
			degree++;
		}
		return degree;
	}
	/*string DepthFirstSearch(char Source)
	{
		if (this->VertexQueue == NULL)
		{
			VertexQueue = new queue<VertexNODE*>;
		}
		VertexNODE* SourceVertex = searchVertex(Source);

		EdgeNODE* currentEdge = (EdgeNODE*)SourceVertex->header;
		while (currentEdge)
		{
			if (currentEdge->address->visited == false)
			{
				currentEdge->address->visited = true;
				VertexQueue->push(currentEdge->address);
			}

			currentEdge = currentEdge->nextEdge;
		}
		VertexNODE* temp = VertexQueue->front;
		VertexQueue->pop;
		DepthFirstSearch(temp->name);
		
	}*/

	void PrintGraph()
	{
		VertexNODE* current = this->root;
		while (current)
		{
			cout << endl;	
			cout << current->name << ":\t[ ";

			EdgeNODE *currentEdge = (EdgeNODE*)current->header;
			while (currentEdge)
			{
				cout << currentEdge->address->name << " ";
				currentEdge = currentEdge->nextEdge;
			}
			cout << "]"<<endl;
			current = current->nextVertex;
		}
	}

	

private:
	VertexNODE * root;
	bool HelperVariableForInsertEdge = 0;
	queue<VertexNODE*> *VertexQueue;
	

};

