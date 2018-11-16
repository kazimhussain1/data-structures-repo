#include <iostream>
#include<stdlib.h>
using namespace std;



struct adjNode
{
	char value;
	adjNode *next;
	struct adjlist *header;
};
struct adjlist
{
	adjNode *edge;
	adjlist *next;
};


void insertNode(adjNode **start, char value)
{
	//cout << "Enter AdjNode\n";
	adjNode *ptr;
	ptr = (adjNode *)malloc(sizeof(adjNode));
	ptr->value = value;
	ptr->next = NULL;
	ptr->header = NULL;

	if (*start == NULL)
		*start = ptr;
	else
	{
		adjNode *curr = *start;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = ptr;
	}
	
}

adjNode* searchVertex(adjNode *start, char value)
{   
	
	adjNode *curr = start;
	while (curr->value != value)
	{
		curr = curr->next;
	}
	if (curr == NULL)
		return NULL;
	else
		return curr;
}


void  insertList(adjNode **start)
{
	cout << "\n--------------EDGES-------------\n";
	adjNode *sourcePointer , *destPointer;
	adjlist *ptr;
	char source, destination;
	cout << "Enter Source: ";
	cin  >> source;
	cout << "Enter Destination: ";
	cin  >> destination;

	sourcePointer = searchVertex(*start, source);
	destPointer = searchVertex(*start, destination);
	if (sourcePointer == NULL || destPointer == NULL)
	{
		cout << "WRONG INPUT\n";
		return;
	}
	
	else
	{    
		ptr = (adjlist *)malloc(sizeof(adjlist));
		ptr->edge = destPointer;
		ptr->next = NULL;
		if (sourcePointer->header == NULL)
		{
			sourcePointer->header = ptr;
		}
		else
		{
			adjlist *curr = sourcePointer->header;
			while (curr->next != NULL)
				curr = curr->next;

			curr->next = ptr;
		}
		
	}

}

void outdegree(adjNode *start, char value)
{
	int degree = 0;
	adjNode *temp=start, *vertex = searchVertex(start, value);
	while (vertex->header != NULL)
	{
		vertex->header = vertex->header->next;
		degree++;
	}
	cout << "\n---------------degree------------------\n";
	cout << "degree: " << degree;
	start = temp;
}

void display(adjNode *start)
{
	cout << "\n--------------Display Adjacency Matrix--------\n";
	adjNode *curr = start, *temp = start; ;
	while (curr != NULL)
	{
		cout << curr->value << "| ";
		while (curr->header != NULL)
		{
			cout << curr->header->edge->value<< "->";
			curr->header = curr->header->next;
		}
		cout << "NULL" << endl;
		curr = curr->next;
	}
	start = temp;
}


int main()
{
	adjNode *start = NULL;
	insertNode(&start, 'A');
	insertNode(&start, 'B');
	insertNode(&start, 'C');
	insertNode(&start, 'D');
	insertList(&start);
	insertList(&start);
	insertList(&start);
	insertList(&start);
	display(start);
	outdegree(start, 'A');
	display(start);
	//cout << start->header->edge->value;

	system("pause");
}