#include <stdio.h>
//#pragma pack(1)

struct emp{
    int a;
    char ch;
    float s;
    int b;
};

//#pragma pack()

int main()
{
    struct emp e;
    int size = sizeof(e);
    printf("%d\n",size);
    printf("%u %u %u %u\n",&e.a,&e.ch,&e.s,&e.b);
    return 0;
}
