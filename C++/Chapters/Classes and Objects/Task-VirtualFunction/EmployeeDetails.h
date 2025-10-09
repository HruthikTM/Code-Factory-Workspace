#ifndef EMPLOYEEDETAILS_H
#define EMPLOYEEDETAILS_H

#include<iostream>
#include <list>

using namespace std;

class EmployeeDetails
{
private:
    string m_empId;
    string m_empName;
    string m_empDesignation;

public:
    EmployeeDetails();
    EmployeeDetails(string id,string name,string designation);
    EmployeeDetails(const EmployeeDetails& copy);
    ~EmployeeDetails();

    string getEmployeeId();
    string getEmployeeName();
    string getEmployeeDesg();


};

#endif // EMPLOYEEDETAILS_H
