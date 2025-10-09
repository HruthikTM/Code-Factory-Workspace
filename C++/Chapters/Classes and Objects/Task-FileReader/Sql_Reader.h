#ifndef SQL_READER_H
#define SQL_READER_H

#include<iostream>
#include <sqlite3.h>
#include "FileReader.h"
class EmployeeDetails;

using namespace std;

class Sql_Reader : public FileReader
{
public:
    Sql_Reader();
    ~Sql_Reader();

    void readFile();
};

#endif // SQL_READER_H
