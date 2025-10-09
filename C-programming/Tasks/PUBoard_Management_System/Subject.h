#ifndef SUBJECT_H
#define SUBJECT_H
#include "PUBoard.h"

typedef struct Subject{
    char *subjectCode;
    char *subjectName;
}Subject;

Subject* getGlobalSubjects();
int getSubjectCount();



#endif // SUBJECT_H
