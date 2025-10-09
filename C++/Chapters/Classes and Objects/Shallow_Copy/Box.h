#ifndef BOX_H
#define BOX_H

#include <iostream>
using namespace std;

class Box
{
private:
    int m_length;
    int *m_breadth;
    int m_height;

public:
    Box();
    ~Box();

    void setDimention(int length, int breadth, int height);
    void showData();
    void deleteBreadth();
};

#endif // BOX_H
