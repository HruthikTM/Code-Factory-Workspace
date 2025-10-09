#ifndef EVALUATORDB_H
#define EVALUATORDB_H


#include <sqlite3.h>
#include "PUBoardManager.h"

void createEvaluatorTable(sqlite3 *db);
void insertEvaluator(sqlite3 *db, Evaluator *evaluator);
void loadEvaluatorsFromDB(PUBoardManager *manager, sqlite3 *db);


#endif // EVALUATORDB_H
