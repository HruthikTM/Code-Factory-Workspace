#include "Bike.h"


Bike::Bike(string model, int cc, float milage, double price) : m_model(model), m_cc(cc), m_milage(milage), m_price(price)
{
    cout << "Bike object created" << endl;
}

Bike::~Bike()
{
    cout << "Bike object destroyed" << endl;
}

void Bike::display() const
{
    cout << "Model: " << m_model << ", CC: " << m_cc << ", Milage: " << m_milage << ", Price: " << m_price << endl;
}

string Bike:: getModel() const
{
    return m_model;
}

int Bike:: getCC() const
{
    return m_cc;
}

float Bike:: getMilage() const
{
    return m_milage;
}

double Bike:: getPrice() const
{
    return m_price;
}
