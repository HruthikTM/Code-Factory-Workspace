#include <stdio.h>


int main() {
    int arr[] = {12, 43, 65, 78, 154};
    int n = sizeof(arr) / sizeof(arr[0]);


    reverseArray(arr, n);


    int reversedArr[n];
    for (int i = 0; i < n; i++) {
        reversedArr[i] = arr[i];
    }

    printf("Reversed array c:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", reversedArr[i]);
    }

    return 0;
}

int reverseArray(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    return 0;
}
