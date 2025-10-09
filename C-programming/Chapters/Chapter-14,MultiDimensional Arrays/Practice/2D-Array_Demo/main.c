#include <stdio.h>

int main()
{

    int s[4][2]={

        {1200,34},
        {1204,93},
        {1208,57},
        {1212,43}
    };

    for(int i=0;i<=3;i++)
    {
        printf("Address of %dth 1-D array=%u\n",i,s[i]);
    }

    return 0;
}
