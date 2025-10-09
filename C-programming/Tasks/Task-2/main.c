#include <stdio.h>

//int return_me(int n);

// void fun1(int n)
// {
//     printf("kkk");
// }

// int fun1()
// {
//     printf("mmm");
//     return 0;
// }

struct name{
    char a;
    char b;
    char c;
    char d;
    char e;
    char f;
};

int main()
{
    // int n;
    // printf("Enter value of n: ");
    // scanf("%d", &n);

    // char character = return_me(n);
    // printf("Chacracter: %c\n", character);

    // if(1)
    //     printf("hi");
    // else
    //     printf("hello");

    // fun1();
    // fun1();

//private int a;


    struct name z={'a','b','c','d','e','f'};

    int size=sizeof(struct name);

    printf("%d",size);


    return 0;
}


// int return_me(int n)
// {

//     if (n == 1)
//         return 'A';
//     else if (n == 2)
//         return 'B';
//     else if (n == 3)
//         return 'C';
//     else if (n == 4)
//         return 'E';
//     else if (n == 5)
//         return 'F';
//     else
//         return '?';
// }
