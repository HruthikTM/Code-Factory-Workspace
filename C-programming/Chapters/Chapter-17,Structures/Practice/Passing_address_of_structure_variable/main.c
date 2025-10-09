#include <stdio.h>

struct book
{
    char name[25];
    char author[25];
    int callno;
};

void display(struct book *);

int main()
{
    struct book b={"let us c","YPK",030};

    display(&b);

    return 0;
}

void display(struct book *b)
{
    printf("%s %s %d\n",b->name,b->author,b->callno);
}
