#include <iostream>

using namespace std;

class Time
{
    int hr;
    int min;

public:
    Time()
    {
        cout << "Enter hr and min" << endl;
        cin >> hr >> min;
    }
    operator int()
    {
        return hr * 60 + min;
    }
};

int main()
{
    Time t;
    int n;
    n=t;
    cout << "Total no of minutes" << n << endl;
    return 0;
}
