#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *b_link, *f_link;
};
struct node *start = NULL;
struct node* createnode()
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	return(temp);
};
void insertnode()
{
	struct node *temp = createnode(), *t;
	printf("\nEnter value: ");
	scanf("%d", &temp->info);
	temp->f_link = NULL;
	if (start == NULL)
	{
		start = temp;
		temp->b_link = NULL;
	}
	else
	{
		t = start;
		while (t->f_link != NULL)
		{
			t = t->f_link;
		}
		t->f_link = temp;
		temp->b_link = t;
	}
}
void fprint()
{
	if (start == NULL)
		printf("\nList is empty\n");
	else
	{
		struct node *temp = start;
		while (temp != NULL)
		{
			printf("%d  ", temp->info);
			temp = temp->f_link;
		}
	}
}
void bprint()
{
	if (start == NULL)
		printf("List is empty");
	else
	{
		struct node *temp = start;
		while (temp->f_link != NULL)
			temp = temp->f_link;
		while (temp != NULL)
		{
			printf("%d ", temp->info);
			temp = temp->b_link;
		}
	}
}
void searchnode()
{
	if (start == NULL)
		printf("\nList is empty");
	else
	{
		printf("\nEnter value to search: ");
		int val, count = 0, t = 0;
		scanf("%d", &val);
		struct node *temp = start;
		while (temp != NULL)
		{
			count++;
			if (temp->info == val)
			{
				printf("\nValue found at position: %d\n", count);
				t++;
				break;
			}
			temp = temp->f_link;
		}
		if (t == 0)
			printf("\nValue not in list\n");
	}
}
int length()
{
	struct node *temp = start;
	int l = 0;
	while (temp != NULL)
	{
		l++;
		temp = temp->f_link;
	}
	return(l);
}
void deletenode()
{
	if (start == NULL)
		printf("\nList is empty");
	else
	{
		int del;
		printf("\nEnter position of value to delete: ");
		scanf("%d", &del);
		while (del>length())
		{
			printf("\nRe-enter choice: ");
			scanf("%d", &del);
		}
		if (del == 1)
		{
			struct node *temp = start;
			start = temp->f_link;
			temp->f_link = NULL;
			temp->b_link = NULL;
			free(temp);
		}
		else
		{
			struct node *temp = start;
			int i;
			for (i = 1; i<del; i++)
			{
				temp = temp->f_link;
			}
			(temp->b_link)->f_link = temp->f_link;
			if (del == length())
				(temp->f_link)->b_link = temp->b_link;
			temp->b_link = temp->f_link = NULL;
			free(temp);
		}
	}
}
void swap()
{
	if (start == NULL)
		printf("\nList is empty");
	else if (start->f_link == NULL)
		printf("\nThere`s only one element in list");
	else
	{
		int loc1, loc2, i, j;
		printf("Enter position of value 1:");
		scanf("%d", &loc1);
		while (loc1>length() || loc1<1)
		{
			printf("Re-enter position:");
			scanf("%d", &loc1);
		}
		printf("\nEnter position of value 2:");
		scanf("%d", &loc2);
		while (loc2>length() || loc2<1)
		{
			printf("Re-enter choice:");
			scanf("%d", &loc2);
		}
		struct node *p1 = start, *p2 = start;
		if (loc1 == 1 && loc2 - loc1 == 1)
		{
			p2 = p1->f_link;

			start = p2;
			p1->f_link = p2->f_link;
			p2->f_link = p1;

			p2->b_link = NULL;
			p1->b_link = p2;
			(p1->f_link)->b_link = p1;
		}
		else if (loc1 == 1 && loc2 - loc1 != 1)
		{
			for (i = 1; i<loc2; i++)
				p2 = p2->f_link;

			start = p2;
			p2->f_link = p1->f_link;
			(p2->b_link)->f_link = p1;

			p1->b_link = p2->b_link;
			p2->b_link = NULL;
			(p2->f_link)->b_link = p2;

			if (p1->f_link != NULL)
			{
				struct node *temp = p2->f_link;
				p1->f_link = temp;
				temp->b_link = p1;
			}
			else
				p1->f_link = NULL;
		}
		else if (loc1 != 1 && loc2 - loc1 == 1)
		{
			for (i = 1; i<loc1; i++)
				p1 = p1->f_link;
			p2 = p1->f_link;

			(p1->b_link)->f_link = p2;
			p1->f_link = p2->f_link;
			p2->f_link = p1;

			p2->b_link = p1->b_link;
			p1->b_link = p2;
			(p1->f_link)->b_link = p1;
		}
		else if (loc1 != 1 && loc2 - loc1 != 1)
		{
			for (i = 1; i<loc1; i++)
				p1 = p1->f_link;
			for (j = 1; j<loc2; j++)
				p2 = p2->f_link;
			struct node *temp1 = p1->b_link;

			temp1->f_link = p2;
			p2->f_link = p1->f_link;
			(p2->b_link)->f_link = p1;

			p1->b_link = p2->b_link;
			p2->b_link = temp1;
			(p2->f_link)->b_link = p2;

			if (p1->f_link != NULL)
			{
				struct node *temp2 = p2->f_link;
				p1->f_link = temp2;
				temp2->b_link = p1;
			}
			else
				p1->f_link = NULL;
		}
	}
}
void insertionsort()
{
	if (start == NULL)
		printf("\nList is empty");
	else if (start->f_link == NULL)
		printf("\nThere`s only one element in last");
	else
	{
		struct node *p1 = start, *p2 = start->f_link;
		int N = length(), i, j, k, c = 0;
		for (i = 1; i<N; i++)
		{
			for (j = i - 1; j >= 0 && p2->info<p1->info; j--)
			{
				c++;
				if (p1 == start)
				{
					start = p2;
					p1->f_link = p2->f_link;
					p2->f_link = p1;

					p2->b_link = NULL;
					p1->b_link = p2;
					(p1->f_link)->b_link = p1;
				}
				else
				{
					(p1->b_link)->f_link = p2;
					p1->f_link = p2->f_link;
					p2->f_link = p1;

					p2->b_link = p1->b_link;
					p1->b_link = p2;
					(p1->f_link)->b_link = p1;
				}

				p1 = p1->b_link;
				p2 = p2->f_link;

				p1 = p1->b_link;
				p2 = p2->b_link;
			}
			for (k = 1; k <= c + 1; k++)
				p2 = p2->f_link;
			p1 = p2->b_link;
			c = 0;
		}
	}
}
int menu()
{
	int ch;
	printf("\n\n1:Add value to the list");
	printf("\n2:Delete value");
	printf("\n3:View list forwards");
	printf("\n4:View List backwards");
	printf("\n5:Search Value");
	printf("\n6:Swap Values");
	printf("\n7:Sort(Ascending)");
	printf("\nEnter choice: ");
	scanf("%d", &ch);
	return(ch);
}
int main()
{
	while (1)
	{
		switch (menu())
		{
		case 1:
			insertnode();
			break;
		case 2:
			deletenode();
			break;
		case 3:
			fprint();
			break;
		case 4:
			bprint();
			break;
		case 5:
			searchnode();
			break;
		case 6:
			swap();
			break;
		case 7:
			insertionsort();
			break;
		default:
			printf("\nInvalid choice\n");
		}
	}
}
