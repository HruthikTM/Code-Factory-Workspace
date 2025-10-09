#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n1=-567;
    int n2=-14.86;
    int n3=-12345678;

    int abs_int=abs(n1);
    int abs_float=fabs(n2);
    int abs_long=labs(n3);

    printf("Absolute num of %d : %d\n",n1,abs_int);
    printf("Absolute num of %d : %d\n",n2,abs_float);
    printf("Absolute num of %d : %d\n",n3,abs_long);

}
