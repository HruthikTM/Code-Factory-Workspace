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
        for(int j=0;j<=1;j++)
        {
            //printf("%d ",*(*(s+i)+j));

            //printf("%d ",*(s[i]+j));

            //printf("%d ",s[i][j]);

            //All printf statments prints same result
        }

        printf("\n");
    }

    return 0;
}
