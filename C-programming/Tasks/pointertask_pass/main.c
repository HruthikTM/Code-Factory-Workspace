#include <stdio.h>

//int a=10;
//void pass(int *a);

int main()
{
    // int *b;

    // b=&a;

    // pass(b);

    for(int i=0;i<5;++i)
    {
        printf("%d\n",i);

        printf("%d\n",i++);

        printf("%d\n",i);
    }


    // for(int i=0;i<5;i++)
    // {
    //     printf("%d",i);
    // }

    return 0;
}

// void pass(int *b)
// {
//     printf("%d\n",b);
//     printf("%d",&a);
// }
