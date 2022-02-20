#include<stdio.h>
#include<stdlib.h>
struct node 
{
   int data;
   struct node *link;
};

struct node* front=NULL;
struct node* back=NULL;
int size=0;
void push_back(int item)
{
   struct node *p=(struct node *)malloc(sizeof(struct node));
  
   p->data=item;

   if(size==0)
   {
      front=p;
      back=p;
   }
   back->link=p;
   back=p;
   size++;
}

void push_front(int item)
{
   struct node *p=(struct node *)malloc(sizeof(struct node));
  
   p->data=item;

   if(size==0)
   {
      front=p;
      back=p;
   }
   p->link=front;
   front=p;
   size++;
}

void pop_back()
{
   struct node *p=front;
   if(size==0)
   {
   printf("QUEUE EMPTY\n");
   return;
}
   while(p->link!=back)
   {
      p=p->link;
   }
   p->link=NULL;
   back=p;
   size--;
}

void pop_front()
{
    if(size==0)
    {
       printf("QUEUE EMPTY\n");
       return;
    }
    front=front->link;
    size--;
}

void print()
{
   struct node* p=front;
   while(p!=back)
   {
      printf("%d ",p->data);
      p=p->link;
   }
   printf("%d\n",p->data);
}

void size_of_queue()
{
   printf("Size of the queue is -> %d\n",size);
}


void main()
{
  int x;
  while(1)
  {
     printf("Enter Your command \n1) For Push Back \n2) For Push Front \n3) For Pop Back \n4) For Pop Front \n5) For getting size \n6) Quit Operation \n->");
     scanf("%d",&x); 
     if(x==1)
     {
        printf("Enter the value which you want to be Push\n->");
        scanf("%d",&x);
        push_back(x);
        printf("Your elements in queue\n");
        print();
     } 
     else if(x==2)
     {
        printf("Enter the value which you want to be Push\n->");
        scanf("%d",&x);
        push_front(x);
        printf("Your elements in queue\n");
        print();
     } 
     else if(x==3)
     {
        pop_back();
        if(size!=0)
        {
         printf("Your elements in queue\n");
         print();
        }
     }
     else if(x==4)
     {
        pop_front();
        if(size!=0)
        {
         printf("Your elements in queue\n");
         print();
        }
     }
     
     else if(x==5)
     {
     size_of_queue();
     }
     else     
     break;
     printf("\n");
  }
}
