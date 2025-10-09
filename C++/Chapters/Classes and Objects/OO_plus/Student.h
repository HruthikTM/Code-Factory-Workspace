#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student
{
public:
    Student();
    Student(int num1, int num2);
    ~Student();

    Student operator +(Student &obj);
    Student operator -(Student &obj);
    Student operator *(Student &obj);
    Student operator /(Student &obj);

    int m_a;
    int m_b;
};

#endif // STUDENT_H
