#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

using namespace std;


class Movie
{
    string title;
    int duration;

public:
    Movie(string t, int d)
    {
        title = t;
        duration = d;
        cout << "Movie created: " << title << endl;
    }

    ~Movie()
    {
        cout << "Movie destroyed: " << title << endl;
    }

    void play()
    {
        cout << "Playing " << title << endl;
    }

    void details()
    {
        cout << title << " runs for " << duration << " minutes." << endl;
    }
};

#endif // MOVIE_H
