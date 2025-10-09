#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PUBoard.h"

void* enterStudentPersonalDetails()
{
    printf("\n--- Student Personal Details ---\n");

    StudentPersonalDetails *studentPersonalDetails = (StudentPersonalDetails *)malloc(sizeof(StudentPersonalDetails));
    if (!studentPersonalDetails)
    {
        printf("Memory allocation failed for StudentPersonalDetails\n");
        return NULL;
    }

    studentPersonalDetails->dateofbirth = (DateOfBirth *)malloc(sizeof(DateOfBirth));
    if (!studentPersonalDetails->dateofbirth)
    {
        printf("Memory allocation failed for DateOfBirth\n");
        free(studentPersonalDetails);
        return NULL;
    }

    char tempStudentName[500],tempStudentFName[500],tempStudentMName[500],tempStudentContactNo[500],tempStudentAddress[500];

    printf("Enter Student Name: ");
    getchar();
    fgets(tempStudentName, sizeof(tempStudentName),stdin);
    tempStudentName[strcspn(tempStudentName, "\n")] = '\0';
    studentPersonalDetails->studentName = (char*) malloc(strlen(tempStudentName) + 1);
    strcpy(studentPersonalDetails->studentName,tempStudentName);

    printf("Enter Student Father Name: ");
    fgets(tempStudentFName, sizeof(tempStudentFName),stdin);
    tempStudentFName[strcspn(tempStudentFName, "\n")] = '\0';
    studentPersonalDetails->studentFatherName = (char*) malloc(strlen(tempStudentFName) + 1);
    strcpy(studentPersonalDetails->studentFatherName,tempStudentFName);

    printf("Enter Student Mother Name: ");
    fgets(tempStudentMName, sizeof(tempStudentMName),stdin);
    tempStudentMName[strcspn(tempStudentMName, "\n")] = '\0';
    studentPersonalDetails->studentMotherName = (char*) malloc(strlen(tempStudentMName) + 1);
    strcpy(studentPersonalDetails->studentMotherName,tempStudentMName);

    printf("Enter Student Contact Number: ");
    fgets(tempStudentContactNo, sizeof(tempStudentContactNo),stdin);
    tempStudentContactNo[strcspn(tempStudentContactNo, "\n")] = '\0';
    studentPersonalDetails->studentContactNumber = (char*) malloc(strlen(tempStudentContactNo) + 1);
    strcpy(studentPersonalDetails->studentContactNumber,tempStudentContactNo);

    printf("Enter Student Address: ");
    fgets(tempStudentAddress, sizeof(tempStudentAddress),stdin);
    tempStudentAddress[strcspn(tempStudentAddress, "\n")] = '\0';
    studentPersonalDetails->studentAddress = (char*) malloc(strlen(tempStudentAddress) + 1);
    strcpy(studentPersonalDetails->studentAddress,tempStudentAddress);

    printf("Enter Date of Birth (DD MM YYYY): ");
    scanf("%d %d %d", &studentPersonalDetails->dateofbirth->date, &studentPersonalDetails->dateofbirth->month, &studentPersonalDetails->dateofbirth->year);

    return studentPersonalDetails;
}


void* enterStudentAcademicDetails()

{
    printf("\n--- Student Academic Details ---\n");

    StudentAcademicDetails *studentacademicdetails = (StudentAcademicDetails *)malloc(sizeof(StudentAcademicDetails));
    if (!studentacademicdetails)
    {
        printf("Memory allocation failed for StudentAcademicDetails\n");
        return NULL;
    }

    const char *streamNames[] = {"Science", "Commerce", "Arts"};

    const char *scienceSubjects[] = {"Physics", "Chemistry", "Mathematics", "Biology"};
    const char *scienceCodes[] = {"PHY", "CHE", "MAT", "BIO"};

    const char *commerceSubjects[] = {"Accountancy", "BusinessStudies", "Economics", "Commerce"};
    const char *commerceCodes[] = {"ACC", "BST", "ECO", "COM"};

    const char *artsSubjects[] = {"History", "PoliticalScience", "Sociology", "Psychology"};
    const char *artsCodes[] = {"HIS", "POL", "SOC", "PSY"};

    printf("Select Stream:\n1. Science\n2. Commerce\n3. Arts\n");
    int streamChoice;

    printf("Enter your Choice: ");
    scanf("%d", &streamChoice);

    if (streamChoice < 1 || streamChoice > 3)
    {
        printf("Invalid stream choice\n");
        free(studentacademicdetails);
        return NULL;
    }

    Stream *selectedStream = (Stream *)malloc(sizeof(Stream));
    if (!selectedStream)
    {
        printf("Memory allocation failed for Stream\n");
        free(studentacademicdetails);
        return NULL;
    }

    selectedStream->streamName = (char *)malloc(strlen(streamNames[streamChoice - 1]) + 1);

    if (!selectedStream->streamName)
    {
        printf("Memory allocation failed for streamName\n");
        free(selectedStream);
        free(studentacademicdetails);
        return NULL;
    }

    strcpy(selectedStream->streamName, streamNames[streamChoice - 1]);

    for (int i = 0; i < SUBJECT_COUNT; ++i)
    {
        selectedStream->subjects[i] = (Subject *)malloc(sizeof(Subject));
        if (!selectedStream->subjects[i])
        {
            printf("Memory allocation failed for Subject %d\n", i);

            for (int j = 0; j < i; ++j)
            {
                free(selectedStream->subjects[j]->subjectName);
                free(selectedStream->subjects[j]->subjectCode);
                free(selectedStream->subjects[j]);
            }

            free(selectedStream->streamName);
            free(selectedStream);
            free(studentacademicdetails);
            return NULL;
        }

        Subject *subj = selectedStream->subjects[i];
        const char *subName = NULL;
        const char *subCode = NULL;

        switch (streamChoice)
        {
        case 1:
            subName = scienceSubjects[i];
            subCode = scienceCodes[i];
            break;
        case 2:
            subName = commerceSubjects[i];
            subCode = commerceCodes[i];
            break;
        case 3:
            subName = artsSubjects[i];
            subCode = artsCodes[i];
            break;
        }

        subj->subjectName = (char *)malloc(strlen(subName) + 1);
        subj->subjectCode = (char *)malloc(strlen(subCode) + 1);

        if (!subj->subjectName || !subj->subjectCode)
        {
            printf("Memory allocation failed for subject strings\n");
            for (int j = 0; j <= i; ++j)
            {
                if (selectedStream->subjects[j])
                {
                    free(selectedStream->subjects[j]->subjectName);
                    free(selectedStream->subjects[j]->subjectCode);
                    free(selectedStream->subjects[j]);
                }
            }
            free(selectedStream->streamName);
            free(selectedStream);
            free(studentacademicdetails);
            return NULL;
        }

        strcpy(subj->subjectName, subName);
        strcpy(subj->subjectCode, subCode);


        studentacademicdetails->results[i] = (Result *)malloc(sizeof(Result));
        if (!studentacademicdetails->results[i])
        {
            printf("Memory allocation failed for Result %d\n", i);
            return NULL;
        }

        studentacademicdetails->results[i]->subject = subj;
        studentacademicdetails->results[i]->marks = (Marks *)malloc(sizeof(Marks));
        if (!studentacademicdetails->results[i]->marks)
        {
            printf("Memory allocation failed for Marks %d\n", i);
            return NULL;
        }

        studentacademicdetails->results[i]->marks->totalMarks = 100;
        studentacademicdetails->results[i]->marks->obtainedMarks = -1;
        studentacademicdetails->results[i]->marks->percentage = 0.0f;
        studentacademicdetails->results[i]->marks->grade = '-';
    }

    for (int i = 0; i < 3; ++i)
    {
        studentacademicdetails->stream[i] = NULL;
    }
    studentacademicdetails->stream[0] = selectedStream;

    printf("\nSubjects in %s Stream:\n", selectedStream->streamName);
    for (int i = 0; i < SUBJECT_COUNT; ++i)
        printf("  - %s (%s)\n", selectedStream->subjects[i]->subjectName, selectedStream->subjects[i]->subjectCode);

    return studentacademicdetails;
}


void displayStudentPersonalDetails(StudentPersonalDetails *studentpersonaldetails)
{
    if (!studentpersonaldetails || !studentpersonaldetails->dateofbirth)
    {
        printf("No personal details available\n");
        return;
    }

    printf("\n--- Personal Details ---\n");
    printf("Name          : %s\n", studentpersonaldetails->studentName);
    printf("Father's Name : %s\n", studentpersonaldetails->studentFatherName);
    printf("Mother's Name : %s\n", studentpersonaldetails->studentMotherName);
    printf("Contact Number: %s\n", studentpersonaldetails->studentContactNumber);
    printf("Address       : %s\n", studentpersonaldetails->studentAddress);
    printf("Date of Birth : %d %d %d\n", studentpersonaldetails->dateofbirth->date, studentpersonaldetails->dateofbirth->month, studentpersonaldetails->dateofbirth->year);
}

void displayStudentAcademicDetails(StudentAcademicDetails *studentacademicdetails)
{
    if (!studentacademicdetails || !studentacademicdetails->stream[0])
    {
        printf("No academic details available\n");
        return;
    }

    printf("\n--- Academic Details ---\n");
    printf("Stream: %s\n", studentacademicdetails->stream[0]->streamName);

    int obtainedMarks = 0;
    int isFail = 0;
    int subjectsWithMarks = 0;
    int totalMaxMarks = SUBJECT_COUNT * 100;

    for (int i = 0; i < SUBJECT_COUNT; ++i)
    {
        Result *result = studentacademicdetails->results[i];
        Subject *subject = studentacademicdetails->stream[0]->subjects[i];

        printf("Subject: %s (%s)\n", subject->subjectName, subject->subjectCode);

        if (!result || !result->marks || result->marks->obtainedMarks == -1)
        {
            printf("  Marks: Not yet entered\n");
            printf("  Grade: N/A\n");
        }
        else
        {
            Marks *marks = result->marks;
            printf("  Marks: %d/%d\n", marks->obtainedMarks, marks->totalMarks);
            printf("  Grade: %c\n", marks->grade);
            obtainedMarks += marks->obtainedMarks;
            subjectsWithMarks++;
            if (marks->grade == 'F')
                isFail = 1;
        }
        printf("---------------------------\n");
    }

    float overallPercentage = (totalMaxMarks > 0) ? ((float)obtainedMarks / totalMaxMarks) * 100.0f : 0.0f;
    char overallGrade =
        (overallPercentage >= 90) ? 'A' :
            (overallPercentage >= 75) ? 'B' :
            (overallPercentage >= 60) ? 'C' :
            (overallPercentage >= 40) ? 'D' : 'F';

    printf("\n>>> Total Marks         : %d\n", totalMaxMarks);
    printf(">>> Total Obtained Marks: %d\n", obtainedMarks);
    printf(">>> Overall Percentage  : %.2f%%\n", overallPercentage);
    printf(">>> Final Result        : %s\n", (subjectsWithMarks == SUBJECT_COUNT) ? (isFail ? "Fail" : "Pass") : "Pending");
    printf(">>> Overall Grade       : %c\n", (subjectsWithMarks == SUBJECT_COUNT) ? (isFail ? 'F' : overallGrade) : '-');
}



void freeStudentPersonalDetails(StudentPersonalDetails *details) {
    if (!details) return;

    free(details->studentName);
    free(details->studentFatherName);
    free(details->studentMotherName);
    free(details->studentContactNumber);
    free(details->studentAddress);

    if (details->dateofbirth)
        free(details->dateofbirth);

    free(details);
}


void freeStudentAcademicDetails(StudentAcademicDetails *academicDetails)
{
    if (!academicDetails) return;

    for (int i = 0; i < SUBJECT_COUNT; ++i)
    {
        if (academicDetails->results[i])
        {
            if (academicDetails->results[i]->marks)
                free(academicDetails->results[i]->marks);

            if (academicDetails->results[i]->subject &&
                academicDetails->results[i]->subject != NULL &&
                academicDetails->results[i]->subject != getGlobalSubjects())
            {
                free(academicDetails->results[i]->subject->subjectName);
                free(academicDetails->results[i]->subject->subjectCode);
                free(academicDetails->results[i]->subject);
            }

            free(academicDetails->results[i]);
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        if (academicDetails->stream[i])
        {
            Stream *stream = academicDetails->stream[i];
            for (int j = 0; j < SUBJECT_COUNT; ++j)
            {
                if (stream->subjects[j])
                {

                    if (stream->subjects[j] != getGlobalSubjects())
                        free(stream->subjects[j]);
                }
            }
            free(stream->streamName);
            free(stream);
        }
    }

    free(academicDetails);
}
