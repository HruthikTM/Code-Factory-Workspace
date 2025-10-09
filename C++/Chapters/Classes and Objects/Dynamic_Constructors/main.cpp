#include <iostream>
#include <string>
using namespace std;

class Data
{
    string name;

public:
    Data()
    {
        name = "";
    }

    Data(string n)
    {
        name = n;
    }

    void display()
    {
        cout << name << endl;
    }

    void join(Data &a, Data &b)
    {
        name = a.name + b.name;
    }
};

int main()
{
    string first = "hruthik ";
    Data name1(first), name2("T "), name3("M "), d1, d2;

    d1.join(name1, name2);
    d2.join(d1, name3);

    name1.display();
    name2.display();
    name3.display();
    d1.display();
    d2.display();

    return 0;
}
