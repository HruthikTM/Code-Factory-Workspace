#ifndef Result_H
#define Result_H

#include "Marks.h"
#include "Subject.h"
#include "PUBoard.h"

struct Subject;

typedef struct Result {
    struct Subject *subject;
    Marks   *marks;
} Result;


#endif // Result_H
