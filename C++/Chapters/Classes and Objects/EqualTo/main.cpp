#include <iostream>

using namespace std;

class A{
public:
    int m_num1;
    int m_num2;
    A(){

    }
    A(int num1,int num2){
        m_num1 = num1;
        m_num2 = num2;
    }
    A operator=(A& obj){
        this->m_num1 = obj.m_num1;
        this->m_num2 = obj.m_num2;
        return *this;
    }

};

int main()
{
    cout << "Hello World!" << endl;
    A a(10,20);

    A b;
    b = a;
    cout << b.m_num1 << " " << b.m_num2;

    return 0;
}
