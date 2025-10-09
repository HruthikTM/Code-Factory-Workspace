#include <stdio.h>
//#include <string.h>

void xstrcat(char *,const char *);

int main()
{
    char source[]="Hruthik";
    char target[20]="T M ";

    xstrcat(target,source);

    printf("Source String=%s\n",source);
    printf("Target String=%s\n",target);

    return 0;
}

void xstrcat(char *t, const char *s)
{
    while(*t!='\0'){  //move to the end of the target string
        t++;
    }

    while(*s!='\0'){  //copy source string to target
        *t=*s;
        t++;
        s++;
    }

    *t='\0';  //init t to null

}
