#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PUBoardManager.h"


void displayCollegeWisePassPercentage(PUBoardManager *manager)
{
    if (!manager->activeBoard->collegeList)
    {
        printf("No colleges available\n");
        return;
    }

    struct College *college = manager->activeBoard->collegeList;
    printf("\n--- College-wise Pass Percentage ---\n");

    while (college)
    {
        int totalStudents = 0;
        int passedStudents = 0;

        struct Student *student = college->studentList;
        while (student)
        {
            totalStudents++;
            int isFail = 0;
            int incompleteMarks = 0;

            StudentAcademicDetails *studentAcademicDetails = student->studentAcademicDetails;
            if (studentAcademicDetails && studentAcademicDetails->stream[0])
            {
                for (int i = 0; i < SUBJECT_COUNT; i++)
                {
                    if (!studentAcademicDetails->results[i] || !studentAcademicDetails->results[i]->marks)
                        continue;

                    Marks *marks = studentAcademicDetails->results[i]->marks;
                    if (marks->obtainedMarks == -1)
                    {
                        incompleteMarks = 1;
                        break;
                    }
                    if (marks->grade == 'F')
                    {
                        isFail = 1;
                    }
                }

                if (!incompleteMarks && !isFail)
                {
                    passedStudents++;
                }
            }

            student = student->nextStudent;
        }

        float passPercentage = (totalStudents > 0) ? ((float)passedStudents / totalStudents) * 100.0f : 0.0f;

        printf("College: %s (%s)\n", college->collegeName, college->collegeCode);
        printf("  Total Students   : %d\n", totalStudents);
        printf("  Passed Students  : %d\n", passedStudents);
        printf("  Pass Percentage  : %.2f%%\n", passPercentage);
        printf("----------------------------------------\n");

        college = college->nextCollege;
    }
}


void getIndividualStudentResult(Student *current,sqlite3 *db)
{
    if (!current || !current->studentPersonalDetails || !current->studentPersonalDetails->dateofbirth)
    {
        printf("Invalid student data or missing personal details.\n");
        return;
    }

    char inputStudentId[20];
    int inputDay, inputMonth, inputYear;

    printf("\n--- Student Result Portal ---\n");
    printf("Enter Student ID: ");
    if (scanf("%19s", inputStudentId) != 1)
    {
        printf("Invalid input for Student ID\n");
        return;
    }

    printf("Enter Date of Birth (DD MM YYYY): ");
    if (scanf("%d %d %d", &inputDay, &inputMonth, &inputYear) != 3)
    {
        printf("Invalid input for Date of Birth\n");
        return;
    }

    DateOfBirth *dob = current->studentPersonalDetails->dateofbirth;

    if (current->studentID == NULL || strcmp(current->studentID, inputStudentId) != 0 ||
        dob->date != inputDay || dob->month != inputMonth || dob->year != inputYear)
    {
        printf("Student ID or Date of Birth does not match our records.\n");
        return;
    }


    if (!current->studentPersonalDetails->studentName || !current->studentPersonalDetails->studentFatherName)
    {
        printf("Incomplete student personal details\n");
        return;
    }

    StudentAcademicDetails *studentAcademicDetails = current->studentAcademicDetails;
    if (!studentAcademicDetails || !studentAcademicDetails->results)
    {
        printf("Academic details not found\n");
        return;
    }

    printf("\n----- Student Result -----\n");
    printf("Student ID     : %s\n", current->studentID);
    printf("Student Name   : %s\n", current->studentPersonalDetails->studentName);
    printf("Father's Name  : %s\n", current->studentPersonalDetails->studentFatherName);
    printf("Date of Birth  : %02d/%02d/%04d\n", dob->date, dob->month, dob->year);
    printf("\n--- Subject-wise Marks ---\n");

    int obtainedMarks = 0;
    int isFail = 0;
    const int fixedTotalMarks = 400;

    for (int i = 0; i < SUBJECT_COUNT; ++i)
    {
        Result *result = studentAcademicDetails->results[i];
        if (!result || !result->marks || !result->subject)
            continue;

        Subject *subject = result->subject;
        Marks *marks = result->marks;

        printf("Subject: %s (%s)\n", subject->subjectName, subject->subjectCode);

        if (marks->obtainedMarks == -1)
        {
            printf("  Marks: Not yet entered\n");
            printf("  Grade: N/A\n");
        } else
        {
            printf("  Marks: %d/%d\n", marks->obtainedMarks, marks->totalMarks);
            printf("  Grade: %c\n", marks->grade);
            obtainedMarks += marks->obtainedMarks;
            if (marks->grade == 'F')
            {
                isFail = 1;
            }
        }
        printf("---------------------------\n");
    }

    float overallPercentage = ((float)obtainedMarks / fixedTotalMarks) * 100.0f;
    char overallGrade =
        (overallPercentage >= 90) ? 'A' :
            (overallPercentage >= 75) ? 'B' :
            (overallPercentage >= 60) ? 'C' :
            (overallPercentage >= 40) ? 'D' : 'F';

    printf("\nTotal Marks     : %d\n", fixedTotalMarks);
    printf("Obtained Marks  : %d\n", obtainedMarks);
    printf("Percentage      : %.2f%%\n", overallPercentage);
    printf("Overall Grade   : %c\n", isFail ? 'F' : overallGrade);
    printf("---------------------------\n");
}


