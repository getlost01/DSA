#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node* link;
} node;

node *graph[10];
int visited[10]={0};

//-------------------------Queue---------------------------------
struct Qnode
{
   int data;
   struct Qnode *link;
};
struct Qnode* front=NULL;
struct Qnode* back=NULL;
int size=0;
void push(int item){
   struct Qnode *p=(struct Qnode *)malloc(sizeof(struct Qnode));
   p->data=item;
   if(size==0)
   {front=p;back=p;}
   back->link=p;
   back=p;
   size++;}

void pop(){   
    if(size==0)
    {printf("QUEUE EMPTY\n");return;}
    front=front->link;
    size--;}
void print(){   
   struct Qnode* p=front;
   while(p!=back)
   {printf("%d ",p->data); p=p->link;}
   printf("%d\n",p->data);}
//-----------------------------End Queue---------------------------

void bfs(int a)
{
     push(a);
     while(size!=0)
     {
         int cv=front->data;
         visited[cv]=1;
         printf("%d -> ",cv);
         struct node* curr=graph[cv];
         while(curr!=NULL)
         {
         if(!visited[curr->data])
         {
          push(curr->data); 
          visited[curr->data]=1;
         }
         curr=curr->link;
         }
         pop();
     }
         printf("\n");
         for(int i=0;i<10;i++)
         printf("%d ",visited[i]);
}



void insert(int a,int b)
{
   node *p=(node *)(malloc(sizeof(node)));
   p->data=b;
   p->link=NULL;
   node *q=graph[a];
   if(q==NULL)
   graph[a]=p;
   else
   {
     while(q->link!=NULL)
     q=q->link;
     q->link=p;
   }
}


void main()
{
    printf("Enter Number of nodes, queries\n");
    int n,q,a,b; 
    scanf("%d %d",&n,&q);
    printf("Enter number of connected nodes A , B\n");
    for(int i=0;i<q;i++)
    {
      scanf("%d",&a);
      scanf("%d",&b);
      insert(a,b);
      // insert(b,a);
    }
    scanf("%d",&a);
    printf("DFS for vertex %d is\n",a);
    bfs(a);
    printf("\n");
}


