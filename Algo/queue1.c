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
void push(int item)
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

void pop()
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
     printf("Enter Your command 1) For Push 2) For Pop 3) Quit Operation \n->");
     scanf("%d",&x); 
     if(x==1)
     {
        printf("Enter the value which you want to be Push\n->");
        scanf("%d",&x);
        push(x);
        printf("Your elements in queue\n");
        print();
     } 
     else if(x==2)
     {
        pop();
        printf("Your elements in queue\n");
        if(size!=0)
        print();
     }
   //   else if(x==3)
   //   {
   //   size_of_queue();
   //   }
     else     
     break;
     printf("\n");
  }
}
