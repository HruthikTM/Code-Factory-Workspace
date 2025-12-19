#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
using namespace std;

namespace Hruthik
{

template<class T>
class MyVector
{
private:
    T* m_arr;
    int m_capacity;
    int m_length;

public:
    MyVector();
    MyVector(int n);
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);
    ~MyVector();

    void resize(int newCapacity);
    void pushBack(const T& value);
    void popBack();

    int size() const;
    void erase(int index);
    void at(int index);

    bool isEmpty();
    void insert(int index, const T& value);

    T* begin();
    T* end();

    T& operator[](int index);
    const T& operator[](int index) const;
};

}

#endif // MYVECTOR_H
