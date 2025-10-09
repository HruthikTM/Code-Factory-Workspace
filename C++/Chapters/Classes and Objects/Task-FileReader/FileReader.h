#ifndef FILEREADER_H
#define FILEREADER_H

#include<iostream>
#include<iomanip>
#include <list>
#include "EmployeeDetails.h"

using namespace std;

class FileReader
{
private:
    list<EmployeeDetails*> empList;
public:
    FileReader();
    virtual ~FileReader();

    virtual void readFile() = 0;

    void setEmpList(EmployeeDetails* newEmpList);

    void displayFile();
};

#endif // FILEREADER_H
