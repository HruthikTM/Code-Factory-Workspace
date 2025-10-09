#include "Student.h"

Student::Student()
{
    cout <<"Default constructor"<<endl;
}

Student::Student(int num1,int num2)
{
    cout <<"Parameterised constructor"<<endl;
    m_a = num1;
    m_b = num2;
}

Student::~Student()
{
    cout << "Destructor" <<endl;
}

Student Student :: operator +(Student &obj)
{
    cout << obj.m_a << "-------------s2-----------," << obj.m_b << endl;
    cout << m_a << "-------------s1-----------," << m_b << endl;
    Student temp;
    temp.m_a = m_a + obj.m_a;
    temp.m_b = m_b + obj.m_b;
    return temp;
}

Student Student :: operator -(Student &obj)
{
    Student temp;
    temp.m_a = m_a - obj.m_a;
    temp.m_b = m_b - obj.m_b;
    return temp;
}

Student Student :: operator *(Student &obj)
{
    Student temp;
    temp.m_a = m_a * obj.m_a;
    temp.m_b = m_b * obj.m_b;
    return temp;
}

Student Student :: operator /(Student &obj)
{
    Student temp;
    temp.m_a = m_a / obj.m_a;
    temp.m_b = m_b / obj.m_b;
    return temp;
}
