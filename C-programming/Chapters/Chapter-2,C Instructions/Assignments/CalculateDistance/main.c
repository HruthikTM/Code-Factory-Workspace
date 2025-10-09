#include <stdio.h>
#include<math.h>

int main()
{
    int l1,l2,g1,g2;
    float distance;

    printf("Enter values of latitude and longitude: ");
    scanf("%d%d%d%d",&l1,&l2,&g1,&g2);

    distance=3963*acos(sin(l1)*sin(l2)+(cos(l1)*cos(l2))*cos(g2-g1));

    printf("%f",distance);

    return 0;
}
