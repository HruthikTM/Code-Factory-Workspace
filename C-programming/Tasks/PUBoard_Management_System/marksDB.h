#ifndef MARKSDB_H
#define MARKSDB_H
#include <sqlite3.h>
#include "Marks.h"
#include "College.h"

#include "StudentAcademicDetails.h"
#include "Student.h"


void createStudentMarksTable(sqlite3 *db);
// void insertStudentMarksToDB(sqlite3 *db, const char *studentId, const char *subjectCode, int totalMarks, int obtainedMarks, float percentage, char grade);
void insertStudentMarksToDB(sqlite3 *db, const char *studentId, const char *subjectCode, int totalMarks, int obtainedMarks, float percentage, char grade, const char *evaluatorId, int newStudentCount);
void loadStudentMarksFromDB(College *collegeList, sqlite3 *db);

#endif // MARKSDB_H
