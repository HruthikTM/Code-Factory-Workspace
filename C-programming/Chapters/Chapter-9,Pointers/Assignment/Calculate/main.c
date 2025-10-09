#include <stdio.h>

void calculate(int,int,int,int,int,float *,float *);

int main()
{
    int n1,n2,n3,n4,n5;
    float sum,avg;

    printf("Enter the Numbers: ");
    scanf("%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5);

    calculate(n1,n2,n3,n4,n5,&sum,&avg);

    printf("Sum=%f\n",sum);
    printf("Average=%f\n",avg);


    return 0;
}


void calculate(int x1,int x2,int x3,int x4,int x5,float *s,float *a)
{
    *s=x1+x2+x3+x4+x5;
    //*a=(x1+x2+x3+x4+x5)/5;
    *a=*s/5;
}
