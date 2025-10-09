#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

using namespace std;

class Song
{
    string title;
    string artist;

public:
    Song(string t, string a)
    {
        title = t;
        artist = a;
        cout << "Song created: " << title << endl;
    }

    ~Song()
    {
        cout << "Song destroyed: " << title << endl;
    }

    void play()
    {
    cout << "Playing " << title << " by " << artist << endl;
    }

    void stop()
    {
        cout << title << " stopped " << endl;
    }
};

#endif // SONG_H
