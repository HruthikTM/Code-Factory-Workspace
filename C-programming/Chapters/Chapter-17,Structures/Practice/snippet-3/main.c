#include <stdio.h>

struct gospel{
    int num;
    char mess1[50];
    char mess2[50];
}m1={
    2,"Hello world","Good evening"
};


int main()
{
    struct gospel m2,m3;
    m2=m1;
    m3=m2;

    printf("%d %s %s\n",m1.num,m1.mess1,m1.mess2);
    printf("%d %s %s\n",m2.num,m2.mess1,m2.mess2);
    printf("%d %s %s\n",m3.num,m3.mess1,m3.mess2);
    return 0;
}
