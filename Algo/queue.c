#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int arr[20];
int back=-1;
int front=-1;
char ch;
void pop()
{
   if(back>front)
   front++;
   else
   {
     printf("Warning! UNDERFLOW");
   }
}

void push(int n)
{
   if(back!=20)
   {
     back++;
     arr[back]=n;
   }
   else
   {
     printf("Warning! OVERFLOW"); 
   }
}

void main()
{
   int n,v;
   printf("Enter number of operations\n");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
      scanf("%s",&ch);
      if(ch=='i')
      { 
          scanf("%d",&v);
          push(v);
      }
      else if(ch=='o')
      {
          pop();
      }
      for(int j=front+1;j<=back;j++)
      {
         printf("%d ",arr[j]);
      }
      printf("\n");
   }
}
