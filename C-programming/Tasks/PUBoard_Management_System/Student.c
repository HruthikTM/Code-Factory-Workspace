#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PUBoardManager.h"

enum choice
{
    infiniteLoop = 1,
    GetResult,
    Logout
};


void addStudentDetails(College *current, sqlite3 *db)
{
    if (!current)
    {
        printf("Invalid college pointer.\n");
        return;
    }

    Student *newStudent = (Student *)malloc(sizeof(Student));
    if (!newStudent)
    {
        printf("Memory allocation failed for Student\n");
        return;
    }

    char tempStudentID[500];


    while (1)
    {
        int idExists = 0;

        printf("Enter Student Id: ");
        getchar();
        fgets(tempStudentID, sizeof(tempStudentID), stdin);
        tempStudentID[strcspn(tempStudentID, "\n")] = '\0';


        Student *currStudent = current->studentList;
        while (currStudent != NULL)
        {
            if (strcmp(currStudent->studentID, tempStudentID) == 0)
            {
                idExists = 1;
                break;
            }
            currStudent = currStudent->nextStudent;
        }

        if (idExists)
        {
            printf("Student ID '%s' already exists in this college. Please enter a different ID.\n", tempStudentID);
        }
        else
        {
            break;
        }
    }

    newStudent->studentID = (char *)malloc(strlen(tempStudentID) + 1);
    strcpy(newStudent->studentID, tempStudentID);

    newStudent->studentPersonalDetails = (StudentPersonalDetails *)enterStudentPersonalDetails();
    if (!newStudent->studentPersonalDetails)
    {
        printf("Failed to enter personal details.\n");
        free(newStudent->studentID);
        free(newStudent);
        return;
    }

    newStudent->studentAcademicDetails = (StudentAcademicDetails *)enterStudentAcademicDetails();
    if (!newStudent->studentAcademicDetails)
    {
        printf("Failed to enter academic details.\n");
        free(newStudent->studentID);
        free(newStudent->studentPersonalDetails);
        free(newStudent);
        return;
    }

    newStudent->nextStudent = NULL;

    if (!current->studentList)
        current->studentList = newStudent;
    else
    {
        Student *temp = current->studentList;
        while (temp->nextStudent)
            temp = temp->nextStudent;
        temp->nextStudent = newStudent;
    }

    current->studentCount++;

    insertStudent(db, current->collegeCode, newStudent);

    printf("Student added successfully to %s (%s).\n", current->collegeName, current->collegeCode);
}


void displayStudentDetails(College *current)
{
    if (!current)
    {
        printf("No college found.\n");
        return;
    }

    Student *student = current->studentList;
    if (!student)
    {
        printf("No students found for the college: %s\n", current->collegeName);
    }
    else
    {
        printf("\n--- Student List for College %s ---\n", current->collegeName);
        while (student)
        {
            printf("Student ID: %s\n", student->studentID);
            displayStudentPersonalDetails(student->studentPersonalDetails);
            displayStudentAcademicDetails(student->studentAcademicDetails);
            printf("-------------------------\n");
            student = student->nextStudent;
        }
    }
}


void studentLogin(PUBoardManager *manager, sqlite3 *db)
{
    College *college = NULL;
    Student *foundStudent = NULL;

    printf("\n--- Student Login ---\n");
    char enteredStudentID[50];
    printf("Enter Student ID: ");
    scanf("%49s", enteredStudentID);

    for (int i = 0; i < manager->boardCount; i++)
    {
        PUBoard *board = manager->boards[i];
        college = board->collegeList;

        while (college != NULL)
        {
            Student *current = college->studentList;

            while (current != NULL)
            {
                if (strcmp(enteredStudentID, current->studentID) == 0)
                {
                    foundStudent = current;
                    break;
                }
                current = current->nextStudent;
            }

            if (foundStudent) break;
            college = college->nextCollege;
        }

        if (foundStudent) break;
    }

    if (foundStudent)
    {
        printf("\nLogin successful for Name: %s\n", foundStudent->studentPersonalDetails->studentName);
        studentMenuHandler(foundStudent,db);
    }
    else
    {
        printf("Invalid Student ID or student data not loaded.\n");
    }
}

void studentMenuHandler(Student *current,sqlite3 *db)
{
    int choice = 0;

    while (infiniteLoop)
    {
        printf("\n--- Student Menu ---\n");
        printf("1. Get Result\n");
        printf("2. Logout\n");
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
        case GetResult:
            getIndividualStudentResult(current,db);
            break;
        case Logout:
            printf("Logging out...\n");
            return;
        default:
            printf("Invalid choice. Please try again\n");
        }
    }
}



void freeStudent(Student *student) {
    if (!student)
        return;

    free(student->studentID);
    freeStudentPersonalDetails(student->studentPersonalDetails);
    freeStudentAcademicDetails(student->studentAcademicDetails);
    free(student);
}

void freeStudentList(Student *head) {
    while (head) {
        Student *temp = head;
        head = head->nextStudent;
        freeStudent(temp);
    }
}
