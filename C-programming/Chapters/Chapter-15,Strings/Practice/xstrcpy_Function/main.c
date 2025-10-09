#include <stdio.h>

void xstrcpy(char *,const char *);

int main()
{
    char source[]="hruthik";
    char target[20];

    xstrcpy(target,source);

    printf("Source String=%s\n",source);
    printf("Target String=%s\n",target);

    return 0;
}


void xstrcpy(char *t, const char *s)
{
    while(*s!='\0')
    {
        *t=*s;
        s++;
        t++;
    }

    *t='\0';
}
