#ifndef COLLEGE_H
#define COLLEGE_H

#include <sqlite3.h>
#include "Student.h"

struct PUBoardManager;
struct PUBoard;
struct Student;

typedef struct College {
    int studentCount;
    char *collegeCode;
    char *collegeName;
    struct College *nextCollege;
    struct Student *studentList;
} College;

void addCollegeDetails(struct PUBoardManager *manager, sqlite3 *db);
void displayCollegeDetails(struct PUBoardManager *manager);
void addStudentDetails(College *current, sqlite3 *db);
void displayStudentDetails(College *current);
void collegeMenuHandler(College *current,sqlite3 *db);


#endif // COLLEGE_H
