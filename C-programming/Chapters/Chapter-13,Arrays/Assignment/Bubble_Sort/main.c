#include <stdio.h>

void bubbleSort(int arr[],int n)
{
    int temp,swapped;

    for(int i=0;i<n-1;i++)
    {
        swapped=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                swapped=1;
            }

        }

        if(swapped==0)
        {
            break;
        }
    }
}

int main()
{
    int arr[]={64,34,43,12,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,n);
    printf("Sorted Array..");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}
