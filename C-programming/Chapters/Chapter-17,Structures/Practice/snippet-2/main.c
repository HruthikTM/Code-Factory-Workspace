#include <stdio.h>
#include <string.h>

int main()
{
    struct part
    {
        char partname[50];
        int partnumber;
    };

    struct part p,*ptr;

    ptr=&p;

    strcpy(p.partname,"Crankshaft");
    p.partnumber=102928;

    printf("%s %d\n",p.partname,p.partnumber);

    printf("%s %d\n",(*ptr).partname,(*ptr).partnumber);

    printf("%s %d\n",ptr->partname,ptr->partnumber);


    return 0;
}
