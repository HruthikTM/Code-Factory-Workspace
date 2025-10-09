#include <iostream>

using namespace std;

int main()
{
    int num1, num2;

    cout << "Enter 2 numbers: ";
    cin >> num1 >> num2;

    if(num1>num2)
        cout << "Largest Number is: " << num1 << endl;
    else
        cout << "largest Number is: " << num2 << endl;

    return 0;
}
