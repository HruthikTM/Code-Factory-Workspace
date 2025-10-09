#include<stdio.h>
//string header file not included
int main( )
{
    struct employee
    {
        char  name[25] ;
        int  age ;
        float  bs ;
    } ;

    struct employee  e ;

    strcpy ( e.name, "Hacker" ) ;
    age = 25 ;//it should be e.age
    bs=29239.00;//it should be e.bs
    printf ( "\n%s %d %f", e.name, age, bs ) ;

    return 0;
}
