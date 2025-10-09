#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
    cout << "Music player object is created"<<endl;
}

MusicPlayer::~MusicPlayer()
{
    cout << "Music player object is destroyed"<<endl;
}

void MusicPlayer :: playMusic()
{
    cout << "Music is playing"<<endl;
}

void MusicPlayer :: pauseMusic()
{
    cout << "Music is paused"<<endl;
}
