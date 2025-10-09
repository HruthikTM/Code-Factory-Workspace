 #include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    int a = 8000;
    float b = 10854.5989;

    printf("Integer (a = %d):\n", a);
    unsigned char *p = (unsigned char*)&a;

    for (int i = 0; i < sizeof(a); i++)
        printf("Byte %d: 0x%02X\n", i, p[i]);

    printf("\nFloat (b = %.2f):\n", b);
    unsigned char *q = (unsigned char*)&b;

    for (int i = 0; i < sizeof(b); i++)
        printf("Byte %d: 0x%02X\n", i, q[i]);

    return 0;

}
