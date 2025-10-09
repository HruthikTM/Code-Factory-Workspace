
#include <stdio.h>
#include<math.h>

int main()
{
    float a,b,c;

    printf("Enter the angles: ");
    scanf("%f%f%f",&a,&b,&c);

    if(a==b && b==c)
        printf("Equilateral\n");
    else if(a==b || b==c || c==a)
        printf("Isosceles\n");
    else
        printf("Scalene\n");

    float a2=a*a,b2=b*b,c2=c*c;
    if(fabs(a2+b2-c2)<0.0001||fabs(a2+c2-b2)<0.0001||fabs(c2+b2-a2)<0.0001)
        printf("Right-angled");
    else
        printf("Not Valid");

    return 0;


}
