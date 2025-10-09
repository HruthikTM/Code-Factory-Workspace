#include <stdio.h>


void selectionSort(int arr[],int n)
{
    int min_index;

    for(int i=0;i<n-1;i++)
    {
        min_index=i;

        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])
                min_index=j;
        }

        int temp=arr[min_index];
        arr[min_index]=arr[i];
        arr[i]=temp;
    }
}

void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
}

int main()
{
    int arr[]={10,37,45,62,12};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original Array..\n");
    printArray(arr,n);

    selectionSort(arr,n);

    printf("\nSelection Sort Array..\n");
    printArray(arr,n);

    return 0;
}
