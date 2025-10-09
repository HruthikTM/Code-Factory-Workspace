#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book
{

    string title;
    string author;
    int pages;

public:

    Book(string t, string a, int p)
    {
        title = t;
        author = a;
        pages = p;

        cout << "book object created " << endl;
    }

    ~Book()
    {
        cout << "book object destroyed " << endl;
    }


    void read()
    {
        cout << "Reading " << title << endl;
    }

    void info()
    {
        cout << title << " by" << author << "," << pages << "pages." << endl;
    }


};

#endif // BOOK_H
