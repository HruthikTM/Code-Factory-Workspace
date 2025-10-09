#include <iostream>
#include <vector>

using namespace std;

class Test
{
private:
    int m_a;
public:

    Test(int a)
    {
        m_a = a;
        cout << "Constructor" << endl;
    }

    ~Test()
    {
        cout << "Destructor" << endl;
    }

    Test(const Test& obj)
    {
        cout << "copy constructor" << endl;
        m_a = obj.m_a;
    }


};

int main()
{
    vector<Test> v1;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);




    cout << "size:" << v1.size() << endl;
    cout << "capacity: " << v1.capacity() << endl;

    return 0;
}


