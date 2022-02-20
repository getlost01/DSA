#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node* link;
} node;

node *graph[10];
int visited[10]={0};

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
void dfs(int i)
{
    node *p;
    printf("-> %d",i);
    p=graph[i];
    visited[i]=1;
    while(p!=NULL)
    {
     i=p->data;
     if(!visited[i])
     dfs(i);
     p=p->link;
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
      insert(b,a);
    }
    scanf("%d",&a);
    printf("DFS for vertex %d is\n",a);
    dfs(a);
    printf("\n");
}


