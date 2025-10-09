#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <iostream>
#include <string>

using namespace std;

class MusicPlayer
{
public:
    MusicPlayer();

    ~MusicPlayer();

    void playMusic();

    void pauseMusic();
};

#endif // MUSICPLAYER_H
