#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentDB.h"
#include "Subject.h"


void createStudentTable(sqlite3 *db)
{
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS STUDENT ("
                      "STUDENT_ID TEXT PRIMARY KEY NOT NULL,"
                      "COLLEGE_CODE TEXT NOT NULL,"
                      "NAME TEXT,"
                      "FATHER_NAME TEXT,"
                      "MOTHER_NAME TEXT,"
                      "CONTACT_NUMBER TEXT,"
                      "ADDRESS TEXT,"
                      "DOB_DAY INTEGER,"
                      "DOB_MONTH INTEGER,"
                      "DOB_YEAR INTEGER,"
                      "STREAM TEXT,"
                      "FOREIGN KEY (COLLEGE_CODE) REFERENCES COLLEGE(COLLEGE_CODE));";

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error (create student table): %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("Student table created successfully\n");
    }
}

void insertStudent(sqlite3 *db, const char *collegeCode, Student *student)
{
    if (!student || !student->studentPersonalDetails || !student->studentAcademicDetails)
    {
        printf("Invalid student data\n");
        return;
    }

    const char *sql = "INSERT INTO STUDENT (STUDENT_ID, COLLEGE_CODE, NAME, FATHER_NAME, MOTHER_NAME, CONTACT_NUMBER, ADDRESS, DOB_DAY, DOB_MONTH, DOB_YEAR, STREAM) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";

    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare insert student statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    StudentPersonalDetails *pd = student->studentPersonalDetails;
    StudentAcademicDetails *ad = student->studentAcademicDetails;
    DateOfBirth *dob = pd->dateofbirth;

    sqlite3_bind_text(stmt, 1, student->studentID, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, collegeCode, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, pd->studentName, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, pd->studentFatherName, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, pd->studentMotherName, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, pd->studentContactNumber, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, pd->studentAddress, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 8, dob->date);
    sqlite3_bind_int(stmt, 9, dob->month);
    sqlite3_bind_int(stmt, 10, dob->year);

    if (ad->stream[0] && ad->stream[0]->streamName) {
        sqlite3_bind_text(stmt, 11, ad->stream[0]->streamName, -1, SQLITE_STATIC);
    }
    else
    {
        fprintf(stderr, "Stream information missing. Cannot insert student.\n");
        sqlite3_finalize(stmt);
        return;
    }

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        fprintf(stderr, "Insert student failed: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        printf("Student inserted successfully\n");

        const char *updateSql = "UPDATE COLLEGE SET STUDENT_COUNT = STUDENT_COUNT + 1 WHERE COLLEGE_CODE = ?;";
        sqlite3_stmt *updateStmt;

        if (sqlite3_prepare_v2(db, updateSql, -1, &updateStmt, NULL) == SQLITE_OK)
        {
            sqlite3_bind_text(updateStmt, 1, collegeCode, -1, SQLITE_STATIC);

            if (sqlite3_step(updateStmt) != SQLITE_DONE)
            {
                fprintf(stderr, "Failed to update student count: %s\n", sqlite3_errmsg(db));
            }
            else
            {
                printf("Student count updated successfully\n");
            }

            sqlite3_finalize(updateStmt);
        }
        else
        {
            fprintf(stderr, "Failed to prepare update statement: %s\n", sqlite3_errmsg(db));
        }
    }

    sqlite3_finalize(stmt);

}


void loadStudentsFromDB(sqlite3 *db, College *college)
{
    if (!college)
    {
        printf("Invalid college pointer\n");
        return;
    }

    const char *sql = "SELECT STUDENT_ID, NAME, FATHER_NAME, MOTHER_NAME, CONTACT_NUMBER, ADDRESS, DOB_DAY, DOB_MONTH, DOB_YEAR, STREAM "
                      "FROM STUDENT WHERE COLLEGE_CODE = ?;";

    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare SELECT statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, college->collegeCode, -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        Student *student = malloc(sizeof(Student));
        StudentPersonalDetails *pd = malloc(sizeof(StudentPersonalDetails));
        DateOfBirth *dob = malloc(sizeof(DateOfBirth));

        if (!student || !pd || !dob)
        {
            printf("Memory allocation failed while loading students\n");
            free(student);
            free(pd);
            free(dob);
            break;
        }

        student->studentID = strdup((const char *)sqlite3_column_text(stmt, 0));
        pd->studentName = strdup((const char *)sqlite3_column_text(stmt, 1));
        pd->studentFatherName = strdup((const char *)sqlite3_column_text(stmt, 2));
        pd->studentMotherName = strdup((const char *)sqlite3_column_text(stmt, 3));
        pd->studentContactNumber = strdup((const char *)sqlite3_column_text(stmt, 4));
        pd->studentAddress = strdup((const char *)sqlite3_column_text(stmt, 5));

        dob->date = sqlite3_column_int(stmt, 6);
        dob->month = sqlite3_column_int(stmt, 7);
        dob->year = sqlite3_column_int(stmt, 8);

        pd->dateofbirth = dob;
        student->studentPersonalDetails = pd;

        StudentAcademicDetails *studentAcademicDetails = malloc(sizeof(StudentAcademicDetails));
        Stream *stream = malloc(sizeof(Stream));

        if (!studentAcademicDetails || !stream)
        {
            printf("Memory allocation failed for academic details\n");
            free(student);
            free(pd);
            free(dob);
            free(studentAcademicDetails);
            free(stream);
            break;
        }

        stream->streamName = strdup((const char *)sqlite3_column_text(stmt, 9));

        for (int i = 0; i < SUBJECT_COUNT; ++i)
        {
            studentAcademicDetails->results[i] = NULL;
        }
        for (int i = 0; i < 3; ++i)
        {
            studentAcademicDetails->stream[i] = NULL;
        }

        studentAcademicDetails->stream[0] = stream;
        student->studentAcademicDetails = studentAcademicDetails;

        student->nextStudent = NULL;

        if (!college->studentList)
            college->studentList = student;
        else
        {
            Student *temp = college->studentList;
            while (temp->nextStudent)
                temp = temp->nextStudent;
            temp->nextStudent = student;
        }


    }

    int count = 0;
    Student *s = college->studentList;
    while (s) {
        count++;
        s = s->nextStudent;
    }
    college->studentCount = count;

    sqlite3_finalize(stmt);
}
