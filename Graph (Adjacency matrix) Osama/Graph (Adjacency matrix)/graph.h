#include <iostream>
#include "stack.h"
#include "vertex.h"
#include "queue.h"
#include <string>
#include <algorithm>
using namespace std;

class graph{

public:

graph(int n)
{
  this->n = n;
  vertices = new Vertex[n];
  adjMatrix = new int *[n];
  for(int i=0;i<n;i++)
  {
    adjMatrix[i] = new int[n];
    for(int j=0;j<n;j++)
    {
      adjMatrix[i][j] = -1;
    }
  }
}

void addVertex(string name)
{
  static int count = 0;
  if(count < this->n)
  {
    this->vertices[count].setname(name);
    this->vertices[count].setnum(count);
    count++;  
  }
}

void addEdge(string v1, string v2,int weight)
{
   if(IsVertex(v1) && IsVertex(v2))
   {
     adjMatrix[SearchByname(v1)][SearchByname(v2)] = weight;
     adjMatrix[SearchByname(v2)][SearchByname(v1)] = weight;
   }
}


bool IsConnected(int v1,int v2)
{
  if(adjMatrix[v1][v2] != -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}



bool IsVertex(string name)
{
  int flag = 0;
  for(int i=0;i<this->n;i++)
  {
     if(vertices[i].getname() == name)
      {
        flag++;
        break;
      }
  }
  if(flag > 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}


int SearchByname(string name)
{
  int flag = 0,i;
  for(i=0;i<this->n;i++)
  {
     if(vertices[i].getname() == name)
      {
        flag++;
        break;
      }
  }
  if(flag > 0)
  {
    return i;
  }
  else
  {
    return -1;
  }
}

void Display()
{
  for(int i=0;i<this->n;i++)
  {
    cout<<"\nThe vertex "<<vertices[i].getname()<<" is connected with ";
    for(int j= 0 ;j<this->n;j++)
    {
      if(adjMatrix[i][j] != -1)
      {
        cout<<vertices[j].getname()<<" ";
      }
    }
    cout<<endl;
  }
}


string SearchBynum(int num)
{
  int flag = 0,i;
  for(i=0;i<this->n;i++)
  {
     if(vertices[i].getnum() == num)
      {
        flag++;
        break;
      }
  }
  if(flag > 0)
  {
    return vertices[i].getname();
  }
  else
  {
    return "";
  }
}

bool IsCycle(string src)
{
  if(constructPath(src,src) == "\n\nNo such path found.\n\n")
  {
    return false;
  }else{
    return true;
  }
}

bool IsCycleUnion(graph *grp)
{
   int *parent = new int [this->n];
   for(int i=0;i<this->n;i++)
   {
     parent[i] = -1;
   }
   for(int j=0;j<this->n;j++)
   {
     //int x = find(parent,);
   }

}

string Kruskal_MST(graph *g)
{
  string *SortedEdges = new string [this->n*this->n]; 
  SortedEdges = buildArray(SortedEdges,g);
  SortedEdges = SortEdges(SortedEdges,g);
}

string* buildArray(string *SortedEdges,graph *g)
{
    int k = 0;
    for(int i=0;i<this->n;i++)
    {
      for(int j=0;j<this->n;j++)
      {
        if(g->adjMatrix[i][j] != -1)
        {
           SortedEdges[k].push_back(SearchBynum(i)[0]);
           SortedEdges[k].push_back(SearchBynum(j)[0]);
           k++;
        }
      }
    }
    return SortedEdges;

}


string* SortEdges(string* SortEdges,graph *g)
{
  for(int i=0;i<this->n;i++)
  {
    int current = i;
    int min = Find_min(SortEdges,current);
    swap(SortEdges[current],SortEdges[min]);
     
  }
}

string constructPath(string source,string dest)
{  
  bool *visited = new bool [this->n];
  list *top = NULL;
  int flag=0;
  int src = vertices[SearchByname(source)].getnum();
  int destination = vertices[SearchByname(dest)].getnum();
  for(int i=0;i<this->n;i++)
  {
    if(adjMatrix[destination][i] != -1)
    flag++;

    visited[i] = false;
  }
   
   visited[src] = true;
   int current = src;

   if(adjMatrix[src][destination] != -1)
   {
    return vertices[src].getname() + " " + vertices[destination].getname();
   }
  int i=0;
  int firstNeigh = -1;
  while(!(AllVisited(visited)))
  {
      
      for(i=0;i<this->n;i++)
      {
        if(adjMatrix[current][i] != -1 && !visited[i])
        {
          if(src == destination && top->Isempty(top))
          {
            
            firstNeigh = i;
            
          }

          if(i ==src && current == firstNeigh)
          {
                continue;    
          }
          top->push(&top,current);
          visited[current] = true;
          current = i;
          i=0;
          break;
        }
      }

      if(current == destination)
      {
        top->push(&top,current);
        i++;
        break;
      }
      
      if(src == destination)
      {
        visited[src] = false;
      }

      if(i>0)
      {
        visited[current] = true;
        current = top->pop(&top);
      }
      if(top->Isempty(top))
      {
        break;
      }
  }
  if(top->peak_stack(top) != destination || top->Isempty(top))
  {
    return "\n\nNo such path found.\n\n";
  }
  
  string path;
  list *top2 = NULL;
  while(!(top->Isempty(top)))
  {  
    top2->push(&top2,top->pop(&top));  
  }

  while(!(top2->Isempty(top2)))
  path = path + SearchBynum(top2->pop(&top2)) + " ";
  return path;
}


string DFS_Traversal(graph *G)
{
  bool *visited = new bool [this->n];
  list *top = NULL;
  string path = "";
  int flag=0;
  int src = vertices[SearchByname("A")].getnum();
    for(int i=0;i<this->n;i++)
  {
    if(adjMatrix[src][i] != -1)
    flag++;

    visited[i] = false;
  }
	if(flag == 0)
	{
		exit(-1);
		system("pause");
	}
   visited[src] = true;
   int current = src;
   int i=0;
   path.push_back(SearchBynum(current)[0]);
  while(!(AllVisited(visited)))
  {
      
      for(i=0;i<this->n;i++)
      {
		   if(!repeated(path,current))
		  {
        path.push_back(' ');
			  path.push_back(SearchBynum(current)[0]);
		  }
        if(adjMatrix[current][i] != -1 && !visited[i])
        {
          top->push(&top,current);
          visited[current] = true;
          current = i;
          i=0;
          break;
        }
      }

      if(i>0)
      {
        visited[current] = true;
        current = top->pop(&top);
      }
  }

  return path;
}


bool repeated(string path, int num){
	int flag = 0;
	for(int i=0;i<path.length();i++)
	{
		if(path[i] == SearchBynum(num)[0])
		{
			flag++;
			break;
		}
	}
	if(flag > 0)
	{
		return true;
	}else
	{
		return false;
	}

}

string BFS_Traversal(graph *g)
{
  bool *visited = new bool [this->n];
  Queue *front = NULL;
  Queue *rear = NULL;
  string path = "";
  int flag=0;
  int src = vertices[SearchByname("A")].getnum();
    for(int i=0;i<this->n;i++)
  {
    if(adjMatrix[src][i] != -1)
    flag++;

    visited[i] = false;
  }
	if(flag == 0)
	{
		exit(-1);
		system("pause");
	}
   visited[src] = true;
   int current = src;
  int i=0;
  front->Enqueue(&front,&rear,current);
  while(!(AllVisited(visited)) || !(front->Is_empty(front,rear)))
  {
      
      for(i=0;i<this->n;i++)
      {
        if(adjMatrix[current][i] != -1 && !visited[i])
        {
          front->Enqueue(&front,&rear,i);
          visited[current] = true;
        }
      }

      if(!repeated(path,current))
		  {
			path.push_back(SearchBynum(front->Dequeue(&front,&rear))[0]);
		  }
      current = front->Dequeue(&front,&rear);
      if(!repeated(path,current))
      {
      path.push_back(SearchBynum(current)[0]);
      visited[current] = true;
      }
  }

  return path;
}


bool AllVisited(bool *visited)
{
  int flag = 0;
  for(int i=0;i<this->n;i++)
  {
    if(visited[i] == false)
    {
      flag++;
      break;
    }
  }
  if(flag == 0)
  {
    return true;
  }else{
    return false;
  }
}

private:
int n;
int **adjMatrix;
Vertex *vertices;
};
