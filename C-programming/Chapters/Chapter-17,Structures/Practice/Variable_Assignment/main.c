#include <stdio.h>
#include <string.h>

int main()
{

    struct employee
    {
        char name[10];
        int age;
        float sal;
    };

    struct employee e1={"sanjay",25,600000};
    struct employee e2;
    struct employee e3;


    // strcpy(e2.name,e1.name);
    // e2.age=e1.age;
    // e2.sal=e1.sal;

    e3=e2=e1;

    //e3=e2;


    printf("%s %d %f\n",e1.name,e1.age,e1.sal);
    printf("%s %d %f\n",e2.name,e2.age,e2.sal);
    printf("%s %d %f\n",e3.name,e3.age,e3.sal);



    return 0;
}
