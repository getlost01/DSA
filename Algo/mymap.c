#include<stdio.h>
#include<stdlib.h>
int max(int a,int b) {return ((a>b)?a:b);}

struct node
{
    struct node* left;
    int key;
    int value;
    struct node* right;
};

struct node* root=NULL;
struct node* CreateNode(int k,int v)
{
   struct node* p=(struct node*)(malloc(sizeof(struct node)));
   p->key=k;
   p->value=v;
   p->left=NULL;
   p->right=NULL;
   return p;
}

struct node* insert(struct node* cnode,int k, int v)
{
    if(cnode==NULL)
    {
        cnode=CreateNode(k,v);
    }
    else if(k <= cnode->key)
    {
        cnode->left=insert(cnode->left,k,v);
    }
    else
    {
        cnode->right=insert(cnode->right,k,v);
    }
    return cnode;
} 

struct node* search(struct node* cnode,int item)
{
    if(cnode==NULL)
    return NULL;
    else if(cnode->key == item)
    return cnode;
    else if(cnode->key>item)
    return search(cnode->left,item);
    else
    return search(cnode->right,item);
}

int get(int k)
{
    struct node* temp=search(root,k);
    if(temp==NULL)
    {
     root=insert(root,k,0);
     return 0;
    }
    return temp->value;     
}

void put(int k,int v)
{
    struct node* temp=search(root,k);
    if(temp!=NULL)
    temp->value=v;
    else
    root=insert(root,k,v);
    temp=search(root,k);
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
    if (x>root->key)
    root->right = delete(root->right, x);
    else if(x<root->key)
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
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }
    return root;
}

void inorder(struct node* cnode)
{
    if(cnode==NULL)
    return;
    inorder(cnode->left);
    printf("%d -> %d\n",cnode->key,cnode->value);
    inorder(cnode->right);
}

int main()
{
    int k,v,x;
    char c;
    while(1)
    {
       printf("Enter command\n");
       scanf("%d",&x);
       if(x==1)
       scanf("%d%d",&k,&v),put(k,v);
       else if(x==2)
       scanf("%d",&k),printf("WE get -> %d\n",get(k));  
       else if(x==3)
       scanf("%d",&k),root=delete(root,k);  
       else
       break;
       inorder(root);
       printf("\n");
    }
    
    return 0;
}
