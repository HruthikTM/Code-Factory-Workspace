#include <stdio.h>

int main()
{
    int m1, m2, m3, m4, m5;
    float per;

    printf("Enter the marks (out of 100) for 5 subjects: ");
    scanf("%d%d%d%d%d", &m1, &m2, &m3, &m4, &m5);

    per = ((m1 + m2 + m3 + m4 + m5) / 500.0) * 100;

    if (per >= 60)
        printf("First class\n");
    else if (per >= 50)
        printf("Second class\n");
    else if (per >= 35)
        printf("Third class\n");
    else
        printf("Fail\n");

    return 0;
}
