#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>

using namespace std;

class Sample
{
private:
    int a, b;
public:
    Sample();
    Sample(int x, int y);
    ~Sample();
    friend Sample operator + (Sample &, Sample &);
    void display();
};

#endif // SAMPLE_H
