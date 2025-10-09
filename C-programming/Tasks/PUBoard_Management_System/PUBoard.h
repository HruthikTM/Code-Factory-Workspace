#ifndef PUBOARD_H
#define PUBOARD_H

#include "College.h"

#include "Evaluator.h"

#define MAX_EVALUATOR 12

typedef struct PUBoard {

    char *boardName;
    char *userId;
    char *password;
    struct College *collegeList;

    struct Evaluator *evaluators[MAX_EVALUATOR];
    int evaluatorCount;

} PUBoard;





#endif // PUBOARD_H
