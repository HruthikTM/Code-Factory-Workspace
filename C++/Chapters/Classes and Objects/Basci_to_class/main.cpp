#include <iostream>

using namespace std;

class Time
{
    int hr;
    int min;

public:
    Time() : hr(0), min(0)
    {
    }

    Time(int n)
    {
        cout << "Conversion" <<endl;
        hr = n/60;
        min  = n%60;
    }

    void get_data()
    {
        cout << hr << "hours" << min << "minutes" << endl;
    }
};



int main()
{
    Time t;
    t.get_data();
    int n;
    cout << "Enter num of minutes" << endl;
    cin>>n;
    t=n;
    t.get_data();
    return 0;
}
