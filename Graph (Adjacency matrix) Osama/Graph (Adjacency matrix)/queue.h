#include <iostream>
using namespace std;

class Queue{
public:

Queue()
{
    this->value= 0;
    this->front= NULL;
    this->rear= NULL;
}

int getvalue()
{
    return this->value;
}



void Enqueue(Queue **front,Queue **rear,int element)
{
    Queue* ptr= NULL;
    
   if(*rear==NULL && *front==NULL)
   {
    ptr= (Queue*)malloc(sizeof(Queue));
    //cout<<"\nEnqueued element is "<<element<<".\n\n";
    ptr->value= element;
    ptr->next= NULL;
    *front = ptr;
    *rear= ptr;       
   }
 else
   {
      Queue *curr;
      ptr= (Queue*)malloc(sizeof(Queue));
      //cout<<"\nEnqueued element is "<<element<<".\n\n";
      ptr->value= element;
      ptr->next= NULL;
      curr= *front;
      while(curr!=*rear)
      {
          curr= curr->next;
      }
      (*rear)->next= ptr;
      *rear= (*rear)->next;
      curr->next= ptr;
   }
}


bool Is_empty(Queue *front, Queue *rear)
{
    if(front == NULL && rear == NULL)
    {
        return true;
    }else{

        return false;
    }
}


int Dequeue(Queue **front,Queue **rear)
{
    int temp;
    Queue *curr= *front;
    if(*front==NULL && *rear==NULL)
    {
        cout<<"\nError! The Queue is empty.\n\n";
        return -1;
    }

    if(*front==*rear)
    {
       //cout<<"\nDequeued value is "<<curr->value<<".\n\n";
       temp = curr->value;
       free(curr);
       *front= NULL;
       *rear= NULL;

    }
    else
    {
        temp = curr->value;
        //cout<<"\nDequeued value is "<<curr->value<<".\n\n";
        *front= curr->next;
        free(curr);
    }
    return temp;

}





private:
int value;
Queue *next;
Queue *front;
Queue *rear;
};