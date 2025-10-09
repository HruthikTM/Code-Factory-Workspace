#include <stdio.h>

int main()
{
    int n;

    printf("Enter Size of Array..\n");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the Elements into array..\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-1;i+=2)
    {
        // int temp=arr[i];
        // arr[i]=arr[i+1];
        // arr[i+1]=temp;

        arr[i]=arr[i]+arr[i+1];
        arr[i+1]=arr[i]-arr[i+1];
        arr[i]=arr[i]-arr[i+1];

        //printf("Hello..\n");
    }

    printf("Swapped Array..\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}
