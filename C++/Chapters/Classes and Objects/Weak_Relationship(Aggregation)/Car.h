#ifndef CAR_H
#define CAR_H

#include<iostream>
using namespace std;

class Car
{
private:
    string m_model;
public:
    Car(const string &model);
    ~Car();

    void showModel();

};

#endif // CAR_H
