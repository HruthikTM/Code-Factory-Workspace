#ifndef FILEREADER_H
#define FILEREADER_H

#include<iostream>
#include <list>
#include "EmployeeDetails.h"
using namespace std;

class FileReader
{
public:
    FileReader();
    virtual ~FileReader();

    virtual void readFile(list<EmployeeDetails*>& employeeDetailsList) = 0;
};

#endif // FILEREADER_H
