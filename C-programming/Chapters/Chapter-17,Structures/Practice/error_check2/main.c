#include <stdio.h>

int main()
{
    struct  //structure name not specified
    {
        char  name[25] ;
        char  language[10] ;
    } ;
    struct employee  e = { "Hacker", "C" } ;
    printf ( "\n%s %s", e.name, e.language ) ;

    return 0;
}

