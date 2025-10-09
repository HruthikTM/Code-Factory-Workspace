#include <stdio.h>

int main()
{
    int num[]={12,96,83,72,63};
    for(int i=0;i<=4;i++)
    {
        printf("address=%u\t",&num[i]);
        printf("element=%d%d\t",num[i],*(num+i));
        printf("%d%d\n",*(i+num),i[num]);
    }
    return 0;
}
