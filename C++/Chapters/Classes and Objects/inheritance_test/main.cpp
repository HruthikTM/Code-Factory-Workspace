#include <iostream>

using namespace std;

class Base{

    int a = 10;
public:
    // virtual void work()
    // {
    //     cout << "Work" << endl;
    // }

};

// class Derived : public Base
// {
// public:
//     void work()
//     {
//         cout << "Work" << endl;
//     }

//     virtual void run()
//     {
//         cout << "Run" << endl;
//     }
// };

// class Derived2 : public Derived
// {
// public:
//     void work()
//     {
//         cout << "Work" << endl;
//     }

// };

int main()
{

    Base b;
    cout << sizeof(b) << endl;
    // Base *ptr = new Derived();
    // ptr->work();

    // Base *ptr = new Derived2();
    // ptr->work();

    // Derived *pt = new Derived2();
    // pt->work();
    //cout << "Hello World!" << endl;
    return 0;
}
