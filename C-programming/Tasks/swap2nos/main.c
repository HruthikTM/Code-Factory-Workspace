#include <stdio.h>

void swap(int * , int *);

void print(int *);

int main()
{
    int a = 150;
    int b = 20;

    printf("Before Swapping %d %d\n",a,b);

    swap(&a, &b);

    printf("After Swapping %d %d\n", a, b);

    int c = 30;
    print(&c);
    printf("%d\n",c);

    return 0;
}


void swap(int *x,int *y)
{
    int temp;


    // temp=a;
    // a=b;
    // b=temp;

    temp = *x;
    *x = *y;
    *y = temp;

    // printf("value of x,y is %d %d\n", *x, *y);
}

void print(int *p){
    printf("%d\n",*p);

    *p = 10;
}
