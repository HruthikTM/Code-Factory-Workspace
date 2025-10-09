#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PUBoardManager.h"
#include "Subject.h"
#include "subjectData.h"
#include "evaluatorDB.h"

enum choice
{
    infiniteLoop = 1,
    EnterStudentMarks,
    Logout
};

int evaluatorCount;

char subjectCodeTemp[10];

void addEvaluator(PUBoardManager *manager, sqlite3 *db)
{
    if (!manager || !manager->activeBoard)
    {
        printf("No active board selected. Please log in first.\n");
        return;
    }

    PUBoard *board = manager->activeBoard;

    if (board->evaluatorCount >= MAX_EVALUATOR)
    {
        printf("Maximum number of evaluators reached for this board.\n");
        return;
    }

    printf("\n--- Add Evaluator ---\n");
    char tempEvaluatorId[500], tempEvaluatorPassword[500], subjectCode[10];

    Evaluator *newEvaluator = (Evaluator *)malloc(sizeof(Evaluator));
    if (!newEvaluator)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Set User ID: ");
    getchar();
    fgets(tempEvaluatorId, sizeof(tempEvaluatorId), stdin);
    tempEvaluatorId[strcspn(tempEvaluatorId, "\n")] = '\0';


    for (int i = 0; i < board->evaluatorCount; i++)
    {
        if (strcmp(board->evaluators[i]->userId, tempEvaluatorId) == 0)
        {
            printf("Evaluator with this User ID already exists.\n");
            free(newEvaluator);
            return;
        }
    }

    newEvaluator->userId = strdup(tempEvaluatorId);
    if (!newEvaluator->userId)
    {
        printf("Memory allocation failed.\n");
        free(newEvaluator);
        return;
    }

    printf("Set Password: ");
    fgets(tempEvaluatorPassword, sizeof(tempEvaluatorPassword), stdin);
    tempEvaluatorPassword[strcspn(tempEvaluatorPassword, "\n")] = '\0';

    newEvaluator->password = strdup(tempEvaluatorPassword);
    if (!newEvaluator->password)
    {
        printf("Memory allocation failed.\n");
        free(newEvaluator->userId);
        free(newEvaluator);
        return;
    }

    printf("Enter Subject Code: ");
    scanf("%9s", subjectCode);


    Subject *subjects = getGlobalSubjects();
    int subjectCount = getSubjectCount();
    int found = 0;

    for (int i = 0; i < subjectCount; i++)
    {
        if (strcmp(subjects[i].subjectCode, subjectCode) == 0)
        {
            newEvaluator->subject = &subjects[i];
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Invalid subject code. Evaluator not added.\n");
        free(newEvaluator->userId);
        free(newEvaluator->password);
        free(newEvaluator);
        return;
    }

    printf("Enter max students evaluator can mark: ");
    if (scanf("%d", &newEvaluator->studentLimit) != 1 || newEvaluator->studentLimit <= 0)
    {
        printf("Invalid input for student limit.\n");
        free(newEvaluator->userId);
        free(newEvaluator->password);
        free(newEvaluator);
        return;
    }

    newEvaluator->studentCount = 0;
    newEvaluator->results = NULL;

    for (int i = 0; i < MAX_ASSIGNED_STUDENTS; i++)
        newEvaluator->assignedStudentIds[i] = NULL;


    board->evaluators[board->evaluatorCount++] = newEvaluator;


    insertEvaluator(db, newEvaluator);

    printf("Evaluator added successfully to board '%s'\n", board->boardName);
}

void evaluatorLogin(PUBoardManager *manager, sqlite3 *db)
{
    if (manager->boardCount == 0)
    {
        printf("No boards available in the system. Please contact the admin\n");
        return;
    }

    int evaluatorExists = 0;
    for (int i = 0; i < manager->boardCount; i++)
    {
        if (manager->boards[i]->evaluatorCount > 0)
        {
            evaluatorExists = 1;
            break;
        }
    }

    if (!evaluatorExists)
    {
        printf("No evaluators added yet. Please contact the board admin\n");
        return;
    }

    char enteredUserId[20];
    char enteredPassword[20];

    printf("\n--- Evaluator Login ---\n");
    printf("Enter User ID: ");
    scanf("%19s", enteredUserId);
    printf("Enter Password: ");
    scanf("%19s", enteredPassword);

    PUBoard *matchedBoard = NULL;
    Evaluator *matchedEvaluator = NULL;

    for (int i = 0; i < manager->boardCount; i++)
    {
        PUBoard *board = manager->boards[i];

        for (int j = 0; j < board->evaluatorCount; j++)
        {
            if (strcmp(enteredUserId, board->evaluators[j]->userId) == 0)
            {
                if (strcmp(enteredPassword, board->evaluators[j]->password) == 0)
                {
                    matchedBoard = board;
                    matchedEvaluator = board->evaluators[j];
                    break;
                }
                else
                {
                    printf("Incorrect password\n");
                    return;
                }
            }
        }

        if (matchedEvaluator != NULL)
            break;
    }

    if (matchedEvaluator == NULL)
    {
        printf("Evaluator not found. Please check your credentials\n");
        return;
    }

    if (matchedEvaluator->subject != NULL)
        printf("\nLogin successful! Evaluator for Subject: %s\n", matchedEvaluator->subject->subjectName);
    else
        printf("\nLogin successful! Subject information not available\n");

    evaluatorMenuHandler(matchedEvaluator, matchedBoard->collegeList,db);

}


void enterStudentMarks(Evaluator *currentEvaluator, College *collegeList,sqlite3 *db)
{
    if (!currentEvaluator || !currentEvaluator->subject || !collegeList)
    {
        printf("Evaluator or required data is missing\n");
        return;
    }

    if (currentEvaluator->studentCount >= currentEvaluator->studentLimit)
    {
        printf("Evaluator has already marked the maximum allowed number of students (%d)\n", currentEvaluator->studentLimit);
        return;
    }

    const char *targetSubjectCode = currentEvaluator->subject->subjectCode;
    char studentId[20];
    printf("Enter Student ID to enter marks: ");
    scanf("%s", studentId);

    for (int i = 0; i < currentEvaluator->studentCount; ++i)
    {
        if (strcmp(currentEvaluator->assignedStudentIds[i], studentId) == 0)
        {
            printf("Marks have already been entered for student ID %s\n", studentId);
            return;
        }
    }

    // int markedCount = 0;
    // for (int i = 0; i < currentEvaluator->studentLimit; ++i) {
    //     if (currentEvaluator->assignedStudentIds[i] != NULL)
    //         markedCount++;
    // }
    // if (markedCount >= currentEvaluator->studentLimit) {
    //     printf("Evaluator has already marked the maximum allowed number of students (%d)\n", currentEvaluator->studentLimit);
    //     return;
    // }

    Student *targetStudent = NULL;
    College *college = collegeList;

    while (college && !targetStudent)
    {
        Student *student = college->studentList;
        while (student)
        {
            if (strcmp(student->studentID, studentId) == 0)
            {
                targetStudent = student;
                break;
            }
            student = student->nextStudent;
        }
        college = college->nextCollege;
    }

    if (!targetStudent)
    {
        printf("Student with ID %s not found in any college\n", studentId);
        return;
    }

    StudentAcademicDetails *studentAcademicDetails = targetStudent->studentAcademicDetails;
    if (!studentAcademicDetails)
    {
        printf("No academic details found for student ID %s\n", studentId);
        return;
    }

    for (int i = 0; i < SUBJECT_COUNT; ++i)
    {
        Result *res = studentAcademicDetails->results[i];
        if (res && res->subject && strcmp(res->subject->subjectCode, targetSubjectCode) == 0)
        {
            if (res->marks->obtainedMarks != -1)
            {
                printf("Marks already recorded for subject %s for student ID %s.\n", targetSubjectCode, studentId);
                return;
            }

            int marks;
            res->marks->totalMarks = 100;

            printf("Enter marks for student %s in %s (out of 100): ", studentId, res->subject->subjectName);
            scanf("%d", &marks);

            if(marks < 0 || marks > 100)
            {
                printf("Invalid marks\n");
                return;
            }

            res->marks->obtainedMarks = marks;
            res->marks->percentage = ((float)marks / 100.0f) * 100.0f;

            float pct = res->marks->percentage;
            if (pct >= 90)
                res->marks->grade = 'A';
            else if (pct >= 75)
                res->marks->grade = 'B';
            else if (pct >= 60)
                res->marks->grade = 'C';
            else if (pct >= 50)
                res->marks->grade = 'D';
            else
                res->marks->grade = 'F';

            currentEvaluator->assignedStudentIds[currentEvaluator->studentCount] = malloc(strlen(studentId) + 1);
            strcpy(currentEvaluator->assignedStudentIds[currentEvaluator->studentCount], studentId);
            currentEvaluator->studentCount++;

            insertStudentMarksToDB(db, studentId, targetSubjectCode, res->marks->totalMarks, marks, pct, res->marks->grade, currentEvaluator->userId, currentEvaluator->studentCount);

            printf("Marks entered successfully for student ID %s\n", studentId);
            return;
        }
    }

    printf("Subject %s not found in student %s's academic records\n", targetSubjectCode, studentId);
}

void evaluatorMenuHandler(Evaluator *evaluator, College *collegeList, sqlite3 *db)
{
    int choice = 0;

    while (infiniteLoop)
    {
        printf("\n--- Evaluator Menu ---\n");
        printf("1. Enter Student Marks\n");
        printf("2. Logout\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number\n");
            while (getchar() != '\n');
            continue;
        }

        choice++;

        switch (choice)
        {
        case EnterStudentMarks:
            enterStudentMarks(evaluator, collegeList, db);
            break;
        case Logout:
            printf("Logging out...\n");
            return;
        default:
            printf("Invalid choice. Please try again\n");
        }
    }
}

void freeEvaluator(Evaluator *evaluator)
{
    if (!evaluator)
        return;

    free(evaluator->userId);
    free(evaluator->password);

    for (int i = 0; i < MAX_ASSIGNED_STUDENTS; i++)
        free(evaluator->assignedStudentIds[i]);

    if (evaluator->results)
        free(evaluator->results);


    free(evaluator);
}

void freeBoardEvaluators(PUBoard *board)
{
    if (!board)
        return;

    for (int i = 0; i < board->evaluatorCount; i++)
        freeEvaluator(board->evaluators[i]);
}
