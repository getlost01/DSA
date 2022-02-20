#include <stdio.h>

void min_heapify(int arr[], int n, int i)
{
    int smallest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
 
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
 
    if (smallest != i) 
	{
        int temp=arr[i];
		arr[i]=arr[smallest];
		arr[smallest]=temp;
        min_heapify(arr, n, smallest);
    }
}
void build_heap(int arr[],int n)
{
    for(int i=n/2;i>0;i--)
    {
        min_heapify(arr,n,i-1);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        min_heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        int temp=arr[i];
		arr[i]=arr[0];
		arr[0]=temp;
        min_heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
    int  arr[20];
    int n=20;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]); 
    }
 
    build_heap(arr, n);
 
    printf("\nMin heap is \n");
    printArray(arr, n);
    
    heapSort(arr,n);
    
    printf("\nSorted Array in desending order is \n");
    printArray(arr, n);
	return 0;
}
