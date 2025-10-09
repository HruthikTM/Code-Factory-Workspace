#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#include "Student.h"

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for(int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void createStudentTable(sqlite3 *db)
{
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS STUDENT("
                      "ID INT PRIMARY KEY NOT NULL,"
                      "NAME TEXT NOT NULL,"
                      "PHONE_NO INT NOT NULL);";

    int rc = sqlite3_exec(db,sql,0,0,&errMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr,"SQL error (create table): %s\n",errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("Student table created successfully\n");
    }
}

void insertStudent(sqlite3 *db,Student s)
{
    char sql[256];
    snprintf(sql,sizeof(sql),
             "INSERT INTO STUDENT (ID, NAME, PHONE_NO) VALUES (%d, '%s', %d);",
             s.studentId, s.studentName, s.studentPhoneNo);


    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "Insert error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else
    {
        printf("Student inserted successfully\n");
    }
}

void readStudents(sqlite3 *db)
{
    char *errMsg = 0;
    const char *sql = "SELECT * FROM STUDENT;";
    int rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "Select error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("Student records fetched successfully\n");
    }
}

void updateStudentPhone(sqlite3 *db,int studentId,int newPhoneNo)
{
    char sql[256];
    snprintf(sql,sizeof(sql),
             "UPDATE STUDENT SET PHONE_NO = %d WHERE ID = %d;",
             newPhoneNo, studentId);


    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "Update error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("Student phone updated successfully\n");
    }
}

void deleteStudent(sqlite3 *db, int studentId)
{
    char sql[128];
    snprintf(sql, sizeof(sql),
             "DELETE FROM STUDENT WHERE ID = %d;", studentId);

    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "Delete error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("Student deleted successfully\n");
    }
}

