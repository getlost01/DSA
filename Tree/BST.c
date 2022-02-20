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

int search(struct node* cnode,int item)
{
    if(cnode==NULL)
    return 0;
    else if(cnode->data == item)
    return 1;
    else if(cnode->data>=item)
    return search(cnode->left,item);
    else
    return search(cnode->right,item);
}

int min_ele(struct node* cnode)
{
    if(cnode==NULL)
    return -99999;
    while(cnode->left!=NULL)
    {
       cnode=cnode->left;
    }
    return cnode->data;
}

int max_ele(struct node* cnode)
{
    if(cnode==NULL)
    return -99999;
    while(cnode->right!=NULL)
    {
       cnode=cnode->right;
    }
    return cnode->data;
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

int height(struct node* cnode)
{
    if(cnode==NULL)
    return -1;

    return max(height(cnode->left),height(cnode->right))+1;
}

struct node* delete(struct node* cnode, int item)
{
    if(cnode==NULL)
    return cnode;
    else if(item < cnode->data)
    cnode->left=delete(root->left,item);
    else if(item > cnode->data)
    cnode->right=delete(cnode->right,item);
    else
    {
        if(cnode->left ==NULL && cnode->right==NULL)
        {
            free(cnode);
            cnode=NULL;
        } 
        else if(cnode->left==NULL)
        {
            struct node*temp = cnode;
            cnode=cnode->left;
            free(temp);
        }
        else if(cnode->right==NULL)
        {
            struct node*temp = cnode;
            cnode=cnode->right;
            free(temp);
        }
        else
        {
            struct node *temp = min_e(cnode->right);
            cnode->data = temp->data;
            cnode->right = delete(cnode->right,temp->data); 
        }
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
       else if(x==2)
       scanf("%d",&n),printf("The element %s\n",(search(root,n)?"Found":"Not found"));
       else if(x==3)
       printf("Min element -> %d and Max element -> %d\n",min_ele(root),max_ele(root));
       else if(x==4)
       printf("Height-> %d\n",height(root));
       else if(x==5)
       scanf("%d",&n),root=delete(root,n);
       else
       break;
       inorder(root);
       printf("\n");
    }
    

    return 0;
}
