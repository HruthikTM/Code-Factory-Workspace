#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collegeDB.h"

void createCollegeTable(sqlite3 *db)
{
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS COLLEGE ("
                      "COLLEGE_CODE TEXT PRIMARY KEY NOT NULL UNIQUE,"
                      "COLLEGE_NAME TEXT NOT NULL,"
                      "STUDENT_COUNT INTEGER);";

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error (create table): %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("College table created successfully\n");
    }
}

void insertCollege(sqlite3 *db, College *newCollege)
{
    if (!newCollege)
    {
        printf("Invalid college data\n");
        return;
    }

    const char *sql = "INSERT INTO COLLEGE (COLLEGE_CODE, COLLEGE_NAME, STUDENT_COUNT) VALUES (?, ?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, newCollege->collegeCode, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, newCollege->collegeName, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, newCollege->studentCount);

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        fprintf(stderr, "Insert failed: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        printf("College inserted successfully\n");
    }

    sqlite3_finalize(stmt);
}


void loadCollegesFromDB(sqlite3 *db, PUBoardManager *manager)
{
    const char *sql = "SELECT COLLEGE_CODE, COLLEGE_NAME, STUDENT_COUNT FROM COLLEGE;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare SELECT statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char *code = sqlite3_column_text(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        int studentCount = sqlite3_column_int(stmt, 2);

        College *college = malloc(sizeof(College));
        if (!college)
        {
            fprintf(stderr, "Memory allocation failed\n");
            break;
        }

        college->collegeCode = strdup((const char *)code);
        college->collegeName = strdup((const char *)name);
        college->studentCount = studentCount;
        college->studentList = NULL;
        college->nextCollege = NULL;

        if (manager->boardCount > 0)
        {
            College *head = manager->boards[0]->collegeList;
            if (!head)
            {
                manager->boards[0]->collegeList = college;
            }
            else
            {
                while (head->nextCollege != NULL)
                {
                    head = head->nextCollege;
                }
                head->nextCollege = college;
            }
        }
    }

    sqlite3_finalize(stmt);
}
