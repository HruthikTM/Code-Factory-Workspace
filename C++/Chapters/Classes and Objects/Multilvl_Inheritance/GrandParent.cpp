#include "GrandParent.h"

void GrandParent :: getData()
{
    cout << "Enter the name:" << endl;
    cin >> name;
    cout << "Enter the age:" << endl;
    cin >> age;
    cout << "Enter the color:" << endl;
    cin >> color;
}

void GrandParent :: displayData()
{
    cout << "Name =" << name << endl << "Age = " << age << endl << "Color = " << endl;
}

