#include <stdio.h>


void add();

int main() {
    add();
    int *c = 20;
    printf("Value pointed by c: %d\n", *c);
    return 0;
}

void add() {
    //int c = (int *)malloc(sizeof(int));
    int *c = 10;
}
