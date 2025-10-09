#include "Parent.h"

void Parent :: readData()
{
    getData();

    cout << "Enter the qualification : " << endl;
    cin >> qual;
    cout << "Enter salary: " << endl;
    cin >> salary;
}

void Parent :: printData()
{
    displayData();

    cout << "Qualification : " << qual << endl;
    cout << "Salary: " << salary << endl;
}

