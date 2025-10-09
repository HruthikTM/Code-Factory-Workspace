#ifndef CSV_READER_H
#define CSV_READER_H

#include<iostream>
#include "FileReader.h"
class EmployeeDetails;

using namespace std;

class Csv_Reader : public FileReader
{
public:
    Csv_Reader();
    ~Csv_Reader();
    void readFile();
};

#endif // CSV_READER_H
