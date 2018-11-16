#include <iostream>
//#include "LinkedList.h"

using namespace std;

struct NTNODE
{
	int value;
	int n;
	NTNODE** children;
};

class N_aryTree
{
public:
	bool insert(int value, int NumOfChildren, NTNODE** parent)
	{
		NTNODE *temp = new NTNODE;
		temp->value = value;
		temp->n = NumOfChildren;
		temp->children = new NTNODE*[NumOfChildren];
		for (int i = 0; i < NumOfChildren; i++)
		{
			temp->children[i] = NULL;
		}

		if (*parent == NULL)
		{
			*parent = temp;
			return true;
		}
		else
		{
			int flag = 0;
			for (int i = 0; i < (*parent)->n; i++)
			{
				if ((*parent)->children[i] == NULL)
				{
					(*parent)->children[i] = temp;
					flag = 1;
					return true;
					break;
				}
			}
			if (flag == 0)
			{
				bool check = false;
				int i = 0;
				while (i< (*parent)->n && check == false)
				{	
					check = insert(value, NumOfChildren, &((*parent)->children[i]));
					i++;
				}
			}
			
		}

	}



private:

};
