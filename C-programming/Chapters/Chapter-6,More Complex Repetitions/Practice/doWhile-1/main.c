#include <stdio.h>

int main()
{
    char another;
    int num;

    do
    {
        printf("Enter a number: ");
        scanf("%d",&num);

        printf("Sq of %d is %d\n",num,num*num);

        printf("Want another number y/n");
        fflush(stdin);
        scanf("%c",&another);
    }while(another=='y');

             return 0;
}

