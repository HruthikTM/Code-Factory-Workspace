#include <stdio.h>
#include<math.h>

int main()
{

    int x,y;
    float r,phi;

    printf("Enter value of coordinates: ");
    scanf("%d%d",&x,&y);

    r=sqrt(x*x + y*y);
    phi=atan2(y,x);

    printf("%f\n",r);
    printf("%f\n",phi);

    return 0;



}
