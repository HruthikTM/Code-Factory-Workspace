#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Subject.h"
#include "Result.h"
#include "PUBoard.h"
#include "College.h"

#define MAX_ASSIGNED_STUDENTS 100

struct College;
typedef struct College College;

 struct Subject;

typedef struct Evaluator {
    char *userId;
    char *password;

    char *assignedStudentIds[MAX_ASSIGNED_STUDENTS];
    int studentCount;
    int studentLimit;

    struct Subject *subject;
    Result *results;

} Evaluator;


void enterStudentMarks(Evaluator *currentEvaluator, College *collegeList, sqlite3 *db);
void evaluatorMenuHandler(Evaluator *evaluator, College *collegeList,sqlite3 *db);


#endif // EVALUATOR_H
