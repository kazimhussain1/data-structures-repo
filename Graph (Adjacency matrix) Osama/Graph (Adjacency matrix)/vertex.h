#include <iostream>
using namespace std;

class Vertex{
public:
Vertex()
{
  this->name = "";
  this->num = 0;
}

Vertex(string name, int num)
{
  this->name = name;
  this->num = num;
}

int getnum()
{
  return num;
}

string getname()
{
  return name;
}

void setname(string name)
{
  this->name = name;
}

void setnum(int num)
{
  this->num = num;
}


void Display()
{
  cout<<endl<<this->name<<" "<<this->num<<endl;
}

private:
string name;
int num;
};