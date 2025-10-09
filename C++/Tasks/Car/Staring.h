#ifndef STARING_H
#define STARING_H

#include <iostream>
#include <string>

using namespace std;

class Staring
{
public:
    Staring();

    ~Staring();

    void setHandleType(string handleType);
    string getHandleType();

    void turnRight();
    void turnLeft();
    void horn();

private:
    string m_handleType;
};

#endif // STARING_H
