#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evaluatorDB.h"
#include "subjectData.h"
#include "PUBoardManager.h"

Subject globalSubjects[] = {
    {"PHY", "Physics"},
    {"CHE", "Chemistry"},
    {"MAT", "Mathematics"},
    {"BIO", "Biology"},
    {"ACC", "Accountancy"},
    {"BST", "BusinessStudies"},
    {"ECO", "Economics"},
    {"COM", "Commerce"},
    {"HIS", "History"},
    {"POL", "PoliticalScience"},
    {"SOC", "Sociology"},
    {"PSY", "Psychology"}
};

int subjectCount = sizeof(globalSubjects) / sizeof(globalSubjects[0]);



void createEvaluatorTable(sqlite3 *db)
{
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS EVALUATOR ("
                      "EVALUATOR_ID TEXT PRIMARY KEY NOT NULL UNIQUE,"
                      "PASSWORD TEXT NOT NULL,"
                      "SUBJECT_CODE TEXT NOT NULL,"
                      "STUDENT_LIMIT INTEGER NOT NULL,"
                      "STUDENT_COUNT INTEGER NOT NULL);";

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error (create table): %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("Evaluator table created successfully\n");
    }
}


void insertEvaluator(sqlite3 *db, Evaluator *newEvaluator)
{
    if (!newEvaluator || !newEvaluator->subject)
    {
        printf("Invalid evaluator data\n");
        return;
    }

    const char *sql = "INSERT INTO EVALUATOR (EVALUATOR_ID, PASSWORD, SUBJECT_CODE, STUDENT_LIMIT, STUDENT_COUNT) "
                      "VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare insert statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, newEvaluator->userId, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, newEvaluator->password, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, newEvaluator->subject->subjectCode, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, newEvaluator->studentLimit);
    sqlite3_bind_int(stmt, 5, newEvaluator->studentCount);

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        fprintf(stderr, "Insert failed: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        printf("Evaluator inserted successfully\n");
    }

    sqlite3_finalize(stmt);
}



void loadEvaluatorsFromDB(PUBoardManager *manager, sqlite3 *db)
{
    if (!manager || manager->boardCount == 0)
    {
        printf("No boards available to load evaluators into.\n");
        return;
    }

    Subject *subjects = getGlobalSubjects();
    int subjectCount = getSubjectCount();

    const char *sql = "SELECT EVALUATOR_ID, PASSWORD, SUBJECT_CODE, STUDENT_LIMIT, STUDENT_COUNT FROM EVALUATOR;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare SELECT statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const char *userId = (const char *)sqlite3_column_text(stmt, 0);
        const char *password = (const char *)sqlite3_column_text(stmt, 1);
        const char *subjectCode = (const char *)sqlite3_column_text(stmt, 2);
        int studentLimit = sqlite3_column_int(stmt, 3);
        int studentCount = sqlite3_column_int(stmt, 4);

        Evaluator *evaluator = (Evaluator *)malloc(sizeof(Evaluator));
        if (!evaluator)
        {
            fprintf(stderr, "Memory allocation failed.\n");
            break;
        }

        evaluator->userId = strdup(userId);
        evaluator->password = strdup(password);
        evaluator->studentLimit = studentLimit;
        evaluator->studentCount = studentCount;
        evaluator->results = NULL;
        for (int i = 0; i < MAX_ASSIGNED_STUDENTS; i++)
            evaluator->assignedStudentIds[i] = NULL;

        evaluator->subject = NULL;
        for (int i = 0; i < subjectCount; i++)
        {
            if (strcmp(subjects[i].subjectCode, subjectCode) == 0)
            {
                evaluator->subject = &subjects[i];
                break;
            }
        }

        if (!evaluator->subject)
        {
            printf("Warning: Subject code %s not found for evaluator %s\n", subjectCode, evaluator->userId);
        }

        PUBoard *board = manager->boards[0];
        if (board->evaluatorCount < MAX_EVALUATOR)
        {
            board->evaluators[board->evaluatorCount++] = evaluator;
        }
        else
        {
            printf("Max evaluator count reached. Evaluator %s not added.\n", evaluator->userId);
            free(evaluator->userId);
            free(evaluator->password);
            free(evaluator);
        }
    }

    sqlite3_finalize(stmt);
}
