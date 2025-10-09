#include <iostream>
#include <string>
using namespace std;

class Employee{
    char name[10];
    float age;

public:
    void getData();
    void putData();
};

void Employee :: getData()
{
    cout << "Enter name: " ;
    cin >> name;
    cout << "Enter age: " ;
    cin >> age;
}

void Employee :: putData()
{
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
}

const int arraySize = 3;

int main()
{
    Employee manager[arraySize];

    for(int i = 0; i < arraySize ; i++)
    {
        cout << "\nDetails of manager" << i+1 << "\n";
        manager[i].getData();
    }

    cout << "\n";
    for (int i = 0; i < arraySize ; i++)
    {
        cout << "\nManager" << i+1 << "\n";
        manager[i].putData();
    }
    return 0;
}
