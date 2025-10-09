#include <stdio.h>

// Function to check leapyear
int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

//Function to get number of days in a month
int get_days_in_month(int month, int year) {
    switch (month) {
    case 2:
        return is_leap_year(year) ? 29 : 28;
    case 4: case 6: case 9: case 11:
        return 30;
    default:
        return 31;
    }
}

// Function to get total number of days since 01/01/1900
int get_total_days_since_base(int month, int year) {
    int total_days = 0;
    int y, m;

    // Add days for full years
    for (y = 1900; y < year; y++) {
        total_days += is_leap_year(y) ? 366 : 365;
    }

    // Add days for full months in current year
    for (m = 1; m < month; m++) {
        total_days += get_days_in_month(m, year);
    }

    return total_days;
}

// Function to print the calendar
void print_calendar(int month, int year) {
    char *months[] = {"", "January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};

    int total_days = get_total_days_since_base(month, year);
    int start_day = (total_days + 1) % 7; // 01/01/1900 was Monday => Monday = 1

    printf("\n     %s %d\n", months[month], year);
    printf("Sun Mon Tue Wed Thu Fri Sat \n");

    // Print initial spaces
    int i;
    for (i = 0; i < start_day; i++) {
        printf("    ");
    }

    // Print the days of the month
    int days_in_month = get_days_in_month(month, year);
    for (int day = 1; day <= days_in_month; day++) {
        printf("%3d ", day);
        if ((start_day + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);


    if(month<1||month>12||year<1900)
    {
        printf("Invalid input. Month must be 1-12 and year >= 1900.\n");
        return 1;
    }

    print_calendar(month, year);
    return 0;
}
