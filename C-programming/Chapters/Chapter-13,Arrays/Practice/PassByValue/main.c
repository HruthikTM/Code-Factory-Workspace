#include <stdio.h>

void display(int);

int main()
{
    int marks[]={12,56,84,19,73,52};
    for(int i=0;i<=5;i++)
    {
        display(marks[i]);
    }

    return 0;
}


void display(int n)
{
    printf("%d\n",n);
}
