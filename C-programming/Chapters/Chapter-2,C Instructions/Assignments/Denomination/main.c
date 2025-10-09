#include <stdio.h>

int main()
{
    int denomination[] = {100, 50, 10, 5, 2, 1};
    int count[6] = {0};
    int n;

    printf("Enter the Currency: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("Please enter a positive amount.\n");
        return 1;
    }

    for(int i = 0; i < 6; i++) {
        if(n >= denomination[i]) {
            count[i] = n / denomination[i];
            n = n % denomination[i];
        }
    }

    printf("Minimum number of Denominations:\n");
    for(int i = 0; i < 6; i++) {
        if(count[i] != 0) {
            printf("Rs. %d: %d\n", denomination[i], count[i]);
        }
    }

    return 0;
}
