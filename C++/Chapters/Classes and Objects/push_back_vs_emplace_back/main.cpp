#include <iostream>
#include <vector>
using namespace std;


class Employee
{
public:
    //string m_name;
    int m_age;

    Employee(/*string name,*/int age) : /*m_name(name),*/ m_age(age)
    {
        cout << "Parameterized Constructor" << endl;
    }

    Employee(const Employee& copy)
    {
        cout << "Copy Constructor" << endl;
        //m_name = copy.m_name;
        m_age = copy.m_age;
    }

    ~Employee()
    {
        cout << "Employee Destructor" << endl;
    }
};

int main() {
    vector<Employee> m_vector1;
    vector<Employee> m_vector2;

    cout << "Using push_back:\n";
    m_vector1.push_back(23);
    m_vector1.push_back(28);
    m_vector1.push_back(25);
    m_vector1.push_back(26);
     //m_vector.push_back("Chetan");

    // Employee e("Hruthik",23);
    // m_vector.push_back(e);




    cout << "\nUsing emplace_back:\n";
    m_vector2.emplace_back(23);
    m_vector2.emplace_back(24);
    m_vector2.emplace_back(25);
    m_vector2.emplace_back(26);

    return 0;
}

