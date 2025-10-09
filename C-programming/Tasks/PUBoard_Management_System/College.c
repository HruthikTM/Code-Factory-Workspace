#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "PUBoardManager.h"

enum choice
{
    infiniteLoop = 1,
    AddStudentDetails,
    DisplayStudentDetails,
    Logout
};

void addCollegeDetails(PUBoardManager *manager, sqlite3 *db)
{
    if (!manager || !manager->activeBoard) {
        printf("No board is currently logged in\n");
        return;
    }

    struct College *newCollege = (struct College *)malloc(sizeof(College));
    if (!newCollege)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newCollege->studentCount = 0;
    newCollege->studentList = NULL;
    newCollege->nextCollege = NULL;

    char tempCollegeID[500];
    char tempCollegeName[500];

    while (1) {
        int codeExists = 0;

        printf("Enter College Code: ");
        getchar();
        fgets(tempCollegeID, sizeof(tempCollegeID), stdin);
        tempCollegeID[strcspn(tempCollegeID, "\n")] = '\0';


        College *curr = manager->activeBoard->collegeList;
        while (curr != NULL) {
            if (strcmp(curr->collegeCode, tempCollegeID) == 0) {
                codeExists = 1;
                break;
            }
            curr = curr->nextCollege;
        }

        if (codeExists) {
            printf("College code '%s' already exists. Please enter a different code\n", tempCollegeID);
        } else {
            break;
        }
    }

    newCollege->collegeCode = (char*) malloc(strlen(tempCollegeID) + 1);
    strcpy(newCollege->collegeCode, tempCollegeID);

    printf("Enter College Name: ");
    fgets(tempCollegeName, sizeof(tempCollegeName), stdin);
    tempCollegeName[strcspn(tempCollegeName, "\n")] = '\0';
    newCollege->collegeName = (char*) malloc(strlen(tempCollegeName) + 1);
    strcpy(newCollege->collegeName, tempCollegeName);


    College *head = manager->activeBoard->collegeList;

    if (!head)
    {
        manager->activeBoard->collegeList = newCollege;
    }
    else
    {
        while (head->nextCollege != NULL)
        {
            head = head->nextCollege;
        }
        head->nextCollege = newCollege;
    }

    insertCollege(db, newCollege);

    printf("College added successfully\n");
}



void displayCollegeDetails(PUBoardManager *manager)
{
    if (!manager->activeBoard) {
        printf("No board is currently logged in\n");
        return;
    }

    College *temp = manager->activeBoard->collegeList;
    if (!temp)
    {
        printf("\nNo Colleges Available\n");
        return;
    }

    printf("\n--- College List ---\n");
    while (temp)
    {
        printf("College Code : %s\n", temp->collegeCode);
        printf("College Name : %s\n", temp->collegeName);
        printf("Total Students: %d\n", temp->studentCount);
        printf("-------------------------\n");
        temp = temp->nextCollege;
    }
}

void collegeLogin(PUBoardManager *manager,sqlite3 *db)
{
    if (manager->boardCount == 0)
    {
        printf("\nNo boards available. Please add a board first\n");
        return;
    }

    char enteredCollegeCode[10];
    printf("\n--- College Login ---\n");
    printf("Enter College Code: ");
    scanf("%9s", enteredCollegeCode);

    int found = 0;

    for (int i = 0; i < manager->boardCount; i++)
    {
        College *current = manager->boards[i]->collegeList;
        while (current != NULL)
        {
            if (strcmp(enteredCollegeCode, current->collegeCode) == 0)
            {
                printf("\nLogin successful for College: %s\n", current->collegeName);
                found = 1;

                collegeMenuHandler(current, db);
                return;
            }
            current = current->nextCollege;
        }
    }

    if (!found)
    {
        printf("Invalid College Code\n");
    }
}



void collegeMenuHandler(College *current, sqlite3 *db)
{

    int choice = 0;

    while (infiniteLoop)
    {
        printf("\n--- College Menu ---\n");
        printf("1. Add Student Details\n");
        printf("2. Display Student Details\n");
        printf("3. Logout\n");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number\n");
            while (getchar() != '\n');
            continue;
        }

        choice++;

        switch (choice)
        {
        case AddStudentDetails:
            addStudentDetails(current,db);
            break;
        case DisplayStudentDetails:
            displayStudentDetails(current);
            break;
        case Logout:
            printf("Logging out...\n");
            return;
        default:
            printf("Invalid choice. Please try again\n");
        }
    }
}

void freeCollege(College *college)
{
    if (!college)
        return;

    if (college->collegeCode)
        free(college->collegeCode);

    if (college->collegeName)
        free(college->collegeName);

    freeStudentList(college->studentList);

    free(college);
}

void freeCollegeList(College *head)
{
    College *current = head;
    while (current)
    {
        College *temp = current;
        current = current->nextCollege;
        freeCollege(temp);
    }
}
