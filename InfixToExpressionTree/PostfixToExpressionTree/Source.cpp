#include <iostream>
#include <stack>
#include "InfixToPostfix.h"
#include "BinarySearchTree.h"

using namespace std;

BSTNODE* PostfixToExpressionTree(string Postfix)
{
	stack<BSTNODE*> NODEStack;
	BSTNODE *temp = NULL;
	for (size_t i = 0; i < Postfix.length(); i++)
	{
		if (Postfix[i] >= 'a' && Postfix[i]<= 'z') 
		{
			temp = new BSTNODE;
			temp->value = Postfix[i];
			temp->Left = NULL;
			temp->Right = NULL;
			NODEStack.push(temp);
		}
		else
		{
			temp = new BSTNODE;
			temp->value = Postfix[i];
			temp->Right = NODEStack.top();
			NODEStack.pop();
			temp->Left = NODEStack.top();
			NODEStack.pop();
			NODEStack.push(temp);
		}
	}
	return temp;
}

int main()
{
	string Infix = /*"(a+b-(b*c)/d-(a+b))<(x+y)&c!e+b"*/"a+(b*c-(d+e*f/d-e)+(x+y*c))";

	string Postfix = InfixToPostfix(Infix);

	BSTNODE *myTree = PostfixToExpressionTree(Postfix);

	BST myBST;

	cout << "PostOrder: ";
	myBST.PostorderTaversal(myTree);
	cout << endl << "PreOrder:  ";
	myBST.PreorderTaversal(myTree);
	cout << endl;
	//myBST.InorderTaversal(myTree);
	//cout << endl;

	system("pause");
}
