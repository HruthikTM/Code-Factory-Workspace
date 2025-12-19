#ifndef B_H
#define B_H

#include<iostream>
using namespace std;

class B
{
    int m,n;
public:
    B() : m(0),n(0) {}

    B(int a,int b) : m(a),n(b)
    {

    }

    void get_b()
    {
        cout << m << " "<< n << endl;
    }
};

#endif // B_H
