#include<iostream>
#include<vector>
//#include"stack.h"

using namespace std;

struct VertexNODE
{
	char name;
	bool visited = false;
	void *header = NULL;
	int count = 0;
	int distance = WINT_MAX;
	char previous = 0;
	VertexNODE* nextVertex = NULL;
};
struct EdgeNODE
{
	char Source;
	VertexNODE* address = NULL;
	int weight = 1;
	bool picked = false;
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

	VertexNODE* getRoot()
	{
		return this->root;
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

	void InsertEdge(char VertexName, char EdgeName, int weight = 1)
	{
		EdgeNODE *temp = new EdgeNODE();

		VertexNODE *Vertex = searchVertex(VertexName);
		VertexNODE *Edge = searchVertex(EdgeName);

		temp->Source = VertexName;
		temp->address = Edge;
		temp->weight = weight;
		temp->picked = false;
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
		this->NumOFEdges++;
		if (HelperVariableForInsertEdge == 0)
		{
			HelperVariableForInsertEdge = !HelperVariableForInsertEdge;
			InsertEdge(EdgeName, VertexName, weight);
		}
		else// (HelperVariableForInsertEdge == 1)
		{
			HelperVariableForInsertEdge = !HelperVariableForInsertEdge;
		}
	}
	void InsertEdgeDirected(char VertexName, char EdgeName, int weight = 1)
	{
		EdgeNODE *temp = new EdgeNODE();

		VertexNODE *Vertex = searchVertex(VertexName);
		VertexNODE *Edge = searchVertex(EdgeName);

		temp->Source = VertexName;
		temp->address = Edge;
		temp->weight = weight;
		temp->picked = false;
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
		this->NumOFEdges++;
		
	}

	void InsertEdge(char VertexName, EdgeNODE* myEdge)
	{
		VertexNODE *Vertex = searchVertex(VertexName);
	

		if (Vertex->header == NULL)
		{
			Vertex->header = myEdge;
		}
		else
		{
			EdgeNODE *current = (EdgeNODE*)Vertex->header;
			while (current->nextEdge != NULL)
			{
				current = current->nextEdge;
			}
			current->nextEdge = myEdge;
		}
		Vertex->count++;
		this->NumOFEdges++;
		if (HelperVariableForInsertEdge == 0)
		{
			HelperVariableForInsertEdge = !HelperVariableForInsertEdge;
			InsertEdge(myEdge->address->name, VertexName);
		}
		else// (HelperVariableForInsertEdge == 1)
		{
			HelperVariableForInsertEdge = !HelperVariableForInsertEdge;
		}
	}
	void Delete(char VertexName, char Edge)
	{
		VertexNODE* myVertex = searchVertex(VertexName);
		EdgeNODE *previous, *current = (EdgeNODE*)myVertex->header ;
		int flag = 0;
		if (current->address->name == Edge)
		{
			EdgeNODE *temp = (EdgeNODE*)myVertex->header;
			myVertex->header = ((EdgeNODE*)myVertex->header)->nextEdge;
			free(temp);
		}
		else
		{
			previous = (EdgeNODE*)myVertex->header;
			current = ((EdgeNODE*)myVertex->header)->nextEdge;

			while (current->nextEdge != NULL)
			{
				if (current->address->name == Edge)
				{
					break;
				}
				previous = previous->nextEdge;
				current = current->nextEdge;
			}
			if (current->address->name == Edge)
			{
				previous->nextEdge = current->nextEdge;
				free(current);
			}
			else
			{
				cout << "No such value exists" << endl;
			}
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

	
	//BubbleSort
	


	//------------------------------- S H O R T E S T    P A T H    A L G O R I T H M S -------------------------------
	
	Graph* KrushkalsMST()
	{
		ResetVisited();
		ResetPickedEdge();

		Graph * newGraph = new Graph;

		this->SortAllByWeight();

		VertexNODE* currentVertex = this->root;
		while (currentVertex)
		{
			newGraph->InsertVertex(currentVertex->name);

			currentVertex = currentVertex->nextVertex;
		}

		for (int i = 0; i < this->NumOFEdges; i++)
		{
			EdgeNODE* MinimumEdge = LeastWeightEdge();
			VertexNODE* myVertex = newGraph->searchVertex(MinimumEdge->Source);
			
			EdgeNODE* ptr = (EdgeNODE*)myVertex->header;
			bool flag = true;
			while (ptr)
			{
				if (ptr->address->name == MinimumEdge->address->name)
				{
					flag = false;
				}

				ptr = ptr->nextEdge;
			}
			
			if (flag == true)
			{
				newGraph->InsertEdge(MinimumEdge->Source, MinimumEdge->address->name, MinimumEdge->weight);
			}
			string path = newGraph->Cycle(myVertex->name);

			if (path != "No Cycle")
			{
				newGraph->Delete(myVertex->name, MinimumEdge->address->name);
				newGraph->Delete(MinimumEdge->address->name, myVertex->name);
			}
		}
		ResetPickedEdge();
		return newGraph;
	}

	Graph* PrimsMST()
	{
		this->ResetVisited();
		this->ResetPickedEdge();

		Graph * newGraph = new Graph;
		this->SortAllByWeight();
		this->ResetVisited();

		VertexNODE* currentVertex = this->root;
		while (currentVertex)
		{
			newGraph->InsertVertex(currentVertex->name);
			

			currentVertex = currentVertex->nextVertex;
		}


		for (int i = 0; i < NumOFEdges; i++)
		{			
			currentVertex = this->root;
			currentVertex->visited = true;

			EdgeNODE* LeastWeight = new EdgeNODE;
			LeastWeight->weight = INT16_MAX;

			while (currentVertex)
			{
				if (currentVertex->visited = true)
				{
					EdgeNODE* currentEdge = (EdgeNODE*)currentVertex->header;
					while (currentEdge)
					{
						if (currentEdge->weight < LeastWeight->weight && currentEdge->picked == false)
						{
							LeastWeight = currentEdge;
						}

						currentEdge = currentEdge->nextEdge;
					}
				}
				currentVertex = currentVertex->nextVertex;
			}
			VertexNODE* myVertex = newGraph->searchVertex(LeastWeight->Source);

			

			if (myVertex == NULL)
			{
				newGraph->InsertEdge(LeastWeight->Source, LeastWeight->address->name, LeastWeight->weight);
			}
			else
			{
				EdgeNODE* ptr = (EdgeNODE*)myVertex->header;
				bool flag = true;

				while (ptr)
				{
					if (ptr->address->name == LeastWeight->address->name)
					{
						flag = false;
					}

					ptr = ptr->nextEdge;
				}

				if (flag == true)
				{
					newGraph->InsertEdge(LeastWeight->Source, LeastWeight->address->name, LeastWeight->weight);
				}
			}
			string path = newGraph->Cycle(myVertex->name);

			if (path != "No Cycle")
			{
				newGraph->Delete(myVertex->name, LeastWeight->address->name);
				newGraph->Delete(LeastWeight->address->name, myVertex->name);
			}
			else
			{
				LeastWeight->address->visited = true;
			}
		
			LeastWeight->picked = true;


		}
		return newGraph;
	}

	string DjikstraShortestPath(char Source, char Destination)
	{
		VertexNODE* SourceVertex = searchVertex(Source);
		VertexNODE* DestinationVertex = searchVertex(Destination);

		ResetPickedEdge();
		ResetVisited();

		SourceVertex->distance = 0;
		SourceVertex->visited = true;

		VertexNODE* currentVertex = SourceVertex;
		EdgeNODE* MaxDistance = new EdgeNODE;
		
		VertexNODE* temp = new VertexNODE;
		temp->distance = WINT_MAX;

		MaxDistance->address = temp;

		for (int i=0 ; i < NumOFEdges; i++)
		{
			EdgeNODE* currentEdge = (EdgeNODE*)currentVertex->header;
			while (currentEdge)
			{
				if (currentVertex->distance + currentEdge->weight < currentEdge->address->distance)
				{
					currentEdge->address->distance = currentVertex->distance + currentEdge->weight;
					currentEdge->address->previous = currentVertex->name;
					currentEdge->picked = true;
				}
				currentEdge = currentEdge->nextEdge;
			}

			currentVertex = SourceVertex;
			EdgeNODE* MinimumVertex = MaxDistance;

			while (currentVertex)
			{
				if (currentVertex->visited = true)
				{
					EdgeNODE* currentEdge = (EdgeNODE*)currentVertex->header;
					while (currentEdge)
					{
						if (currentEdge->address->distance < MinimumVertex->address->distance && currentEdge->picked == false)
						{
							MinimumVertex = currentEdge;
;
						}
						currentEdge = currentEdge->nextEdge;
					}
				}
				currentVertex = currentVertex->nextVertex;
			}
			MinimumVertex->picked = true;
			MinimumVertex->address->visited = true;
			currentVertex = MinimumVertex->address;
			
			if (AllVisited())
			{
				break;
			}
		}
		string path;
		VertexNODE* myVertex = DestinationVertex;
		while (myVertex->previous != 0)
		{
			path = myVertex->name + path;
			myVertex = searchVertex(myVertex->previous);
		}
		path = myVertex->name + path;
		return path;
	}


	//------------------------------- U T I L I T Y    F U N C T I O N S -------------------------------

	EdgeNODE* LeastWeightEdge()
	{
		VertexNODE* currentVertex = root;
		
		EdgeNODE* LeastWeight = new EdgeNODE;
		LeastWeight->weight = 65000;

		while (currentVertex)
		{
			EdgeNODE* currentEdge = (EdgeNODE*)currentVertex->header;

			while (currentEdge)
			{
				if (currentEdge->weight < LeastWeight->weight && currentEdge->picked == false)
				{
					LeastWeight = currentEdge;
				}

				currentEdge = currentEdge->nextEdge;
			}

			currentVertex = currentVertex->nextVertex;
		}
		LeastWeight->picked = true;
		return LeastWeight;
	}

	void SortEdgesByWeight(char Vertex)
	{
		VertexNODE *myVertex = searchVertex(Vertex);
		if (myVertex->header == NULL)
		{
			cout << "Empty List" << endl;
		}
		else if (((EdgeNODE*)myVertex->header)->nextEdge == NULL)
		{
			cout << "Can't sort only one element." << endl;
		}
		else
		{

			for (int i = 0; i < myVertex->count; i++)
			{
				EdgeNODE *previous, *current = (EdgeNODE*)myVertex->header;
				if (current->weight > current->nextEdge->weight)
				{
					EdgeNODE *temp = ((EdgeNODE*)myVertex->header)->nextEdge;
					((EdgeNODE*)myVertex->header)->nextEdge = temp->nextEdge;
					temp->nextEdge = (EdgeNODE*)myVertex->header;
					myVertex->header = temp;
				}

				previous = (EdgeNODE*)myVertex->header;
				current = ((EdgeNODE*)myVertex->header)->nextEdge;
				while (current)
				{
					if (current->nextEdge != NULL)
					{
						if (current->weight > current->nextEdge->weight)
						{
							EdgeNODE *temp1, *temp2;
							temp1 = current->nextEdge;
							temp2 = temp1->nextEdge;

							previous->nextEdge = temp1;
							temp1->nextEdge = current;
							current->nextEdge = temp2;
						}
						else
						{
							current = current->nextEdge;

						}
						previous = previous->nextEdge;
					}
					else
					{
						current = current->nextEdge;
					}
				}
			}

		}
	}
	void SortAllByWeight()
	{
		VertexNODE * current = this->root;

		while (current)
		{
			SortEdgesByWeight(current->name);

			current = current->nextVertex;
		}
	}

	bool AllVisited()
	{
		VertexNODE* currentVertex = this->root;
		bool flag = true;
		while (currentVertex)
		{
			EdgeNODE* currentEdge = (EdgeNODE*)currentVertex->header;

			while (currentEdge)
			{
				if (currentEdge->picked == false)
				{
					flag = false;
					break;
				}
				currentEdge = currentEdge->nextEdge;
			}
			currentVertex = currentVertex->nextVertex;
		}
		return flag;
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

	void ResetPickedEdge()
	{
		VertexNODE* currentVertex = this->root;

		while (currentVertex)
		{
			EdgeNODE* currentEdge = (EdgeNODE*)currentVertex->header;

			while (currentEdge)
			{
				currentEdge->picked = false;

				currentEdge = currentEdge->nextEdge;
			}
			currentVertex = currentVertex->nextVertex;
		}
	}

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
				cout << currentEdge->address->name << "(" << currentEdge->weight << ") ";
				currentEdge = currentEdge->nextEdge;
			}
			cout << "]" << endl;
			current = current->nextVertex;
		}
	}

	

private:
	VertexNODE * root;
	bool HelperVariableForInsertEdge = 0;
	int NumOFEdges = 0;
	

};

