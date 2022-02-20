#include<stdio.h>
#include<stdlib.h>
int max(int a,int b) {return ((a>b)?a:b);}

struct node
{
    struct node* left;
    int data;
    struct node* right;
};

//-------------------------Queue---------------------------------
struct Qnode
{
   struct node* data;
   struct Qnode *link;
};
struct Qnode* front=NULL;
struct Qnode* back=NULL;
int size=0;
void push(struct node* item){
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
   {printf("%d ",p->data->data); p=p->link;}
   printf("%d\n",p->data->data);}
//-----------------------------End Queue---------------------------

struct node* root=NULL;
struct node* CreateNode(int item)
{
   struct node* p=(struct node*)(malloc(sizeof(struct node)));
   p->data=item;
   p->left=NULL;
   p->right=NULL;
   return p;
}

struct node* insert(struct node* cnode,int item)
{
    if(cnode==NULL)
    cnode=CreateNode(item);
    else if(item <= cnode->data)
    cnode->left=insert(cnode->left,item);
    else
    cnode->right=insert(cnode->right,item);
    return cnode;
} 

//----------------------------------Traversal---------------------------------------

void levelorder(struct node* cnode)
{
     if(cnode==NULL)
     return;
     push(root);
     while(size!=0)
     {
         struct node* curr=front->data;
         printf("%d ",curr->data);
         if(curr->left!=NULL)
         push(curr->left);
         if(curr->right!=NULL)
         push(curr->right);
         pop();
     }
}

void preorder(struct node* cnode)
{
    if(cnode==NULL)
    return;
    printf("%d ",cnode->data);
    preorder(cnode->left);
    preorder(cnode->right);
}

void inorder(struct node* cnode)
{
    if(cnode==NULL)
    return;
    inorder(cnode->left);
    printf("%d ",cnode->data);
    inorder(cnode->right);
}

void postorder(struct node* cnode)
{
    if(cnode==NULL)
    return;
    preorder(cnode->left);
    preorder(cnode->right);
    printf("%d ",cnode->data);
}


//--------------------------------MAIN------------------------------------------------
int main()
{
    printf("Enter command\n");
    int n,x;
    while(1)
    {
       scanf("%d",&x);
       if(x==1)
       scanf("%d",&n),root=insert(root,n);
       else if(x==2)
       {
       printf("LEVEL ORDER TRAVERSAL\n");
       levelorder(root);
       printf("PERORDER TRAVERSAL\n");
       preorder(root);
       printf("INORDER TRAVERSAL\n");
       inorder(root);
       printf("POSTORDER TRAVERSAL\n");
       postorder(root);
       }
       else
       break;
    }
    

    return 0;
}
