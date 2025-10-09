#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>

using namespace std;


class Teacher
{
    string name;
    string subject;

public:
    Teacher(string n, string s)
    {
        name = n;
        subject = s;

        cout << "Teacher created: " << name << "," << "handling subject" << subject << endl;
    }

    ~Teacher()
    {
        cout << "Teacher destroyed: " << name << endl;
    }

    void teach()
    {
        cout << name << " teaches" << subject << endl;
    }

    void introduce()
    {
        cout << "Hello I am " << name <<endl;
    }
};

#endif // TEACHER_H
