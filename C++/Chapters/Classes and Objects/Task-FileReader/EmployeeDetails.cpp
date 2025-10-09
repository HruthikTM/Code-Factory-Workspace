#include "EmployeeDetails.h"

EmployeeDetails::EmployeeDetails()
{
    cout << "Employee details constructor" << endl;
}

EmployeeDetails::EmployeeDetails(string id,string name,string designation): m_empId(id), m_empName(name), m_empDesignation(designation)
{
    cout << "Employee para details constructor" << endl;
}

EmployeeDetails::EmployeeDetails(const EmployeeDetails& copy) : m_empId(copy.m_empId), m_empName(copy.m_empName), m_empDesignation(copy.m_empDesignation)
{
    cout << "Employee details copy constructor" << endl;
}

EmployeeDetails::~EmployeeDetails()
{
    cout << "Employee details destructor" << endl;
}

void EmployeeDetails::operator =(EmployeeDetails &obj)
{
    cout << "Assignment operator is called" << endl;
}

string EmployeeDetails ::getEmployeeId()
{
    return m_empId;
}

string EmployeeDetails ::getEmployeeName()
{
    return m_empName;
}

string EmployeeDetails ::getEmployeeDesg()
{
    return m_empDesignation;
}

