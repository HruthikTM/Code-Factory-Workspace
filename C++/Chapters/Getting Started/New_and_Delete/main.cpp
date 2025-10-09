#include <iostream>

using namespace std;

int main()
{
    int *arr;
    int size;

    cout << "Enter the size of array: ";
    cin >> size;

    cout << "Creating array of size: " << size << endl;
    arr = new int[size];

    cout << "Dynamic allocation of memeory is successful";

    delete arr;


    return 0;
}
