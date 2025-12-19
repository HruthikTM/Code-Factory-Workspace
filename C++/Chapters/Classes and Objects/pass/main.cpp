#include <iostream>

using namespace std;

//int a = 10, b = 20;


void fun(int a, int b)
{
    cout << "pass by value" << endl;
}

void fun( int &a, int &b)
{
    cout << "pass by reference" << endl;
}

void fun(int *a, int *b)
{
    cout << "pass by address" << endl;
}



int main()
{
    int a = 30;
    float b = 23.444444444444444444444f;
    double d = 45.88888888888888888888888888888;
    // cout << &a << endl;
    // a = 40;
    cout << b << endl;
    cout << d << endl;


    //fun(&a,&b);//call by address
    //fun(a, b); //call by reference
    //fun(10,20);//call by value

    return 0;
}
