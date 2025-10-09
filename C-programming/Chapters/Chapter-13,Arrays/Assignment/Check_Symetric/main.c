#include <stdio.h>

int main() {
    int n, i, isSymmetric = 1;


    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    for(i = 0; i < n / 2; i++) {
        if(arr[i] != arr[n - 1 - i]) {
            isSymmetric = 0;
            break;
        }
    }

    if(isSymmetric)
        printf("The array is symmetric.\n");
    else
        printf("The array is not symmetric.\n");

    return 0;
}

