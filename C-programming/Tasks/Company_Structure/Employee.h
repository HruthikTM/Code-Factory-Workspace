#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <stdio.h>

#include "Seat.h"

typedef struct Employee{

    long employeePhoneNumber;
    char employeeName[20];
    char employeeId[20];
    char employeeMailId[20];
    char employeeRole[20];

    struct Seat *assignedSeat;

}Employee;



#endif // EMPLOYEE_H
