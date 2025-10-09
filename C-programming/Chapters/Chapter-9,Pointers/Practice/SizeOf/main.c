#include <stdio.h>

int main()
{
    printf("Integer size: %d\n",sizeof(int));
    printf("Float size: %d\n",sizeof(float));
    printf("Char size: %d\n",sizeof(char));
    printf("Double size: %d\n",sizeof(double));


    printf("Integer pointer size: %d\n",sizeof(int *));
    printf("Float pointer size: %d\n",sizeof(float *));
    printf("Char pointer size: %d\n",sizeof(char *));
    printf("Double pointer size: %d\n",sizeof(double *));

    return 0;
}
