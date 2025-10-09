#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;


class Student
{
    string name;
    int roll;


public:
    Student(string n, int r)
    {
        name = n;
        roll = r;

        cout << "Student created: " << name << endl;
    }

    ~Student()
    {
        cout << "Student deleted: " << name << endl;
    }

    void study()
    {
        cout << name << " is studying" << endl;
    }

    void displayStudent()
    {
        cout << "Roll: " << roll << endl;
    }
};

#endif // STUDENT_H
