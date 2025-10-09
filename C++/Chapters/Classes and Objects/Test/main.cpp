#include <iostream>

using namespace std;

class A
{
public:
    void work()
    {
        cout << "work from office" << endl;
    }

};



int main()
{

    //(new A)->work();

    A *p = new A;
    p->work();
    delete p;


    return 0;
}
