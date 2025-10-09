#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boardDB.h"

void createPUBoardTable(sqlite3 *db)
{
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS PUBOARD ("
                      "BOARD_ID TEXT PRIMARY KEY NOT NULL UNIQUE,"
                      "BOARD_NAME TEXT NOT NULL,"
                      "PASSWORD TEXT NOT NULL);";

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error (create table): %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("PUBoard table created successfully\n");
    }
}

void insertPUBoard(sqlite3 *db, PUBoard *board)
{
    if(!board)
    {
        printf("Invalid board data\n");
        return;
    }

    const char *sql = "INSERT INTO PUBOARD (BOARD_NAME, BOARD_ID, PASSWORD) VALUES (?, ?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare statement: %s\n",sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, board->boardName, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, board->userId, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, board->password, -1, SQLITE_STATIC);

    if(sqlite3_step(stmt) != SQLITE_DONE)
    {
        fprintf(stderr, "Insert failed: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        printf("Board inserted successfully\n");
    }
    sqlite3_finalize(stmt);
}

void loadBoardsFromDB(sqlite3 *db, PUBoardManager *manager)
{
    const char *sql = "SELECT BOARD_NAME, BOARD_ID, PASSWORD FROM PUBOARD;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare SELECT statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW && manager->boardCount < MAX_BOARDS)
    {
        PUBoard *board = malloc(sizeof(PUBoard));
        if (!board)
        {
            fprintf(stderr, "Memory allocation failed\n");
            break;
        }

        const unsigned char *name = sqlite3_column_text(stmt, 0);
        const unsigned char *userId = sqlite3_column_text(stmt, 1);
        const unsigned char *password = sqlite3_column_text(stmt, 2);

        board->boardName = strdup((const char *)name);
        board->userId = strdup((const char *)userId);
        board->password = strdup((const char *)password);
        board->collegeList = NULL;
        board->evaluatorCount = 0;

        manager->boards[manager->boardCount++] = board;
    }
}

