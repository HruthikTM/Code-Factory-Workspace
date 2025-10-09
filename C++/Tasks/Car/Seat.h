#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>

using namespace std;

class Seat
{
public:

    Seat();

    ~Seat();

    void setSeatType(string seatType);
    string getSeatType();

    void setSeatLength(int seatLength);
    int getSeatLength();

    void seatIncline();
    void seatDecline();

private:

    string m_seatType;
    int m_seatLength;
};

#endif // SEAT_H
