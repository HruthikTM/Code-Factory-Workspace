#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
using namespace std;

class Student
{
private:
    int m_rollNo;
    string m_name;

public:
    Student();
    Student(int rollNo, string name);
    Student(const Student &other);
    ~Student();
};

#endif // STUDENT_H
