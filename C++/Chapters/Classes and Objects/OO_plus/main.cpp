#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    Student s1(10,20);
    Student s2(20,30);

    Student s3 = s1 + s2;
    cout << s3.m_a << "," << s3.m_b << endl;

    Student s4 = s1 - s2;
    cout << s4.m_a << "," << s4.m_b << endl;

    Student s5 = s1 * s2;
    cout << s5.m_a << "," << s5.m_b << endl;

    Student s6 = s1 / s2;
    cout << s6.m_a << "," << s6.m_b << endl;

    return 0;
}
