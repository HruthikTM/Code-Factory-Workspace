#include "Box.h"

Box::Box()
{
    cout << "Box Constructor" << endl;
}

Box::~Box()
{
    cout << "Box Destructor" << endl;
}

void Box :: setDimention(int length, int breadth, int height)
{
    m_length = length;
    m_breadth = new int;
    *m_breadth = breadth;
    m_height = height;
}

void Box :: showData()
{
    cout << "Length=" << m_length << endl << "Height=" << m_height << endl << "Breadth=" << *m_breadth << endl << "Breadth pointer address=" << m_breadth << endl;
}

void Box::deleteBreadth()
{
    delete m_breadth;
    m_breadth = nullptr;
    cout << "Breadth deleted!" << endl;
}
