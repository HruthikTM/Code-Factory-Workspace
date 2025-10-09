#include <stdio.h>

int main()
{
    int weight=98;
    char fname1[]="sandy";
    char sname1[]="malya";

    char fname2[]="ajay";
    char sname2[]="kumar";

    printf("Weight is %d kg\n",weight);
    printf("Weight is %2d kg\n",weight);
    printf("Weight is %4d kg\n",weight);
    printf("Weight is %6d kg\n",weight);
    printf("Weight is %-6d kg\n",weight);
    printf("Weight is %1d kg\n",weight);


    printf("%10d%10d%10d\n",weight,weight,weight);
    printf("%7d%7d%7d\n",weight,weight,weight);

    printf("%20s%20s\n",fname1,sname1);
    printf("%20s%20s\n",fname2,sname2);
    return 0;
}
