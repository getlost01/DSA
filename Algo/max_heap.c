#include <stdio.h>

void max_heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) 
	{
        int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
        max_heapify(arr, n, largest);
    }
}
void build_heap(int arr[],int n)
{
    for(int i=n/2;i>0;i--)
    {
        max_heapify(arr,n,i-1);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        int temp=arr[i];
		arr[i]=arr[0];
		arr[0]=temp;
        max_heapify(arr, i, 0);
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
 
    printf("\nMax heap is \n");
    printArray(arr, n);
    
    heapSort(arr,n);
    
    printf("\nAsending order Sorted Array is \n");
    printArray(arr, n);
	return 0;
}
