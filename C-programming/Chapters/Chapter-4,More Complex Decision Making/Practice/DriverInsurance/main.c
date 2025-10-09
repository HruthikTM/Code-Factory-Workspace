#include <stdio.h>

int main()
{
    int age;
    char ms, sex;

    printf("Enter Age, Marital Status (M/U), and Sex (M/F) of Driver: ");
    scanf("%d %c %c", &age, &ms, &sex);
    if ((ms == 'M') || (ms == 'U' && age >= 30 && sex == 'M') || (ms == 'U' && age >= 25 && sex == 'F'))
        printf("Driver should be Insured\n");
    else
        printf("Driver shouldn't be Insured\n");

    return 0;
}
