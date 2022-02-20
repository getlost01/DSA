#include<stdio.h>
#include<stdlib.h>

int max(int a,int b) {return ((a>b)?a:b);}
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

struct node* min_e(struct node* cnode)
{
    if(cnode==NULL)
    return cnode;
    while(cnode->left!=NULL)
    {
       cnode=cnode->left;
    }
    return cnode;
}

struct node* delete(struct node *root, int x)
{
    if(root==NULL)
    return NULL;
    if (x>root->data)
    root->right = delete(root->right, x);
    else if(x<root->data)
    root->left= delete(root->left, x);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
            temp = root->right;
            else
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = min_e(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
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
       else if(x==2)
       scanf("%d",&n),root=delete(root,n);
       else
       break;
       inorder(root);
       printf("\n");
    }
    return 0;
}
