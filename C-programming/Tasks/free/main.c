#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=10;
    printf("%zp\n",&a);
    int *ptr=&a;
    printf("%zp\n",ptr);
    free(ptr);
    printf("%zp\n",ptr);
    return 0;
}
