#ifndef STUDENTACADEMICDETAILS_H
#define STUDENTACADEMICDETAILS_H

#include "PUBoard.h"
#include "Result.h"
#include "Stream.h"
#define SUBJECT_COUNT 4

typedef struct {
    Result *results[SUBJECT_COUNT];
    Stream *stream[3];
} StudentAcademicDetails;

void* enterStudentAcademicDetails();
void displayStudentAcademicDetails(StudentAcademicDetails *studentAcademicDetails);

#endif // STUDENTACADEMICDETAILS_H
