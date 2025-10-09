#include <stdio.h>

struct s
{
    char  ch ;
    int  i ;
    float  a ;
} ;


//function prototypes missing

int main( )
{
    struct s  var = { 'C', 100, 12.55 } ;
     f ( var ) ;
     g ( &var ) ;
     return 0;
}


void f( struct s  v )
{
    printf ( "\n%c %d %f", v -> ch, v -> i, v -> a ) ;//v.ch
}

void g ( struct s  *v )
{
    printf ( "\n%c %d %f", v.ch, v.i, v.a ) ;//v->ch
}
