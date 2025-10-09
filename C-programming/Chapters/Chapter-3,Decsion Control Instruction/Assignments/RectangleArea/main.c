#include <stdio.h>

int main()
{
    int length=5,breadth=4,area,perimeter;

    area=length*breadth;

    perimeter=2*(length+breadth);

    if(area>perimeter)
        printf("Area of rectangle is greater than its perimeter\n");
    else
       printf("Area of rectangle is smaller than its perimeter\n");

    return 0;
}
