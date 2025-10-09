#include <stdio.h>

int main() {
    int n;
    int *ptr, min;

    printf("Enter Size of Array: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter the elements:");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    ptr = arr;
    min = *ptr;


    for(int i = 1; i < n; i++) {
        if(*(ptr + i) < min) {
            min = *(ptr + i);
        }
    }


    printf("The smallest number in the array is: %d\n", min);

    return 0;
}
