#include <stdio.h>

int main()
{

    struct book{

        // char name[20];
        // float price;
        // int pages;
        //char name[20];

        //char ch;
        // char name[20];
        // //char chr;
        // float price;
        // int pages;
        // int n;

        int n;
        char c;
        float f;
        double d;
        //*/char c;

    };

    //struct book b={"hhh",140.0,32,90};

    struct book b={12,'v',3.6,1878.3};

    int size=sizeof(struct book);
    printf("%d\n",size);

    printf("hi..");

   // struct book b={140.0,861,"ABC"};


    //printf("Address of character=%u\n",&b.ch);
    // printf("Address of name=%u\n",&b.name);
    // //printf("Address of character=%u\n",&b.chr);
    // printf("Address of price=%u\n",&b.price);
    // printf("Address of pages=%u\n",&b.pages);
    // printf("Address of n=%u\n",&b.n);




    return 0;
}
