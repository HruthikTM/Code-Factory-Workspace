#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <string>
using namespace std;

class Bike
{
public:

    Bike(string model, int cc, float milage, double price);

    ~Bike();

    void display() const;

    string getModel() const;
    int getCC() const;
    float getMilage() const;
    double getPrice() const;

private:
// protected :

    string m_model;
    int m_cc;
    float m_milage;
    double m_price;
};

#endif // BIKE_H
