#include <stdio.h>

void areaPeri(int,float *,float *);

int main()
{
    int radius;
    float area,perimeter;

    printf("Enter radius of Circle: ");
    scanf("%d",&radius);
    areaPeri(radius,&area,&perimeter);

    printf("Area=%f\n",area);
    printf("Perimeter=%f\n",perimeter);

    return 0;
}

void areaPeri(int r,float *a,float *p){

    *a=3.14*r*r;
    *p=2*3.14*r;

}

