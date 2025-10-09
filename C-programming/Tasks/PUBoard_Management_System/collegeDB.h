#ifndef COLLEGEDB_H
#define COLLEGEDB_H

#include <sqlite3.h>
#include "PUBoardManager.h"

void createCollegeTable(sqlite3 *db);
void insertCollege(sqlite3 *db, College *newCollege);
void loadCollegesFromDB(sqlite3 *db, PUBoardManager *manager);


#endif // COLLEGEDB_H
