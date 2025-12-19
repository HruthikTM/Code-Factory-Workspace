// #include <iostream>

// using namespace std;

// class Move
// {
// public:

//     int* p;

//     Move(int v) : p(new int(v)) {}

//     // Copy constructor
//     Move(const Move& other) : p(new int(*other.p))
//     {
//         cout << "copy\n";
//     }

//     // Move constructor
//     Move(Move&& other) : p(other.p)
//     {
//         other.p = nullptr;
//         cout << "move\n";
//     }

//     ~Move()
//     {
//         delete p;
//     }
// };

// Move makeA()
// {
//     return Move(42);  // creates a temporary (rvalue)
// }

// int main() {
//     Move x(10);

//     Move y = x;         // calls copy constructor
//     Move z = makeA();   // calls move constructor

//     return 0;
// }


#include <iostream>

using namespace std;

class Base
{

private:
    int m_x;
public:
    Base(int x) : m_x(x)
    {
        cout << "Base initialized with "  << "\n";
        cout << m_x << endl;
    }
    // int getX() const;
    // void setX(int newX);
};

class Derived : public Base {
public:
    Derived(int x) : Base(x) {}  // calling base class constructor
    virtual void fun() = 0;      // abstract class
};

// Concrete class implementing foo()
class Child : public Derived {
public:
    Child(int x) : Derived(x) {}

    void fun() override {
        cout << "fun() implemented in Child\n";
    }
};

int main() {
    Child c(10);   // allowed — Child is concrete
    c.fun();       // calling implemented method

    return 0;
}

// int Base::getX() const
// {
//     return x;
// }

// void Base::setX(int newX)
// {
//     x = newX;
// }
