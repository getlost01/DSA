#include<stdio.h>
#include<stdlib.h>
struct node 
{
   int data;
   struct node *first_link;
   struct node *second_link;
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
   back->first_link=p;
   p->second_link=back;
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
   p->first_link=front;
   front->second_link=p;
   front=p;
   size++;
}

void pop_back()
{
   if(size==0)
   {
   printf("QUEUE EMPTY\n");
   return;
   }
   back=back->second_link;  
   size--;
}

void pop_front()
{
    if(size==0)
    {
       printf("QUEUE EMPTY\n");
       return;
    }
    front=front->first_link;
    size--;
}

void print()
{
   struct node* p=front;
   while(p!=back)
   {
      printf("%d ",p->data);
      p=p->first_link;
   }
   printf("%d\n",p->data);
}

void print_reverse()
{
   struct node* p=back;
   while(p!=front)
   {
      printf("%d ",p->data);
      p=p->second_link;
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
     printf("Enter Your command 1) For Push Back 2) For Push Front 3) For Pop Back 4) For Pop Front 5) Quit Operation \n->");
     scanf("%d",&x); 
     if(x==1)
     {
        printf("Enter the value which you want to be Push\n->");
        scanf("%d",&x);
        push_back(x);
        printf("Your elements \n");
         print();
     } 
     else if(x==2)
     {
        printf("Enter the value which you want to be Push\n->");
        scanf("%d",&x);
        push_front(x);
        printf("Your elements \n");
         print();
     } 
     else if(x==3)
     {
        pop_back();
        if(size!=0)
        {
        printf("Your elements \n");
         print();
        }
     }
     else if(x==4)
     {
        pop_front();
        if(size!=0)
        {
         printf("Your elements \n");
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
