#ifndef DISPLAYDETAILS_C
#define DISPLAYDETAILS_C

#include "Company.h"

void displayDetails();

void displayDetails(){

    printf("\nEmployee - Seat Assignment \n");
    for (int i = 0; i < company.noOfEmployees; i++) {
        printf("Employee Name: %s, Employee Id: %s, Employee Phone-Number: %ld, Employee Mail-Id: %s, Employee Role: %s, Assigned Seat: %d\n",
               company.employees[i].employeeName,
               company.employees[i].employeeId,
               company.employees[i].employeePhoneNumber,
               company.employees[i].employeeMailId,
               company.employees[i].employeeRole,

               company.employees[i].assignedSeat->seatNo);
    }

    free(company.seats);
    free(company.employees);

}

#endif // DISPLAYDETAILS_C
