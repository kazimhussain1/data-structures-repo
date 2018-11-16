#include <iostream>


using namespace std;

struct BSTNODE
{
	int value;
	BSTNODE *Left;
	BSTNODE *Right;
};

class BST
{
public:
	void Insert(int value, BSTNODE** root)
	{
		BSTNODE *temp = (BSTNODE*)malloc(sizeof(BSTNODE));
		temp->value = value;
		temp->Left = NULL;
		temp->Right = NULL;

		if (!(*root))
		{
			*root = temp;
		}
		else if ((*root)->value > value)
		{
			Insert(value, &((*root)->Left));
		}
		else if ((*root)->value < value)
		{
			Insert(value, &((*root)->Right));
		}
	}
	BSTNODE* Search(int value, BSTNODE *root)
	{
		if (root == NULL)
		{
			cout << "Not Found" << endl;
			return NULL;
		}
		else if (root->value == value)
		{
			cout << "Found" << endl;
			return root;
		}
		else if (root->value > value)
		{
			return Search(value, root->Left);
		}
		else if (root->value < value)
		{
			return Search(value, root->Right);
		}
		else
		{
			return NULL;
		}

	}
	void DeleteBSTNODE(int value, BSTNODE **root)
	{
		BSTNODE *current = *root, *previous = NULL;
	
		while (current != NULL && current->value != value)
		{
			if (current->value > value)
			{
				previous = current;
				current = current->Left;

			}
			else if (current->value < value)
			{
				previous = current;
				current = current->Right;
			}
		}


		if (current == NULL)
		{
			cout << "No such value exists" << endl;
		}
		else if (current->value == value)
		{
			if (current->Left == NULL && current->Right == NULL)
			{
				if (previous->Left == current)
				{
					previous->Left = NULL;
					free(current);
				}
				else
				{
					previous->Right = NULL;
					free(current);
				}
			}
			else if (current->Left != NULL && current->Right != NULL)
			{
				BSTNODE *LeftSubTree = current->Left;
				BSTNODE *temp = LeftSubTree;
				int Greatest = temp->value;
				while (temp->Right != NULL)
				{
					temp = temp->Right;
					if (Greatest < temp->value)
					{
						Greatest = temp->value;
					}
				}

				current->value = Greatest;
				DeleteBSTNODE(Greatest, &LeftSubTree);

			}
			else if (current->Left != NULL)
			{
				if (previous->Left == current)
				{
					previous->Left = current->Left;
					free(current);
				}
				else
				{
					previous->Right = current->Left;
					free(current);
				}
			}
			else if (current->Right != NULL)
			{
				if (previous->Left == current)
				{
					previous->Left = current->Right;
					free(current);
				}
				else
				{
					previous->Right = current->Right;
					free(current);
				}
			}
		}
	}

	void InorderTaversal(BSTNODE *root)
	{
		if (root->Left)
		{
			InorderTaversal(root->Left);
		}
		cout << root->value << " ";
		if (root->Right)
		{
			InorderTaversal(root->Right);
		}
	}
	void PreorderTaversal(BSTNODE *root)
	{
		cout << root->value << " ";
		if (root->Left)
		{
			PreorderTaversal(root->Left);
		}
		if (root->Right)
		{
			PreorderTaversal(root->Right);
		}

	}
	void PostorderTaversal(BSTNODE *root)
	{
		if (root->Left)
		{
			PostorderTaversal(root->Left);
		}
		if (root->Right)
		{
			PostorderTaversal(root->Right);
		}
		cout << root->value << " ";
	}


	void PrintTree(BSTNODE *root)
	{
		if (root)
		{
			/*cout << root->value << endl;
			if (root->Left != NULL)
			{
			PrintTree(root->Left);
			}
			if (root->Right != NULL)
			{
			PrintTree(root->Right);
			}*/
			PrintTree(root->Left);
			cout << root->value << " ";
			PrintTree(root->Right);

		}
	}





private:

};
