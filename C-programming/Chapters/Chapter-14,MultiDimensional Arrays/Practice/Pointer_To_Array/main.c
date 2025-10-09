#include <stdio.h>


// int main()
// {
//     int* p;
//     int a = 20;
//     p =&a;
//     printf("%d\n",a);
//     printf("%d\n",*p);
//     *p =100;
//     printf("%d\n",*p);



// }
int main()
{

    int s[4][2]=
    {
        {1200,34},
        {1204,93},
        {1208,57},
        {1212,43}
    };


int (*p)[2];

int *pint;

for(int i=0;i<=3;i++)
{
    p=&s[i];
    pint=(int*)p;
    printf("\n");
    for(int j=0;j<=1;j++)
        printf("%d ",*(pint+j));


}
// printf("\n %u pint :",pint);
// printf("\n %u pint :",pint+1);
// printf("\n %d pint :",*pint);
// printf("\n %d pint :",*pint+1);

// printf("\n %u p :",p);
// printf("\n %u p :",p+1);
// printf("\n %d p :",*p);
// printf("\n %d p :",*p+1);




return 0;
}
