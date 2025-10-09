#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>

using namespace std;


class Library
{
    string name;
    int books;

public:
    Library(string n, int b)
    {
        name = n;
        books = b;

        cout << "Library created: " << name << endl;
    }

    ~Library()
    {
        cout << "Library destroyed: " << name << endl;
    }

    void borrow()
    {
        cout << "Book borrowed." << endl;
    }

    void status()
    {
        cout << "Books available: " << books << endl;
    }
};


#endif // LIBRARY_H
