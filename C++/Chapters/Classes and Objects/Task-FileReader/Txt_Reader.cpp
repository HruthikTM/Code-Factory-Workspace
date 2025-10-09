#include "Txt_Reader.h"
#include "EmployeeDetails.h"
#include <fstream>


Txt_Reader::Txt_Reader()
{
    cout << "Text Reader Constructor" << endl;
}

Txt_Reader::~Txt_Reader()
{
    cout << "Text Reader Destructor" << endl;
}

void Txt_Reader::readFile()
{
    fstream txtReader("employees.txt");

    string empId, empName, empDesg;

    while(getline(txtReader, empId, ' ') && getline(txtReader, empName, ' ') && getline(txtReader, empDesg))
    {
        EmployeeDetails *e = new EmployeeDetails(empId, empName, empDesg);
        setEmpList(e);
    }

    txtReader.close();
}
