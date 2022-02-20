#include<stdio.h>
#include<stdlib.h>
struct node 
{
   int data;
   struct node *link;
};

struct node head;
struct node* trav;
int size=0,temp;
/*
  stucture of my linked list
  head --> |data|link*| --> |data|link*| --> |data|link*| --> NULL
*/

void add_last(int item)
{
   struct node *p=(struct node *)malloc(sizeof(struct node));
  
   p->data=item;

   if(size==0)
   {
      head.link=p;
   }
   else
   {
   trav->link=p;
   }
   trav=p;
   size++;
}


void add_first(int item)
{
   struct node *p=(struct node *)malloc(sizeof(struct node));
   p->data=item;
   p->link=head.link;
   head.link=p;
   size++;
}

void insert_pos(int pos,int item) //here pos is zero based indexing
{
   struct node *p=(struct node *)malloc(sizeof(struct node));
   p->data=item;
   struct node* t=head.link;
   while(pos--)
   {
      t=t->link;         
   }
   p->link=t->link;
   t->link=p;
   size++;
}

void insert(int pos,int item)
{
   if(pos==0)
   add_first(item);
   else if(pos==size-1)
   add_last(item);
   else 
   {
     if(pos<size-1 && pos>0)
     insert_pos(pos,item);
     else
     {
     printf("ERROR!INVALID POSITION\n"); return;
     }
   }
   size++;
}

void remove_ele(int pos)
{
  if(pos<size)
  { 
    struct node *p=&head;
    while(pos--)
    {
      p=p->link;
    }
    p->link=p->link->link;
  }
   size--;
}


void print()
{
   struct node* t=head.link;
   while(t->link!=NULL)
   {
      printf("%d ",t->data);
      t=t->link;
   }
   printf("%d \n",t->data);
}

void sort()
{
   struct node* p= head.link,* q,*tem;
   while(p!=NULL)
   {
     int max=p->data;
     q=p->link;
     tem=p;
     while(q!=NULL)
     {
       if(max>q->data)
       {
         tem=q;  
         max=q->data;
       }
       q=q->link;
     }
     int temp=tem->data;
     tem->data=p->data;
     p->data=temp;
     p=p->link;
   }
}

void reverse_LL()
{
   struct node* p=head.link,*q,*tem=NULL;
   trav=p;
   while(p!=NULL)
   {
     q=p->link;
     p->link=tem;
     tem=p;
     p=q;
   }
    head.link=tem;
}

void find(int val)
{
   struct node* p= head.link;
   int pos=0,found=0;
   while(p!=NULL)
   {
      if(p->data==val)
      {
         if(!found)
         {
            found=1;
            printf("The value %d found at postion at %d  ",val,pos);
         }
         else
         printf("%d  ",pos);
      }
      pos++;
      p=p->link;
   }
   if(!found)
   printf("Data Does'nt Exist");
   printf("\n");
}

void main()
{
   int x,item,pos;
   while(1)
   {
     printf("-->Enter Your command<-- \n1) For Push Back \n2) For Push Front \n3) For Insert at any positon \n4) For Remove \n5) For Sorting \n6) For Finding Elements \n7) For Reverse a LinkedList \n8) Quit Operation \n->");
      scanf("%d",&x);
      if(x==1)
      {
      printf("Enter the element\n");
      scanf("%d",&item);
      add_last(item);
      }
      else if(x==2)
      {
      printf("Enter the element\n");
      scanf("%d",&item);
      add_first(item);
      }
      else if(x==3)
      {
      printf("Enter the position\n");
      scanf("%d",&pos);
      printf("Enter the element\n");
      scanf("%d",&item);
      insert(pos,item);
      } 
      else if(x==4)
      {
      printf("Enter the position\n");
      scanf("%d",&pos);
      remove_ele(pos);
      }
      else if(x==5)
      {
      sort();
      }
      else if(x==6)
      {
       printf("Enter the element\n");
       scanf("%d",&item);
       find(item);
      }
      else if(x==7)
      {
      reverse_LL();
      }
      else
      {
       break; 
      }
      printf("Your list\n");
      print();
}
}
