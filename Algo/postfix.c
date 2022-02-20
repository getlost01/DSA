#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node* link;
};

char s[20],temp;
struct node* top=NULL;
void push(char item)
{
   struct node *p=(struct node *)malloc(sizeof(struct node)); 
   p->data=item;
   p->link=top;
   top=p;
}

char pop()
{
   if(top!=NULL)
   {
     temp=top->data;
     top=top->link; 
   }
   else
   {
     temp='0';
   }
   return temp;
}

void print()
{
   struct node *p=top;  
   while(p!=NULL)
   { 
      printf("%c \n",p->data);
      p=p->link;
   }
}

void main()
{
   printf("Enter the statement\n");
   scanf("%s",s);
   int n=strlen(s);
   for(int i=0;i<n;i++)
   {
      if(s[i]>=65 && s[i]<=90 )
      { 
         printf("%c",s[i]);
      }
      else if(s[i]==')')
      {
          while(top->data!='(')
          {printf("%c",pop());}
          pop();
      }
      else
      {
          push(s[i]);
      }
   }
   printf("\n");
}
