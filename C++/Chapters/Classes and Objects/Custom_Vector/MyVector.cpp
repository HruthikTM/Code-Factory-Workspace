#include "MyVector.h"
using namespace Hruthik;

template<class T>
MyVector<T>::MyVector() : m_arr(nullptr), m_capacity(0), m_length(0)
{
    cout << "MyVector Constructor" << endl;
}

template<class T>
MyVector<T>::MyVector(int n) : m_capacity(n), m_length(0)
{
    cout << "MyVector Parameterised Constructor" << endl;
    m_arr = new T[n];
}

template<class T>
MyVector<T>::MyVector(const MyVector &other) : m_capacity(other.m_capacity), m_length(other.m_length)
{
    cout << "MyVector Copy Constructor" << endl;
    m_arr = new T[m_capacity];
    for (int i = 0; i < m_length; i++)
        m_arr[i] = other.m_arr[i];
}

template<class T>
void MyVector<T>::resize(int newCapacity)
{
    T *newArr = new T[newCapacity];
    for(int i =0; i < m_length; i++)
    {
        newArr[i] = m_arr[i];
    }
    delete[] m_arr;
    m_arr = newArr;
    m_capacity = newCapacity;
}

template<class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
    cout << "Copy elements using Assignment Operator" << endl;
    if (this != &other)
    {
        delete[] m_arr;
        m_capacity = other.m_capacity;
        m_length = other.m_length;
        m_arr = new T[m_capacity];
        for (int i = 0; i < m_length; i++)
            m_arr[i] = other.m_arr[i];
    }
    return *this;
}

template<class T>
MyVector<T>::~MyVector()
{
    delete[] m_arr;
}

template<class T>
void MyVector<T>::pushBack(const T &value)
{
    if (m_length == m_capacity)
        resize(m_capacity == 0 ? 1 : m_capacity * 2);
    m_arr[m_length++] = value;
}

template<class T>
void MyVector<T>::popBack()
{
    if (m_length > 0)
        m_length--;
}

template<class T>
T& MyVector<T>::operator[](int index)
{
    if (index < 0 || index >= m_length)
        cout << "Index out of range" <<endl;
    return m_arr[index];
}

template<class T>
const T& MyVector<T>::operator[](int index) const
{
    if (index < 0 || index >= m_length)
        cout << "Index out of range" <<endl;
    return m_arr[index];
}

template<class T>
int MyVector<T>::size() const
{
    return m_length;
}

template<class T>
void MyVector<T>::erase(int index)
{
    if(index >= m_length)
    {
        cout << "\nIndex out of Range.." << endl;
        return;
    }

    for (int i = index; i < m_length-1; i++)
    {
        m_arr[i] = m_arr[i+1];
    }

    m_length--;
}

template<class T>
bool MyVector<T>::isEmpty()
{
    if(m_length == 0)
        return true;
    else
        return false;
}

template<class T>
void MyVector<T>::insert(int index, const T &value)
{
    if (index < 0 || index > m_length)
        cout << "Index out of range" << endl;
    if (m_length == m_capacity)
        resize(m_capacity * 2);
    for (int i = m_length; i > index; i--)
    {
        m_arr[i] = m_arr[i - 1];
    }
    m_arr[index] = value;
    m_length++;
}

template<class T>
void MyVector<T>::at(int index)
{
    if (index >= m_length)
        cout << "\nIndex out of range" << endl;
    else
        cout << "\nValue at given Index: "<< m_arr[index] << endl;
}

template<class T>
T* MyVector<T>::begin()
{
    return m_arr;
}

template<class T>
T* MyVector<T>::end()
{
    return m_arr + m_length-1;
    //return &m_arr[m_length]; //the above stmt and this is one and the same
}


//template class MyVector<int>;
//template class MyVector<float>;
template class MyVector<string>;
//template class MyVector<string>;
//template class MyVector<int>;

