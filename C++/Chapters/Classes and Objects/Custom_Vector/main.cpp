#include <iostream>
#include "MyVector.h"

using namespace std;
//using namespace Hruthik;

int main()
{
    Hruthik::MyVector<string> v1(10);
    //Hruthik::MyVector<float> v2(10);

    string a = "hruthik";
    string b = "tm";

    v1.pushBack(a);
    v1.pushBack(b);
    // v1.pushBack(&20.9f);
    // v1.pushBack(&30.6);
    // v1.pushBack(&40.4);
    // v1.pushBack(&50.5);

    cout << "Elements: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i]<<   " ";


    // cout << "\n" << **v1.begin() << endl;
    // cout << &v1[0] << endl;
    // cout << v1.end() << endl;
    // cout << &v1[4] << endl;


    // v1.popBack();

    // cout << "\nAfter popBack: ";
    // for (int i = 0; i < v1.size(); i++)
    //     cout << v1[i] << " ";

    // v1.erase(2);

    // cout << "\nAfter erase: ";
    // for (int i = 0; i < v1.size(); i++)
    //     cout << v1[i] << " ";

    // v1.at(1);

    // //v1.insert(1,80);

    // // cout << "\nAfter insert: ";
    // // for (int i = 0; i < v1.size(); i++)
    // //     cout << *v1[i] << " ";

    // cout <<"\n---------------" <<endl;


    return 0;
}
