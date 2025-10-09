#include <stdio.h>

//Snippet-1
// void pass(int,int);

// int main()
// {

//     int i=135,a=135,k;
//     k=pass(i,a);
//     printf("%d\n",k);
//     return 0;

// }

// void pass(int j,int b){
//     int c=j+b;
//     return (c);
// }

//Here the void values will be ignored

// Snippet-2

// void pass(int,int);

// int main()
// {

//     int i=135,a=135;
//     pass(&i,&a);
//     printf("%d%d\n",i,a);
//     return 0;

// }

// void pass(int j,int b){
//     j=j+j;
//     b=b+b;
// }

// No Error

//Snippet-3

// void check(int);

// int main()
// {
//     int k=35,z;
//     z=check(k);
//     printf("%d\n",z);
//     return 0;
// }

// void check(m)
// {
//     int m;
//     if(m>40)
//         return (1);
//     else
//         return (0);
// }

//void value return error
//m redecleared


//Snippet-4

// void check(int *);

// int main()
// {
//     int k=35,*z;
//     z=check(&k);
//     printf("%d\n",z);
//     return 0;
// }

// void check(m)
// {
//     return (*m+2);
// }


//void value return error
//m redecleared
