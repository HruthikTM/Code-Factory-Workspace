#include <iostream>

using namespace std;

class Student
{

public:
    int a;
    enum Academic
    {
        first = 1,
        second,
        third
    };

    Academic acc;
    void setAcc(Academic choice)
    {
        acc = choice;
    }
    enum Sports
    {
        First = 1,
        Second,
        Third
    } spo;
};

int main()
{

    Student s1;
    s1.setAcc();
    // s1.spo = "first";
    return 0;
}
