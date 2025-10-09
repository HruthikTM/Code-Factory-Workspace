#include <stdio.h>
//#pragma pack(1)
int main()
{

    struct example{
        // char *type;
        // int n;
        // char c;


        long employeePhoneNumber;
        char employeeName[20];
        char employeeId[20];
        char employeeMailId[20];
        char employeeRole[20];

        // char abc[10];
        // char bcd[10];
        // double d;
        // float f;
        //int l;

        // char a;
        // double d;
        // float b;
        // char c;

        // float a;
        // double b;

        // double k;
        // char y;



        // char c;
        // char b;
        // int a;
    };

//#pragma pack()


    struct example e={666565656,"goodqwerty","qwer","iiit","uririr"};



    //struct example e={"goodqwerty","hdhdhd",1.36,367.737};

    //struct example e={'a','b',789.738,67.9};

    //struct example e={'b',1,'c'};

    //struct example e={10.25,'c'};


    int size=sizeof(e);
    printf("struct size e %d\n",size);


    printf("%u\n",&e.employeePhoneNumber);

    printf("%u\n",&e.employeeName);



    printf("%u\n",&e.employeeId[1]);

    printf("%u\n",&e.employeeMailId);

    printf("%u\n",&e.employeeRole);



    // float f=3.14;
    // double x=245.343;

    // printf("size of float:%d\n",sizeof(f));

    // printf("size of double:%d\n",sizeof(x));





   // printf("hi..");
}



