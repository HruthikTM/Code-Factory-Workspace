#ifndef CONTAINER_H
#define CONTAINER_H

#include<iostream>
using namespace std;

class Container
{
private:
    int m_length;
    int *m_breadth;
    int m_height;

public:
    Container();
    Container(const Container &copy);
    ~Container();

    Container& operator =(const Container &copy);

    void setDimention(int length, int breadth, int height);
    void showData();

};

#endif // CONTAINER_H
