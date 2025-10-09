#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3


struct Cricketer {
    char name[50];
    int age;
    int matches;
    float average;
};


int compareByAverage(const void *a, const void *b) {
    float avgA = ((struct Cricketer *)a)->average;
    float avgB = ((struct Cricketer *)b)->average;

    if (avgA < avgB)
        return -1;
    else if (avgA > avgB)
        return 1;
    else
        return 0;
}

int main() {
    struct Cricketer players[MAX];

    printf("Enter details of 20 cricketers:\n");
    for (int i = 0; i < MAX; i++) {
        printf("\nCricketer %d:\n", i + 1);
        printf("Name: ");
        scanf(" %s", players[i].name);
        printf("Age: ");
        scanf("%d", &players[i].age);
        printf("Number of Test Matches: ");
        scanf("%d", &players[i].matches);
        printf("Average Runs: ");
        scanf("%f", &players[i].average);
    }

    qsort(players, MAX, sizeof(struct Cricketer), compareByAverage);


    printf("\nCricketers sorted by average runs (ascending):\n");
    printf("----------------------------------------------------------\n");
    printf("%-20s %-5s %-10s %-10s\n", "Name", "Age", "Matches", "Average");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < MAX; i++) {
        printf("%-20s %-5d %-10d %-10.2f\n", players[i].name, players[i].age, players[i].matches, players[i].average);
    }

    return 0;
}
