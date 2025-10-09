#include <stdio.h>

// int i=1;
// void val();

// int f(int);
// int g(int);




//int main()
//{
    // for(int i=0;i<=5000;i++){
    //     printf("%d\n",i);
    // }

    // float a=13.5;
    // double b=13.5;
    // printf("%f%lf\n",a,b);

    // return 0;


    // printf("mains of i=%d\n",i);
    // i++;
    // val();
    // printf("mains of i=%d\n",i);
    // val();
    // return 0;


    // int x,y,s=2;
    // s*=3;
    // y=f(s);
    // x=g(s);

    // printf("%d%d%d\n",s,y,x);
    // return 0;
//}

// int t=8;

// int f(int a)
// {
//     a+=5;
//     t-=4;
//     return(a+t);
// }


// int g(int a)
// {
//     a=1;
//     t+=a;
//     return(a+t);
// }

// void val()
// {
//     i=100;
//     printf("vals of i=%d\n",i);
//     i++;
// }


// int main()
// {
//     static int count=5;
//     printf("count=%d\n",count--);
//     if(count!=0)
//         main();

//     return 0;
// }

// int g(int);
// int main( )
// {
//     int  i, j ;
//     for ( i = 1 ; i < 5 ; i++ )
//     {
//         j = g ( i ) ;
//         printf ( "%d\n", j ) ;
//     }
// }
// int g ( int  x )
// {
//     static int  v = 1 ;
//     int  b = 3 ;
//     v += x ;
//     return ( v + x + b ) ;
// }


void func();

int main( )
{
    func( ) ;
    func( ) ;
    return 0;
}
void func( )
{
    auto int  i = 0 ;
    register int j = 0 ;
    static int k = 0 ;
    i++ ;  j++ ;  k++ ;
    printf ( "\n %d % d %d", i, j, k ) ;
}

