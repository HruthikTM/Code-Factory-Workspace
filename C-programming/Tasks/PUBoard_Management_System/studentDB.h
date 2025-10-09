#ifndef STUDENTDB_H
#define STUDENTDB_H

#include <sqlite3.h>
#include "Student.h"
#include "studentDB.h"


void createStudentTable(sqlite3 *db);
void insertStudent(sqlite3 *db, const char *collegeCode, Student *student);
void loadStudentsFromDB(sqlite3 *db, College *college);

#endif // STUDENTDB_H
