#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee
{
    string name;
    double salary;

public:
    Employee(string n, double s)
    {
        name = n;
        salary = s;

        cout << "Employee created: " << name << endl;
    }

    ~Employee()
    {
        cout << "Employee destroyed: " << name << endl;
    }

    void work()
    {
        cout << name << " is working " << endl;
    }

    void showSalary()
    {
        cout << name << "'s salary: " << salary << endl;
    }
};

#endif // EMPLOYEE_H
