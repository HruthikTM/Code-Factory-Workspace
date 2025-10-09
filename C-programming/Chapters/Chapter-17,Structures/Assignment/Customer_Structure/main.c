#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 200
#define MIN_BALANCE 100

struct Customer {
    int accountNumber;
    char name[50];
    float balance;
};

void printLowBalanceCustomers(struct Customer customers[], int n);
void processTransaction(struct Customer customers[], int n, int accNo, float amount, int code);

int main() {
    struct Customer customers[MAX_CUSTOMERS];
    int n;

    printf("Enter number of customers (max 200): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for customer %d:\n", i + 1);
        printf("Account Number: ");
        scanf("%d", &customers[i].accountNumber);
        printf("Name: ");
        scanf(" %s", customers[i].name);
        printf("Balance: ");
        scanf("%f", &customers[i].balance);
    }

    printLowBalanceCustomers(customers, n);

    int accNo, code;
    float amount;
    char choice;

    do {
        printf("\nEnter transaction details:\n");
        printf("Account Number: ");
        scanf("%d", &accNo);
        printf("Amount: ");
        scanf("%f", &amount);
        printf("Enter 1 for deposit, 0 for withdrawal: ");
        scanf("%d", &code);

        processTransaction(customers, n, accNo, amount, code);

        printf("Do you want to perform another transaction? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void printLowBalanceCustomers(struct Customer customers[], int n) {
    printf("\nCustomers with balance below Rs. 100:\n");
    for (int i = 0; i < n; i++) {
        if (customers[i].balance < MIN_BALANCE) {
            printf("Account Number: %d, Name: %s\n", customers[i].accountNumber, customers[i].name);
        }
    }
}

void processTransaction(struct Customer customers[], int n, int accNo, float amount, int code) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (customers[i].accountNumber == accNo) {
            found = 1;
            if (code == 1) {
                customers[i].balance += amount;
                printf("Deposit successful. New balance: %.2f\n", customers[i].balance);
            } else if (code == 0) {
                if (customers[i].balance - amount < MIN_BALANCE) {
                    printf("The balance is insufficient for the specified withdrawal.\n");
                } else {
                    customers[i].balance -= amount;
                    printf("Withdrawal successful. New balance: %.2f\n", customers[i].balance);
                }
            } else {
                printf("Invalid transaction code.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Account not found.\n");
    }
}
