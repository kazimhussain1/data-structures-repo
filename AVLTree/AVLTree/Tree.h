#include <iostream>
#include <cmath>
using namespace std;

class Tree{
public:

Tree()
{
  this->value=0;
  this->left= NULL;
  this->right= NULL;
}

Tree* insert_node(Tree **root,Tree *Parent,int val)
{
  Tree *curr= *root;
  if(*root==NULL)
  {
    Tree *ptr= NULL;
    ptr= (Tree*)malloc(sizeof(Tree));
    ptr->value= val;
    ptr->right= NULL;
    ptr->left= NULL;
    ptr->hLeft = 0;
    ptr->hRight = 0;
    ptr->fromLeft = false;
    ptr->fromRight = false;
    ptr->parent = Parent;
    *root= ptr;
    Tree* temp = MaintainHeight(ptr);
    if(temp->parent == NULL)
    {
      return temp;
    }
    
  }
  else
  {
      Tree* temp;
    if(val>curr->value)
    {
    
     temp = insert_node(&(curr->right),curr,val);
     if(temp->parent == NULL)
     return temp;
    }
    else
    {
      if(val<curr->value)
      {
      temp = insert_node(&(curr->left),curr,val);
      if(temp->parent == NULL)
      return temp;
    }
    }
  }
  return *root;
}



void search_node(Tree *root,int search)
{
  Tree *curr= root;
  if(root==NULL)
  {
    cout<<"\n\nNo such node found in tree.\n\n";
    return;
  }
  if(root->value==search)
  {
    cout<<"\n\nNode is present in the tree.\n";
  }
  else
  {
    if(search>curr->value)
    {
      search_node(curr->right,search);
    }
    else
    {
      if(search<curr->value)
      {
      search_node(curr->left,search);
    }
    }
  }
}


Tree* MaintainHeight(Tree *curr)
{
      if(curr)
      {  
      if(curr->parent)
      {
        if(curr->parent->left == curr)
        {
          if(curr->parent->hLeft <= curr->hLeft || curr->parent->hLeft <= curr->hRight)
           curr->parent->hLeft++;
        }

        if(curr->parent->right == curr)
        {
           if(curr->parent->hRight <= curr->hRight || curr->parent->hRight <= curr->hLeft)
           curr->parent->hRight++;
        }

        if(curr->parent->hLeft > curr->parent->hRight)
        {
          curr->parent->fromLeft = true;
          //curr->parent->fromRight = false;
        }else
        {
          if(curr->parent->hRight > curr->parent->hLeft)
          {
            curr->parent->fromRight = true;
            //curr->parent->fromLeft = false;
          }
        }

        if(!(Isbalanced(curr->parent)))
        {
          return balanceTree(curr->parent);
        }
          if(curr->parent->parent != NULL)
          curr = MaintainHeight(curr->parent);
      }
      }
      return curr;
}


Tree* balanceTree(Tree *curr)
{
  if(curr->fromRight && curr->right->fromRight)
  {
   return shiftLeft(&curr);
  }

  if(curr->fromLeft && curr->left->fromLeft)
  {
    return shiftRight(&curr);
  }

  if(curr->fromLeft && curr->left->fromRight)
  {
    curr->left->hRight++;
    curr->left = shiftLeft(&(curr->left));
    return shiftRight(&curr);
  }

  if(curr->fromRight && curr->right->fromLeft)
  {
    curr->right->hLeft++;
    curr->right = shiftRight(&(curr->right));
    return shiftLeft(&curr);
  }

}


bool Isbalanced(Tree* curr)
{
  if(abs(curr->hLeft - curr->hRight) <= 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

Tree* shiftLeft(Tree **curr)
{
  Tree* Parent1 = (*curr)->parent;
  (*curr)->hRight = (*curr)->hRight -2;

  Tree *temp = *curr; 
  Tree *temp2 = (*curr)->right->left;

  *curr = (*curr)->right;
  (*curr)->left = temp;

  (*curr)->parent = Parent1;
  
  if(Parent1 != NULL)
  Parent1->left = *curr;
    
  temp->right = temp2;
  
  if(temp2 != NULL)
  temp2->parent = temp;
  
  temp->parent = *curr;
  if(temp->right == NULL && temp->left == NULL)
  {
  temp->fromLeft = false;
  temp->fromRight = false;
  }else
  {
    temp->fromRight = true;
    temp->fromLeft = false;
  }
  (*curr)->hLeft++;
  (*curr)->fromLeft = true;
  return *curr;
}


Tree* shiftRight(Tree **curr)
{
  Tree* Parent = (*curr)->parent;
  (*curr)->hLeft = (*curr)->hLeft -2;
  Tree *temp = *curr; 
  Tree *temp2 = (*curr)->left->right;
  *curr = (*curr)->left;
  (*curr)->parent = Parent;

  if(Parent != NULL)
  Parent->right = *curr;

  (*curr)->right = temp;
  temp->left = temp2;
  
  if(temp2 != NULL)
  temp2->parent = temp;

  temp->parent = *curr;
  if(temp->right == NULL && temp->left == NULL)
  {
  temp->fromLeft = false;
  temp->fromRight = false;
  }else
  {
    temp->fromRight = false;
    temp->fromLeft = true;
  }
  (*curr)->hRight++;
  (*curr)->fromRight = true;
  return *curr;
}


void delete_node(Tree **start,int val,Tree **parent)
{
  Tree *curr= *start;
  if(curr==NULL)
  {
    cout<<"\nNo such node in tree.\n\n";
    return;
  }

  if(curr->value==val)
  {
    if(curr->left==NULL && curr->right==NULL)
    {
      free(curr);
      (*parent)->right= NULL;
      (*parent)->left= NULL;
      return;
    }
    else
    {
      if(curr->left==NULL || curr->right==NULL)
      {
        if(curr->left!=NULL)
        {
          if(parent!=NULL)
          {
          (*parent)->left = curr->left;
          free(curr);
          }
          else
          {
            *start= curr->left;
            free(curr);
          }
          return;
        }
        if(curr->right!=NULL)
        {
          if(parent!=NULL)
          {
          (*parent)->right= curr->right;
          free(curr);
          }
          else
          {
            *start= curr->right;
            free(curr);
          }
          return;
        }
      }
      
      else
      {        
        Tree *greatest= curr->left;
        while(greatest->right!=NULL)
        {
           greatest= greatest->right;
        }
        Tree *greatest_parent= search_parent(curr,greatest->value,NULL);

        if(parent!=NULL)
        {
        if((*parent)->left->value == val)
        {
          (*parent)->left= greatest;
        }
        else
        {
          (*parent)->right= greatest;
        }
        }
        else
        {
          *start= greatest;
        }

        
        greatest->right= curr->right;
        Tree *temp= greatest->left;
        greatest->left= curr->left;        
        greatest_parent->right= temp;  
        free(curr);
        return;
      }

    }
        return;
  }

   if(val>curr->value)
   {
     delete_node(&(curr->right),val,&curr);
   }

   if(val<curr->value)
   {
     delete_node(&(curr->left),val,&curr);
   }

}


Tree* search_parent(Tree *start,int val,Tree *parent)
{
  static int count =0;
Tree *curr= start;
  if(start==NULL && count != 0)
  {
    //cout<<"\n\nNo such node found in tree.\n\n";
    return NULL;
  }
  count++;
  if(start!=NULL)
  {
  if(start->value==val)
  {
    //cout<<"\n\nNode is present in the tree.\n\n";
    return parent;
  }
  else
  { count = 0; 
    if(val>curr->value)
    {
      search_parent(curr->right,val,curr);
    }
    else
    {
      if(val<curr->value)
      {
      search_parent(curr->left,val,curr);
    }
    }
  }
  }
  else
  {
    count = 0;
    return NULL;
  }
    
} 


void Inorder_Traversal(Tree *root)
{
  if(root->left)
  {
    Inorder_Traversal(root->left);
  }
  cout<<root->value<<" ";
  if(root->right)
  {
    Inorder_Traversal(root->right);
  }
}


void Preorder_Traversal(Tree *root)
{
  cout<<root->value<<" ";
  if(root->left)
  {
    Preorder_Traversal(root->left);
  }
  if(root->right)
  {
    Preorder_Traversal(root->right);
  }
}

void Postorder_Traversal(Tree *root)
{
  if(root->left)
  {
    Postorder_Traversal(root->left);
  }
  if(root->right)
  {
    Postorder_Traversal(root->right);
  }
  cout<<root->value<<" ";
}


private:
int value;
bool fromLeft;
bool fromRight;
Tree *right;
Tree *left;
Tree *parent;
int hLeft;
int hRight;
};