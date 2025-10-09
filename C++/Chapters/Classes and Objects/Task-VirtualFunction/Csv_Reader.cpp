
#include "Csv_Reader.h"
#include "EmployeeDetails.h"
#include <fstream>

Csv_Reader::Csv_Reader()
{
    cout << "Csv Reader Constructor" << endl;
}

Csv_Reader::~Csv_Reader()
{
    cout << "Csv Reader Destructor" << endl;
}

void Csv_Reader::readFile(list<EmployeeDetails*>& employeeDetailsList)
{
    fstream csvReader("employees.csv");

    string empId, empName, empDesg;


    while(getline(csvReader, empId, ',') && getline(csvReader, empName, ',') && getline(csvReader, empDesg))
    {
       EmployeeDetails *e = new EmployeeDetails(empId, empName, empDesg);
       employeeDetailsList.push_back(e);
    }

    csvReader.close();
}
