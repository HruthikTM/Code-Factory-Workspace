#include <iostream>

using namespace std;

void func(const int b)
{
    b = 30;
    cout << b << endl;
}


class A
{
private:
    int m_a = 100;
public:
    int geta() const{
        m_a =200;
        return m_a;
    }
    void seta(int a)
    {
        m_a = a;
    }
};

int main()

{
    const int a= 10;
    a=20;
    func(a);



    cout << "Hello World!" << endl;
    return 0;
}
