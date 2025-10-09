#include <stdio.h>
#include<math.h>

int main()
{

    float l1,l2,l3,area,s;
    printf("Enter lengths of triangle: ");
    scanf("%f%f%f",&l1,&l2,&l3);

    s=(l1+l2+l3)/2;

    area=sqrt(s*(s-l1)*(s-l2)*(s-l3));

    printf("%f",area);

    return 0;





}
