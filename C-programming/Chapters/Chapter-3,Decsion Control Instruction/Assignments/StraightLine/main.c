#include <stdio.h>

int main()
{
    float x1,x2,x3,y1,y2,y3;

    printf("Enter first co-ordinates:\n");
    scanf("%f%f",&x1,&y1);


    printf("Enter second co-ordinates:\n");
    scanf("%f%f",&x2,&y2);

    printf("Enter third co-ordinates:\n");
    scanf("%f%f",&x3,&y3);

    if((y2-y1)*(x3-x2)==(y3-y2)*(x2-x1))
        printf("The points fall on one straight line\n");
    else
        printf("The points doesn't fall on one straight line\n");


    return 0;
}
