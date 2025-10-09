#include <iostream>
#include "Child.h"

using namespace std;


int main()
{
    Child c;

    cout << "Enter child info..." << endl;
    c.inputData();

    cout << "Display child info..." << endl;
    c.outputData();

    return 0;
}
