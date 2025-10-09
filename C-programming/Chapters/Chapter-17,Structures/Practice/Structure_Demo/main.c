#include <stdio.h>

int main()
{
    // struct book
    // {
    //     char name;
    //     float price;
    //     int pages;
    // };
    // struct book b1, b2, b3;

    // struct book
    // {
    //     char name;
    //     float price;
    //     int pages;
    // }
    // b1, b2, b3;

    // struct
    // {
    //     char name;
    //     float price;
    //     int pages;
    // }
    // b1, b2, b3;

    struct book
    {
        char name[20];
        float price;
        int pages;
    };

    struct book b1={"book1",130.00,56};
    struct book b2={"b00k2",530.00,568};
    struct book b3={0};

    //All the above structure declearation and defenation are working

    // printf("Enter the name, price & no. of pages of 3 books\n");

    // scanf(" %c %f %d", &b1.name, &b1.price, &b1.pages);
    // scanf("\n%c %f %d", &b2.name, &b2.price, &b2.pages);
    // scanf("%c %f %d", &b3.name, &b3.price, &b3.pages);



    printf("And this is what you entered\n");

    printf(" %s %f %d\n", b1.name, b1.price, b1.pages);
    printf(" %s %f %d\n", b2.name, b2.price, b2.pages);
    printf(" %s %f %d\n", b3.name, b3.price, b3.pages);

    return 0;
}
