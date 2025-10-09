#include <stdio.h>

int main()
{

    struct book{
        char name[20];
        char author[20];
        int callno;
    };

    struct book b={"Let us C","YPK",101};

    struct book *ptr;

    ptr=&b;

    printf("%s %s %d\n",b.name,b.author,b.callno);
    printf("%s %s %d\n",ptr->name,ptr->author,ptr->callno);

    return 0;
}
