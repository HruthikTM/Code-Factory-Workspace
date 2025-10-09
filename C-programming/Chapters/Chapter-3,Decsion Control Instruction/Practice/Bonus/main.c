#include <stdio.h>

int main()
{
    int bonus,yoj,cy,yos;

    printf("Enter current year and year of joining: ");
    scanf("%d%d",&cy,&yoj);

    yos=cy-yoj;

    if(yos>3){
        bonus=3000;
        printf("Bonus=Rs.%d\n",bonus);
    }

    return 0;
}
