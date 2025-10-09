#ifndef COMPANYMANAGEMENT_C
#define COMPANYMANAGEMENT_C

#include <stdio.h>
#include <stdlib.h>

#include "Company.h"

Company company;

void enterSeatDetails() {
    printf("Enter No. of Seats: ");
    scanf("%d", &company.noOfSeats);

    company.seats = (Seat *)malloc(company.noOfSeats * sizeof(Seat));

    printf("\nEnter Seat Numbers\n");
    for (int i = 0; i < company.noOfSeats; i++) {
        int seatNo;
        int isDuplicate;

        do {
            isDuplicate = 0;
            printf("Enter seat number for Seat %d: ", i + 1);
            scanf("%d", &seatNo);

            for (int j = 0; j < i; j++) {
                if (company.seats[j].seatNo == seatNo) {
                    printf("Seat number already exists! Enter a unique number.\n");
                    isDuplicate = 1;
                    break;
                }
            }
        } while (isDuplicate);

        company.seats[i].seatNo = seatNo;
    }
}

void enterEmployeeDetails() {
    printf("Enter No. of Employees: ");
    scanf("%d", &company.noOfEmployees);

    company.employees = (Employee *)malloc(company.noOfEmployees * sizeof(Employee));

    for (int i = 0; i < company.noOfEmployees; i++) {
        printf("\nEnter details for Employee %d\n", i + 1);

        printf("Employee Name: ");
        scanf(" %s", company.employees[i].employeeName);

        printf("Employee Id: ");
        scanf(" %s", company.employees[i].employeeId);

        printf("Employee Phone Number: ");
        scanf("%ld", &company.employees[i].employeePhoneNumber);

        printf("Employee Mail-Id: ");
        scanf(" %s", company.employees[i].employeeMailId);

        printf("Employee Role: ");
        scanf(" %s", company.employees[i].employeeRole);

        company.employees[i].assignedSeat = NULL;
    }
}

void assignSeats() {
    for (int i = 0; i < company.noOfEmployees; i++) {
        int desiredSeatNo;
        Seat *assigned = NULL;

        while (assigned == NULL) {
            printf("\nAssigning seat for Employee: %s\n", company.employees[i].employeeName);
            printf("Enter desired Seat Number: ");
            scanf("%d", &desiredSeatNo);

            for (int j = 0; j < company.noOfSeats; j++) {
                if (company.seats[j].seatNo == desiredSeatNo) {
                    int alreadyAssigned = 0;
                    for (int k = 0; k < company.noOfEmployees; k++) {
                        if (company.employees[k].assignedSeat == &company.seats[j]) {
                            alreadyAssigned = 1;
                            break;
                        }
                    }

                    if (!alreadyAssigned) {
                        assigned = &company.seats[j];
                    } else {
                        printf("Seat already assigned to another employee. Try again.\n");
                    }

                    break;
                }
            }

            if (assigned == NULL) {
                printf("Invalid seat number or already assigned! Please re-enter.\n");
            }
        }

        company.employees[i].assignedSeat = assigned;
    }
}

void displaySeatDetails() {
    printf("\n--- Seat Details ---\n");

    if (company.noOfSeats == 0 || company.seats == NULL) {
        printf("No seat details available.\n");
        return;
    }
    for (int i = 0; i < company.noOfSeats; i++) {
        printf("Seat %d: %d\n", i + 1, company.seats[i].seatNo);
    }
}


void displayEmployeeDetails() {
    printf("\n--- Employee Details ---\n");

    for (int i = 0; i < company.noOfEmployees; i++) {
        printf("\nEmployee Name: %s\nEmployee Id: %s\nPhone: %ld\nMail: %s\nRole: %s\n", company.employees[i].employeeName, company.employees[i].employeeId, company.employees[i].employeePhoneNumber, company.employees[i].employeeMailId, company.employees[i].employeeRole);
    }
}

void displaySeatAssignments() {
    printf("\n--- Seat Assignments ---\n");

    for (int i = 0; i < company.noOfEmployees; i++) {
        printf("\nEmployee Name: %s\n", company.employees[i].employeeName);
        if (company.employees[i].assignedSeat != NULL) {
            printf("Assigned Seat: %d\n", company.employees[i].assignedSeat->seatNo);
        } else {
            printf("Assigned Seat: None\n");
        }
    }

    free(company.seats);
    free(company.employees);
}

void companyManagementMenu() {
    int choice;

    while (1) {
        printf("\n----- Company Management Menu -----\n");

        printf("1. Enter Seat Details\n");
        printf("2. Enter Employee Details\n");
        printf("3. Assign Seats\n");
        printf("4. Display Seat Details\n");
        printf("5. Display Employee Details\n");
        printf("6. Display Seat Assignments\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            enterSeatDetails();
            break;
        case 2:
            enterEmployeeDetails();
            break;
        case 3:
            assignSeats();
            break;
        case 4:
            displaySeatDetails();
            break;
        case 5:
            displayEmployeeDetails();
            break;
        case 6:
            displaySeatAssignments();
            break;
        case 7:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("INVALID CHOICE!\n");
        }
    }
}

#endif // COMPANYMANAGEMENT_C
