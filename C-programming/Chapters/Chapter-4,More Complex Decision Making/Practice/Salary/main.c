#include <stdio.h>

int main()
{

    char g;
    int yos,qual,sal=0;

    printf("Enter Gender,Year of Service,Qualification(0=UG,1=PG),Salary: ");
    scanf("%c%d%d",&g,&yos,&qual);

    if(g='M' && yos>=10 && qual==1)
        sal=15000;
    else if((g='M' && yos>=10 && qual==0) || (g='M' && yos<10 && qual==1))
        sal=10000;
    else if(g='M' && yos<10 && qual==0)
        sal=7000;
    else if(g='F' && yos>=10 && qual==1)
        sal=12000;
    else if(g='F' && yos>=10 && qual==0)
        sal=9000;
    else if(g='F' && yos<10 && qual==1)
        sal=10000;
    else if(g='F' && yos<10 && qual==0)
        sal=6000;
    else
        printf("NA");

    printf("Salary of Employee=%d \n",sal);
    return 0;


}
