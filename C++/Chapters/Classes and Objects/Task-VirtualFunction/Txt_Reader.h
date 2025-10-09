#ifndef TXT_READER_H
#define TXT_READER_H

#include<iostream>
#include "FileReader.h"
class EmployeeDetails;

using namespace std;

class Txt_Reader : public FileReader
{
public:
    Txt_Reader();
    ~Txt_Reader();

    void readFile(list<EmployeeDetails*>& employeeDetailsList);
};

#endif // TXT_READER_H
