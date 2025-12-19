#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *ptr = new int;
    *ptr = a;

    cout << "Before delete:" << endl;
    cout << "a = " << a << endl << "*ptr = " << *ptr << endl << "ptr = " << ptr << endl;

    // delete ptr;
    // ptr = nullptr;

    cout << "\nAfter delete:" << endl;
    cout << "a = " << a << endl << "*ptr = " << *ptr << endl << "ptr = " << ptr << endl;


    // if (ptr == nullptr)
    //     cout << "ptr is nullptr now." << endl;
    // else
    //     cout << "*ptr = " << *ptr << endl;

    return 0;
}
