#include "Container.h"

Container::Container()
{
    cout << "Container Constructor" << endl;
    m_breadth = nullptr;
}

Container::Container(const Container &copy)
{
    cout << "Copy Constructor" << endl;
    m_length = copy.m_length;
    m_height = copy.m_height;
    m_breadth = new int;
    *m_breadth = *copy.m_breadth;
}

Container::~Container()
{
    cout << "Container Destructor" << endl;
    delete m_breadth;
}

Container &Container::operator =(const Container &copy)
{
    cout << "Assignment Operator" << endl;

    if (this != &copy)
    {
        delete m_breadth;
        m_length = copy.m_length;
        m_height = copy.m_height;
        m_breadth = new int;
        *m_breadth = *copy.m_breadth;
    }
    return *this;
}

void Container :: setDimention(int length, int breadth, int height)
{
    m_length = length;
    m_breadth = new int;
    *m_breadth = breadth;
    m_height = height;
}

void Container :: showData()
{
    cout << "Length=" << m_length << "\nHeight=" << m_height << "\nBreadth=" << *m_breadth << "\nBreadth pointer address=" << m_breadth << endl << endl;
}
