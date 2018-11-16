#include <iostream>
#include "N-aryTree.h"

using namespace std;

int main()
{
	NTNODE *root = NULL;
	N_aryTree myTree;

	myTree.insert(1, 3, &root);
	myTree.insert(2, 3, &root);
	myTree.insert(3, 3, &root);
	myTree.insert(4, 3, &root);
	myTree.insert(5, 3, &root);
	myTree.insert(6, 3, &root);
	myTree.insert(7, 3, &root);
	myTree.insert(8, 3, &root);
	myTree.insert(9, 3, &root);
	myTree.insert(0, 3, &root);
	cout << "\t\t" << root->value << endl;
	cout << "\t" << root->children[0]->value << "\t" << root->children[1]->value << "\t" << root->children[2]->value << endl;


	system("pause");
}