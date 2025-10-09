#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <iostream>
#include <string>
#include "AirConditioner.h"
#include "MusicPlayer.h"
#include "UsbPort.h"

using namespace std;

class DashBoard
{
public:

    DashBoard();

    ~DashBoard();

    void operate();

private:
    AirConditioner m_myAC;
    MusicPlayer m_myMusicPlayer;
    UsbPort m_myUSB;
};

#endif // DASHBOARD_H
