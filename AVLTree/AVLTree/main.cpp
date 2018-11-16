#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
	 Tree T;
	 Tree *root = NULL;
	 root = T.insert_node(&root,NULL,135);
	 root = T.insert_node(&root,NULL,120);
	 root = T.insert_node(&root,NULL,30);
	 root = T.insert_node(&root,NULL,60);
	 root = T.insert_node(&root,NULL,20);
	 root = T.insert_node(&root,NULL,18); 
	 root = T.insert_node(&root,NULL,75);
	 root = T.insert_node(&root,NULL,87);
	 //root = T.insert_node(&root,NULL,56); 
	// root = T.insert_node(&root,NULL,93);
	 //root = T.insert_node(&root,NULL,150);
	 //root = T.insert_node(&root,NULL,22); 
	 //root = T.insert_node(&root,NULL,69);
	 //root = T.insert_node(&root,NULL,70);
	 //root = T.insert_node(&root,NULL,74); 
  
	system("pause");	
}