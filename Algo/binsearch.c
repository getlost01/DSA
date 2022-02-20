
#include <stdio.h>

int binarySearch(int arr[], int first, int last, int num)
{
int mid = (first + last) / 2;
while (first <= last)
{
if (arr[mid] < num) {first = mid + 1;} 
else if (arr[mid] == num) 
{
	return mid;
}
else 
{
	last = mid - 1;
}
mid = (first + last) / 2;
}
return -1;
}

int main()
{
	int arr[10];
	for(int i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter number of queries\n");
	int q,v;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d",&v);
		printf("The position of %d is -> %d\n",v,binarySearch(arr,0,10,v));
	}
	return 0;
}
