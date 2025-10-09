#include <stdio.h>

int main()
{
    int i=0;
    char ch='A';
    float a=3.14;
    char str[20];

    printf("%d%c%f\n",i,ch,a);
    sprintf(str,"%d%c%f\n",i,ch,a);
    printf("%s\n",str);

    return 0;
}
