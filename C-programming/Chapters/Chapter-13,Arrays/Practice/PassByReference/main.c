#include <stdio.h>

void display(int *);

int main()
{
    int marks[]={58,36,29,83,47,94};
    for(int i=0;i<=5;i++)
    {
        display(&marks[i]);
    }
    return 0;
}


void display(int *n)
{
    printf("%d\n",*n);
}
