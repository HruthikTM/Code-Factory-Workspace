#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "subjectData.h"
#include <marksDB.h>

 #include "StudentAcademicDetails.h"

void createStudentMarksTable(sqlite3 *db)
{
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS StudentMarks ("
                      "STUDENT_ID TEXT NOT NULL,"
                      "SUBJECT_CODE TEXT NOT NULL,"
                      "TOTAL_MARKS INTEGER NOT NULL,"
                      "OBTAINED_MARKS INTEGER NOT NULL,"
                      "PERCENTAGE REAL NOT NULL,"
                      "GRADE TEXT NOT NULL,"
                      "PRIMARY KEY (STUDENT_ID, SUBJECT_CODE),"
                      "FOREIGN KEY (STUDENT_ID) REFERENCES STUDENT(STUDENT_ID),"
                      "FOREIGN KEY (SUBJECT_CODE) REFERENCES SUBJECT(SUBJECT_CODE));";

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error (create StudentMarks table): %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("StudentMarks table created successfully\n");
    }
}

// void insertStudentMarksToDB(sqlite3 *db, const char *studentId, const char *subjectCode, int totalMarks, int obtainedMarks, float percentage, char grade)
// {
//     if (!db || !studentId || !subjectCode)
//     {
//         printf("Invalid database or data for insertion.\n");
//         return;
//     }

//     const char *sql = "INSERT INTO StudentMarks (STUDENT_ID, SUBJECT_CODE, TOTAL_MARKS, OBTAINED_MARKS, PERCENTAGE, GRADE) "
//                       "VALUES (?, ?, ?, ?, ?, ?);";


//     sqlite3_stmt *stmt;
//     int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

//     if (rc != SQLITE_OK)
//     {
//         printf("Failed to prepare insert statement: %s\n", sqlite3_errmsg(db));
//         return;
//     }

//     sqlite3_bind_text(stmt, 1, studentId, -1, SQLITE_TRANSIENT);
//     sqlite3_bind_text(stmt, 2, subjectCode, -1, SQLITE_TRANSIENT);
//     sqlite3_bind_int(stmt, 3, totalMarks);
//     sqlite3_bind_int(stmt, 4, obtainedMarks);
//     sqlite3_bind_double(stmt, 5, percentage);
//     sqlite3_bind_text(stmt, 6, &grade, 1, SQLITE_STATIC);

//     rc = sqlite3_step(stmt);
//     if (rc != SQLITE_DONE)
//     {
//         printf("Failed to insert marks: %s\n", sqlite3_errmsg(db));
//     }
//     else
//     {
//         printf("Student marks inserted successfully into database.\n");
//     }

//     sqlite3_finalize(stmt);
// }


void insertStudentMarksToDB(sqlite3 *db, const char *studentId, const char *subjectCode, int totalMarks, int obtainedMarks, float percentage, char grade, const char *evaluatorId, int newStudentCount)
{
    if (!db || !studentId || !subjectCode)
    {
        printf("Invalid database or data for insertion.\n");
        return;
    }

    const char *sql = "INSERT INTO StudentMarks (STUDENT_ID, SUBJECT_CODE, TOTAL_MARKS, OBTAINED_MARKS, PERCENTAGE, GRADE) "
                      "VALUES (?, ?, ?, ?, ?, ?);";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK)
    {
        printf("Failed to prepare insert statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, studentId, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, subjectCode, -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, totalMarks);
    sqlite3_bind_int(stmt, 4, obtainedMarks);
    sqlite3_bind_double(stmt, 5, percentage);
    sqlite3_bind_text(stmt, 6, &grade, 1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        printf("Failed to insert marks: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        printf("Student marks inserted successfully into database.\n");


        if (evaluatorId) {
            const char *updateSql = "UPDATE EVALUATOR SET STUDENT_COUNT = ? WHERE EVALUATOR_ID = ?;";
            sqlite3_stmt *updateStmt;
            if (sqlite3_prepare_v2(db, updateSql, -1, &updateStmt, NULL) == SQLITE_OK) {
                sqlite3_bind_int(updateStmt, 1, newStudentCount);
                sqlite3_bind_text(updateStmt, 2, evaluatorId, -1, SQLITE_TRANSIENT);
                if (sqlite3_step(updateStmt) != SQLITE_DONE) {
                    printf("Failed to update evaluator student count: %s\n", sqlite3_errmsg(db));
                }
                sqlite3_finalize(updateStmt);
            } else {
                printf("Failed to prepare update statement: %s\n", sqlite3_errmsg(db));
            }
        }
    }

    sqlite3_finalize(stmt);
}


void loadStudentMarksFromDB(College *collegeList, sqlite3 *db)
{
    if (!db || !collegeList)
        return;

    const char *sql = "SELECT STUDENT_ID, SUBJECT_CODE, TOTAL_MARKS, OBTAINED_MARKS, PERCENTAGE, GRADE FROM StudentMarks;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
    {
        printf("Failed to prepare statement to load marks from DB\n");
        return;
    }

    Subject *globalSubjects = getGlobalSubjects();
    int subjectCount = getSubjectCount();

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const char *studentId = (const char *)sqlite3_column_text(stmt, 0);
        const char *subjectCode = (const char *)sqlite3_column_text(stmt, 1);
        int obtainedMarks = sqlite3_column_int(stmt, 3);
        int totalMarks = sqlite3_column_int(stmt, 2);
        float percentage = (float)sqlite3_column_double(stmt, 4);
        char grade = *(const char *)sqlite3_column_text(stmt, 5);

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

        if (targetStudent && targetStudent->studentAcademicDetails)
        {
            StudentAcademicDetails *studentAcademicDetails = targetStudent->studentAcademicDetails;

            for (int i = 0; i < subjectCount; ++i)
            {
                Result *res = studentAcademicDetails->results[i];

                if (!res)
                {
                    res = (Result *)malloc(sizeof(Result));
                    res->subject = NULL;
                    res->marks = (Marks *)malloc(sizeof(Marks));
                    studentAcademicDetails->results[i] = res;
                }

                if (!res->subject)
                {
                    for (int s = 0; s < subjectCount; ++s)
                    {
                        if (strcmp(globalSubjects[s].subjectCode, subjectCode) == 0)
                        {
                            res->subject = &globalSubjects[s];
                            break;
                        }
                    }
                }

                if (res->subject && strcmp(res->subject->subjectCode, subjectCode) == 0)
                {
                    res->marks->obtainedMarks = obtainedMarks;
                    res->marks->totalMarks = totalMarks;
                    res->marks->percentage = percentage;
                    res->marks->grade = grade;
                    break;
                }
            }
        }
    }

    sqlite3_finalize(stmt);
}
