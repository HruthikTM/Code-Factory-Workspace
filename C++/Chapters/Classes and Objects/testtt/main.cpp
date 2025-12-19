#include <iostream>
using namespace std;

class Base {
public:
     virtual void show() { cout << "Base"; }
};

class Derived : public Base {
public:
    void show()  { cout << "Derived"; }
};

int main() {
    Base* ptr = new Derived();  // correct!
    ptr->show();                // prints "Derived"
    return 0;
}
