#ifndef WATCH_H
#define WATCH_H

#include <iostream>
#include <string>

using namespace std;


class Watch
{
    string brand;
    bool digital;

public:
    Watch(string b, bool d)
    {
        brand = b;
        digital = d;

        cout << "Watch created: " << brand << endl;
    }

    ~Watch()
    {
        cout << "Watch destroyed: " << brand << endl;
    }

    void showTime()
    {
        cout << "Showing time.." << endl;
    }

    void alarm()
    {
        cout << "Alarm ringing!" << endl;
    }
};

#endif // WATCH_H
