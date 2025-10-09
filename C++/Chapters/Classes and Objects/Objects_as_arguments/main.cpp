#include <iostream>

using namespace std;

class Time{
    int hours;
    int minutes;

public:
    void getTime(int h, int m)
    {
        hours = h;
        minutes = m;
    }

    void putTime()
    {
        cout << hours << " hours and " ;
        cout << minutes << " minutes " << "\n";
    }

    void sum(Time, Time);
};

void Time :: sum(Time t1, Time t2)
{
    minutes = t1.minutes + t2.minutes;
    hours = minutes / 60;
    minutes = minutes % 60;
    hours = hours + t1.hours + t2.hours;
}



int main()
{
    Time t1, t2, t3;

    t1.getTime(2,45);
    t2.getTime(3,30);

    t3.sum(t1,t2);

    cout << "Time 1: " ;
    t1.putTime();

    cout << "Time 2: " ;
    t2.putTime();

    cout << "Time 3: " ;
    t3.putTime();

    return 0;
}
