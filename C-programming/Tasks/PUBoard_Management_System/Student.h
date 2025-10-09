#ifndef STUDENT_H
#define STUDENT_H

#include "StudentPersonalDetails.h"
#include "StudentAcademicDetails.h"

 struct StudentAcademicDetails;
 struct StudentPersonalDetails;


typedef struct Student {
    char *studentID;
    struct Student *nextStudent;
    struct StudentPersonalDetails *studentPersonalDetails;
    struct StudentAcademicDetails *studentAcademicDetails;
} Student;

void getIndividualStudentResult(Student *student, sqlite3 *db);
void studentMenuHandler(Student *current, sqlite3 *db);

#endif // STUDENT_H
