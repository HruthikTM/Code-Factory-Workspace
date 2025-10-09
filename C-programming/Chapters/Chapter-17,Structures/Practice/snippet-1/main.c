#include <stdio.h>
#include <string.h>

int main()
{
    struct gospel
    {
        int num;
        char mess1[50];
        char mess2[50];
    }m;

    m.num=1;
    strcpy(m.mess1,"Hello world");
    strcpy(m.mess2,"World hello");


    printf("%u %u %u\n",&m.num,m.mess1,m.mess2);
    return 0;
}
