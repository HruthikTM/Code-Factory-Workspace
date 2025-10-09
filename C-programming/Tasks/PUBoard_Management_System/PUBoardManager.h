#ifndef PUBOARDMANAGER_H
#define PUBOARDMANAGER_H

#include <sqlite3.h>

#include "PUBoard.h"
#define MAX_BOARDS 10

struct PUBoard;

typedef struct PUBoardManager {
    int boardCount;
    struct PUBoard *boards[MAX_BOARDS];
    struct PUBoard *activeBoard;
} PUBoardManager;

//void menu(PUBoardManager *manager, sqlite3 *db);
void menu();
void displayBoards(PUBoardManager *manager);
void addBoard(PUBoardManager *manager, sqlite3 *db);
void boardLogin(PUBoardManager *manager, sqlite3 *db);
void collegeLogin(PUBoardManager *manager, sqlite3 *db);
void studentLogin(PUBoardManager *manager, sqlite3 *db);
void addEvaluator(PUBoardManager *manager, sqlite3 *db);
void evaluatorLogin(PUBoardManager *manager, sqlite3 *db);
void displayCollegeWisePassPercentage(PUBoardManager *manager);
void boardMenuHandler(PUBoardManager *manager,sqlite3 *db);


#endif // PUBOARDMANAGER_H
