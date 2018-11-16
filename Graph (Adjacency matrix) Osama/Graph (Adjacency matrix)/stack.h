#include <iostream>
using namespace std;

class list{
public:

list()
{
    this->value= 0;
    this->next= NULL;
}

int getvalue()
{
    return this->value;
}

bool Isempty(list *top)
{
    if(top == NULL)
    {
        return true;
    }else{
        return false;
    }
}

void push(list **top,int element)
{
    list *ptr= NULL;
    if(*top==NULL)
    {
       ptr= (list*)malloc(sizeof(list));
       //cout<<"\nThe pushed element is "<<element<<".\n";
       ptr->value= element;
       ptr->next= NULL;
       *top= ptr;
    }
    else
    {
        list *temp;
        temp= *top;
        ptr= (list*)malloc(sizeof(list));
        //cout<<"\nThe pushed element is "<<element<<".\n";
        ptr->value= element;
        *top= ptr;
        ptr->next= temp;
         
    }
}





int pop(list **top)
{
    int retVal;
    if(*top==NULL)
    {
        cout<<"\nError! Stack is empty.\n\n";
        return 0;
    }
    list *curr= *top;  

   if(curr->next!=NULL)
   {
       list *temp= NULL;
       temp= (*top)->next;
       //cout<<"\nThe poped element is "<<curr->value<<".\n\n";
       retVal = curr->value;
       *top= temp; 
       free(curr);
           
   }
   else
   {
       //cout<<"\nThe poped element is "<<curr->value<<".\n\n";
       retVal = curr->value;
       free(curr);
       *top= NULL;   
       
   }    
   return retVal;

}

int peak_stack(list *start)
{
    return start->value;
}



private:
int value;
list *next;

};