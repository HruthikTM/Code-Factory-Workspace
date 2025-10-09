#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string>

using namespace std;


class Train
{
    string number;
    int coaches;

public:
    Train(string n, int c){

        number = n;
        coaches = c;
        cout << "Train created: " << number << endl;
    }

    ~Train()
    {
        cout << "Train destroyed: " << number << endl;
    }

    void depart()
    {
        cout << "Train " << number << " departed " << endl;
    }

    void arrive()
    {
        cout << "Train " << number << " arrived " << endl;
    }
};


#endif // TRAIN_H
