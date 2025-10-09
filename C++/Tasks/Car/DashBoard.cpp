#include "DashBoard.h"

DashBoard::DashBoard()
{
    cout << "Dashboard object created"<<endl;
}

DashBoard::~DashBoard()
{
    cout << "Dashboard object created"<<endl;
}

void DashBoard :: operate()
{
    m_myAC.cool();
    m_myAC.warm();

    m_myMusicPlayer.playMusic();
    m_myMusicPlayer.pauseMusic();

    m_myUSB.connectDevice();
}
