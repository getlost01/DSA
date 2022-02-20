#include<stdio.h>
#include<stdlib.h>
struct node 
{
   int data;
   struct node *link;
};

struct node* head=NULL;
struct node* trav;
int size=0,temp,n;

void push(int item)
{
   struct node *p=(struct node *)malloc(sizeof(struct node));
  
   p->data=item;

   if(size==0)
   {
      head=p;
      trav=p;
   }
   trav->link=p;
   trav=p;
   size++;
}

void creatlist(int n)
{
   while(size!=n)
   {
     scanf("%d",&temp);
     push(temp);
   }
}

void traverse()
{
   struct node* t=head;
   int p=n;
   while(--p)
   {
      printf("%d ",t->data);
      t=t->link;
   }
   printf("%d \n",t->data);
}

int main()
{
   printf("Enter the size of linked list \n");
   scanf("%d",&n);
   creatlist(n);
   traverse();
   return 0;  
}
