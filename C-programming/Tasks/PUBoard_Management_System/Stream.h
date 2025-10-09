#ifndef STREAM_H
#define STREAM_H


#define SUBJECT_COUNT 4
#include "PUBoard.h"


struct Subject;

typedef struct {
    char *streamName;
    struct Subject *subjects[SUBJECT_COUNT];
} Stream;


#endif // STREAM_H
