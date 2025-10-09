#include "Child.h"

void Child :: inputData()
{
    readData();
    cout << "Enter hobby: " << endl;
    cin >> hobby;
}

void Child :: outputData()
{
    printData();
    cout << "hobby = " << hobby << endl;
}
