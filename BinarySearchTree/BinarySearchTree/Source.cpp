#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
	BSTNODE *root = NULL;;
	BST myTree;

	myTree.Insert(15, &root);
	myTree.Insert(10, &root);
	myTree.Insert(20, &root);
	myTree.Insert(17, &root);
	myTree.Insert(19, &root);
	myTree.Insert(21, &root);
	myTree.Insert(18, &root);
	myTree.Insert(12, &root);
	myTree.PrintTree(root);

	//cout << root->Right->Left->Right->value << endl;
	myTree.Search(22, root);


	cout << "\n\n------------------------------------\n\n";
	//myTree.DeleteNode(15, &root);
	myTree.InorderTaversal(root);

	cout << "\n\n------------------------------------\n\n";
	myTree.PreorderTaversal(root);

	cout << "\n\n------------------------------------\n\n";
	myTree.PostorderTaversal(root);

	myTree.DeleteBSTNODE(15, &root);

	cout << "\n\n DELETED TREE:\n\n";
	myTree.InorderTaversal(root);

	//myTree.PrintTree(root);
	system("pause");
}