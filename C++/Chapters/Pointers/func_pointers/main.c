#include <stdio.h>

int *func();

int main()
{
    int *p;
    p = func();
    printf("%u\n",p);
    printf("%d\n",*p);
   // printf("%u\n",&p);
    printf("%d\n",p);

    return 0;
}

int *func()
{
   static int i = 90;
   return (&i);
}
