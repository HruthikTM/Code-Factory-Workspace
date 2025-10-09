#include <stdio.h>

void display(char *,char *,int);

struct book{
    char name[20];
    char author[20];
    int callno;
};

int main()
{
    struct book b={"Let us C","YPK",101};

    display(b.name,b.author,b.callno);

    return 0;
}

void display(char *s,char *t,int n)
{
    printf("%s %s %d\n",s,t,n);
}
