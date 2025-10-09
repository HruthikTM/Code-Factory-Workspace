#include <stdio.h>

void swap(int *,int);

int main()
{
    int n;

    printf("Enter the size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    swap(&arr, n);

    printf("Array after swapping..\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void swap(int *arr, int n)
{
    for (int i = 0; i < n - 1; i += 2)
    {
        // int temp = *(arr);
        // *(arr) = *(arr + 1);
        // *(arr + 1) = temp;


        // *(arr)=*(arr) + *(arr + 1);
        // *(arr + 1)=*(arr) - *(arr + 1);
        // *(arr)=*(arr) - *(arr + 1);

        // *(arr+i)=*(arr+i) + *(arr+ i + 1);
        // *(arr + i + 1)=*(arr+i) - *(arr +i + 1);
        // *(arr+i)=*(arr+i) - *(arr +i + 1);
    }
}
