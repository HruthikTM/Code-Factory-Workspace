#include <stdio.h>

struct address{
    char phone[15];
    char city[20];
    int pin;
};
                //This also shows structures can be decleared any where in the code.
struct emp{
    char name[15];
    struct address a;
};



int main()
{
    struct emp e={"hruthik","8660195850","mysuru",570023};

    printf(" name=%s\n phone=%s\n city=%s\n pin=%d\n",e.name,e.a.phone,e.a.city,e.a.pin);

    return 0;
}
