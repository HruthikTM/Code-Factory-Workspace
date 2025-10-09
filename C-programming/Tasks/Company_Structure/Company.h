#ifndef COMPANY_H
#define COMPANY_H

#include "Seat.h"
#include "Employee.h"

typedef struct Company {
    Employee* employees;
    Seat* seats;
    int noOfEmployees;
    int noOfSeats;
} Company;

void enterSeatDetails();
void enterEmployeeDetails();
void assignSeats();
void displaySeatDetails();
void displayEmployeeDetails();
void displaySeatAssignments();

#endif // COMPANY_H
