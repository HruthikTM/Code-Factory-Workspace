#include <stdio.h>


// int char mixed[100];

// int main()
// {
//     int a[10];
//     for(int i=1;i<=10;i++)
//     {
//         scanf("%d",a[i]);
//         printf("%d\n",a[i]);
//     }
//     return 0;
// }


// int main()
// {
//     int size;
//     printf("Enter size: ");
//     scanf("%d",&size);
//     int arr[size];

//     for(int i=1;i<=size;i++)
//     {
//         scanf("%d",&arr[i]);
//         printf("%d\n",arr[i]);
//     }

//     return 0;
// }


int main()
{
    int a=2,b=3;
    int arr[2+3];
    for(int i=0;i<a+b;i++)
    {
        scanf("%d",&arr[i]);
        printf("%d\n",arr[i]);
    }

    return 0;
}
