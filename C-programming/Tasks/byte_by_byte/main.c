#include <stdio.h>

int main() {
    int a = 1000;
    float b = 10.8;

    unsigned char *pA = (unsigned char*)&a;
    unsigned char *pB = (unsigned char*)&b;

    printf("Bytes of int a = %d:\n", a);
    for (int i = 0; i < sizeof(a); i++) {
        printf("Byte %p: %d\n", i, pA[i]);
    }

    printf("\nBytes of float b = %f:\n", b);
    for (int i = 0; i < sizeof(b); i++) {
        printf("Byte %p: %d\n", i, pB[i]);
    }

    return 0;
}



