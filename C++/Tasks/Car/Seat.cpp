#include "Seat.h"

Seat::Seat()
{
    cout << " Seat object is created " << endl;
}

Seat :: ~Seat()
{
    cout << " Seat object is destroyed " << endl;
}

void Seat :: setSeatType(string seatType)
{
    m_seatType = seatType;
}

string Seat :: getSeatType()
{
    return m_seatType;
}

void Seat :: setSeatLength(int seatLength)
{
    m_seatLength = seatLength;
}

int Seat :: getSeatLength()
{
    return m_seatLength;
}


void Seat :: seatIncline()
{
    cout << "Seat inclined" << endl;
}

void Seat :: seatDecline()
{
    cout << "Seat declined" << endl;
}
