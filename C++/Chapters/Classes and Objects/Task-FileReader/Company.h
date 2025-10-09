#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <list>
#include <map>
#include "EmployeeDetails.h"
#include "FileReader.h"

using namespace std;
enum  Operation
{
    Fetch_Data = 1,
    Display_Data,
    EXIT
};

enum  FetchFile
{
    Fetch_CSV = 1,
    Fetch_Text,
    Fetch_SQL,
    Main_Menu
};

enum  DisplayFile
{
    Display_CSV = 1,
    Display_Text,
    Display_SQL,
    Mainmenu
};

enum FileType
{
    CSV = 1,
    TEXT,
    SQL
};

class Company
{
private:
    map<FileType, FileReader*> m_fileMap;

public:
    Company();
    ~Company();

    void setupFile();
    void display();
};

#endif
