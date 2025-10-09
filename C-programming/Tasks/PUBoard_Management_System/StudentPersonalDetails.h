#ifndef STUDENTPERSONALDETAILS_H
#define STUDENTPERSONALDETAILS_H

#include "PUBoard.h"
#include "DateOfBirth.h"

typedef struct StudentPersonalDetails{

    char *studentName;
    char *studentFatherName;
    char *studentMotherName;
    char *studentContactNumber;
    char *studentAddress;

    DateOfBirth *dateofbirth;

}StudentPersonalDetails;

void* enterStudentPersonalDetails();
void displayStudentPersonalDetails(StudentPersonalDetails *studentPersonalDetails);

#endif // STUDENTPERSONALDETAILS_H
