#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>
#include <string>

using namespace std;


class Airplane
{
    string m_airline;
    int m_capacity;

public:
    Airplane(string a, int c);


    ~Airplane();


    void fly();


    void land();

    string getAirline();

    void setAirline(string airline);

};

#endif // AIRPLANE_H
