#ifndef BOARDDB_H
#define BOARDDB_H

#include <sqlite3.h>
#include "PUBoardManager.h"

void createPUBoardTable(sqlite3 *db);
void insertPUBoard(sqlite3 *db, PUBoard *board);
void loadBoardsFromDB(sqlite3 *db, PUBoardManager *manager);


#endif // BOARDDB_H
