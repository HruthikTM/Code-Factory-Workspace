#include "airplane.h"

Airplane::Airplane(string a, int c) : m_airline(a), m_capacity(c)
{

        // m_airline = a;
        // m_capacity = c;

        cout << "Airplane created: " << m_airline << endl;

}

Airplane :: ~Airplane()
{

        cout << "Airplane destroyed: " << m_airline << endl;

}

void Airplane :: fly()
{
    cout << m_airline << " is flying" << endl;
}

void Airplane :: land()
{
    cout << m_airline << " is landing" << endl;
}

void Airplane :: setAirline(string airline)
{
    if(m_airline == airline)
        return;

    m_airline = airline;
}

string Airplane :: getAirline()
{
    return m_airline;
}
