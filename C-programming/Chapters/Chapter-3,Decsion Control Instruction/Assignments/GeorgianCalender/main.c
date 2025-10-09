#include <stdio.h>

int isLeap(int year){
    if((year%4==0 && year%100!=0)||year%400==0)
        return 1;
    else
        return 0;
}

void findDay(int year){

    int totDays=0;
    int day_index;

    char days[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};


    for(int i=1;i<year;i++){
        if(isLeap(i))
            totDays=totDays+366;
        else
            totDays=totDays+365;
    }

    day_index=totDays%7;

    printf("1st Jan of %d is %s\n",year,days[day_index]);

}

int main()
{
    int year;
    printf("Enter the year: ");
    scanf("%d",&year);
    if (year < 1) {
        printf("invalid input");
        return 1;
    }


    findDay(year);

    return 0;
}
