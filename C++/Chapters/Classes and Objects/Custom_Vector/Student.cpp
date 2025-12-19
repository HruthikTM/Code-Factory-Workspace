#include <Student.h>

Student::Student()
{
    cout << "Student Constructor" << endl;
}

Student::Student(int rollNo, string name) : m_rollNo(rollNo), m_name(name)
{
    cout << "Student Parameterized Constructor" << endl;
}

Student::Student(const Student &other) : m_rollNo(other.m_rollNo), m_name(other.m_name)
{
    cout << "Student Copy Constructor" << endl;
}

Student::~Student()
{
    cout << "Student Destructor" << endl;
}
