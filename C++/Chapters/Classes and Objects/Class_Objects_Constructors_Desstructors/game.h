#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

using namespace std;

class Game
{
    string title;
    string genre;

public:
    Game(string t, string g): title(t), genre(g)
    {
        cout << "Game created: " << title << endl;
    }

    ~Game()
    {
        cout << "Game destroyed: " << title << endl;
    }

    void play()
    {
        cout << "Playing " << title << endl;
    }

    void quit()
    {
        cout << "Quit " << title << endl;
    }
};


#endif // GAME_H
