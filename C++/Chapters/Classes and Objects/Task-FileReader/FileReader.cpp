#include "FileReader.h"

FileReader::FileReader()
{
    cout << "File Reader Constructor" << endl;
}

FileReader::~FileReader()
{
    cout << "File Reader Destructor" << endl;
}

void FileReader::setEmpList(EmployeeDetails* newEmpList)
{
    empList.push_back(newEmpList);
}

void FileReader :: displayFile()
{
    if (empList.empty())
    {
        cout << "No employee data available" << endl;
    }
    else
    {
        cout << left << setw(5) << "ID" << left << setw(20) << "Name" << "Designation" << '\n';

        for (auto e : empList)
        {
            cout << left << setw(5)  << e->getEmployeeId() << left << setw(20) << e->getEmployeeName() << e->getEmployeeDesg() << '\n';
        }
    }
}
