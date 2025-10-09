#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <list>
#include "EmployeeDetails.h"
#include "FileReader.h"

using namespace std;

class Company
{
private:
    list<EmployeeDetails*> csvList;
    list<EmployeeDetails*> txtList;
    list<EmployeeDetails*> sqlList;
public:
    Company();
    ~Company();

    void setupFile();
    void display(const list<EmployeeDetails*>& lst);
};

#endif
