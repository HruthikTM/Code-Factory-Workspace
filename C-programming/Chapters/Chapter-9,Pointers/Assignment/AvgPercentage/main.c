#include <stdio.h>


void calculate(int,int,int,float *,float *);

int main()
{
    int m1,m2,m3;
    float avg,per;

    printf("Enter the marks: ");
    scanf("%d%d%d",&m1,&m2,&m3);

    calculate(m1,m2,m3,&avg,&per);

    printf("Avgrage=%f\n",avg);
    printf("Percentage=%f\n",per);
}

void calculate(int m1, int m2, int m3, float *avg, float *per)
{
    int sum=m1+m2+m3;
    *avg=sum/3;
    *per=sum/300*100;
}
