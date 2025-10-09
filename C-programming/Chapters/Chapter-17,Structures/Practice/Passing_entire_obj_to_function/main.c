#include <stdio.h>

struct book{
    char name[20];
    char author[20];
    int callno;
};

void display(struct book);

int main()
{


    struct book b={"Let us c","YPK",101};
    display(b);

    return 0;
}

void display(struct book b)
{
    printf("%s %s %d\n",b.name,b.author,b.callno);
}
