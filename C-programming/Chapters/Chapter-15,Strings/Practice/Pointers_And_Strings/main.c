#include <stdio.h>

// int main()
// {
//     char str1[]="Hello";
//     char str2[10];

//     char *s="Good Morning";
//     char *q;

//     str2=str1;//Error:Can't assign 1 String to another

//     q=s;//Works:Can assign i Char pointer to another

//     return 0;
// }


int main()
{
    char str1[]="Hello";
    char *p="Hello";

    str1="Bye";//error
    p="Bye";//works
}
