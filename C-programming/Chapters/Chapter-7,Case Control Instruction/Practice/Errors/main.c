#include <stdio.h>

int main()
{
    // int suite=1;
    // switch(suite);
    // {
    //     case 1:
    //         printf("Clube\n");
    //     case 2:
    //         printf("Heart\n");
    // }


    // int temp;
    // scanf("%d",&temp);
    // switch(temp)
    // {
    // case(temp<=20):
    //     printf("Apple\n");
    // case(temp>20&&temp<=30):
    //     printf("Banana\n");
    // default:
    //     printf("Grape\n");

    // }

    // float a=3.5;
    // switch(a)
    // {
    // case 0.5:
    //     printf("Apple\n");
    // case 3.5:
    //     printf("Banana\n");
    // default:
    //     printf("Grape\n");

    // }

    int a=3,b=4,c;
    c=b-a;
    switch(c)
    {
    case 1||2:
        printf("Coffee Break\n");
        break;
    case a||b:
        printf("Tea Break\n");
        break;
    }

    return 0;
}
