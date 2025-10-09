#include <iostream>

using namespace std;

class Sample
{
public:
    Sample();
    Sample(int x,int y);
    ~Sample();

    void operator =(Sample & object)
    {
        cout << object.m_num1;
        cout << object.m_num2;

        m_num1 = object.m_num1;
        m_num2 = object.m_num2;
    }

    int m_num1;
    int m_num2;
};

Sample ::Sample()
{
    cout << "Constructor" <<endl;
}

Sample ::~Sample()
{
    cout << "Destructor" <<endl;
}

Sample::Sample(int x,int y)
{
    m_num1 = x;
    m_num2 = y;
}

int main()
{
    Sample s1(10,20);
    Sample s2;

    cout << sizeof(s2) << endl;
     s2 = s1;
     cout << s2.m_num1 << " " << s2.m_num2 << endl;

    return 0;
}
