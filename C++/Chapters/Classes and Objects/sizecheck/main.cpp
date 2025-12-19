// #include <iostream>

// using namespace std;

// // class Base
// // {
// //     //int a;
// //     //string b;

// // };

// // class Derived : public Base
// // {
// //     //int ydy;
// // public:
// //     Derived()
// //     {
// //         cout << sizeof(Base) << endl;
// //     }

// // };


// // int main()
// // {
// //     //cout << "Hello World!" << endl;
// //     Derived d;
// //     cout << sizeof(d) << endl;
// //     return 0;
// // }



// // struct Employee
// // {
// // public:
// //     int a;
// //     string b;

// // public:

// //     Employee()
// //     {
// //         cout << "Constructor" << endl;
// //     }

// //     ~Employee()
// //     {
// //         cout << "Destructor" << endl;
// //     }
// // };


// class Employee
// {
// public:
//     int a;
//     string b;

// public:

//     Employee()
//     {
//         cout << "Constructor" << endl;
//     }

//     ~Employee()
//     {
//         cout << "Destructor" << endl;
//     }
// };

// int main()
// {
//     Employee obj;
//     //obj.a;
//     cout << &obj.a << endl;
//     cout << &obj.b << endl;
// }


// #include <iostream>
// using namespace std;

// class Base1 {
// public:

//     Base1()
//     {
//         cout << "base-1 const" << endl;
//     }

//      void show() {
//         cout << "base-1 show" << endl;
//     }
// };

// class Base2
// {
// public:
//     Base2()
//     {
//         cout << "base-2 const" << endl;
//     }

//      void show()
//     {
//         cout << "base-2 show" << endl;
//     }
// };


// class Derived :  public Base1,  public Base2
// {
// public:
//     void show()
//     {
//         cout << "dhdfjh" << endl;
//     }
// };

#include <iostream>
using namespace std;

class Test
{
public:

    Test()
    {

    }
    ~Test()
    {

    }

    static void run()
    {
        cout << "jddhsdjh" << endl;
    }

public:
    int a;
    static int b;
    const int c = 10;
};

int main()
{
    Test d;
    cout << &d.a << endl;
    //cout << Test::b << endl;
    cout << &d.c << endl;

    d.run();
    //d.Base1::show();
}

