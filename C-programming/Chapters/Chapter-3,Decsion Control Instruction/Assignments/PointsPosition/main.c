#include <stdio.h>
#include <math.h>

int main()
{
    float xc,yc,radius;
    float x,y;
    float distance;

    printf("Enter the Center of the circle (xc,yc): \n");
    scanf("%f%f",&xc,&yc);

    printf("Enter the radius of the circle: \n");
    scanf("%f",&radius);

    printf("Enter the co-ordinates of circle (x,y): \n");
    scanf("%f%f",&x,&y);

    distance=sqrt(pow(x-xc,2) + pow(y-yc,2));

    if(distance<radius){
        printf("Lies inside the circle\n");
    }
    else if(distance==radius){
        printf("Lies on the circle\n");
    }
    else
    {
        printf("Lies outside the circle\n");
    }

    return 0;
}
