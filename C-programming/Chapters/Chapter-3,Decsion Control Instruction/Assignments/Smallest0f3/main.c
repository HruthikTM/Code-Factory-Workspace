#include <stdio.h>

int main()
{
    int age1,age2,age3,smallest;
    printf("Enter the ages of Ram,Shayam,Ajay: ");
    scanf("%d%d%d",&age1,&age2,&age3);
    return 0;

    smallest=age1;

    if(age2<smallest)
        smallest=age2;

    if(age3<smallest)
        smallest=age3;

    printf("%d\n",smallest);
}
