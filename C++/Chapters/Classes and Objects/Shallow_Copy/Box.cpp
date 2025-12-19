#include "Box.h"

Box::Box()
{
    cout << "Box Constructor" << endl;
}

Box::~Box()
{
    cout << "Box Destructor" << endl;
}

Box::Box(Box &copy)
{
    cout << "Shallow-Copy Copy Constructor" << endl;
    m_length = copy.m_length;
    m_height = copy.m_height;
    m_breadth = copy.m_breadth;
}

// Box &Box::operator=(const Box &copy)
// {
//     cout << "Shallow-Copy Assignment Operator" << endl;

//     if (this != &copy)
//     {
//         m_length = copy.m_length;
//         m_height = copy.m_height;
//         m_breadth = copy.m_breadth;
//     }

//     return *this;
// }

void Box :: setDimention(int length, int height, int breadth)
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
