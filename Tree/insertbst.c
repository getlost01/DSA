#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* left;
    int data;
    struct node* right;
};
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
    {
        cnode=CreateNode(item);
    }
    else if(item <= cnode->data)
    {
        cnode->left=insert(cnode->left,item);
    }
    else
    {
        cnode->right=insert(cnode->right,item);
    }
    return cnode;
} 
void inorder(struct node* cnode)
{
    if(cnode==NULL)
    return;
    inorder(cnode->left);
    printf("%d ",cnode->data);
    inorder(cnode->right);
}
int main()
{
    printf("Enter command\n");
    int n,x;
    while(1)
    {
       scanf("%d",&x);
       if(x==1)
       scanf("%d",&n),root=insert(root,n);
       else
       break;
       inorder(root);
       printf("\n");
    }
    return 0;
}
