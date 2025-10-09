#include <iostream>

using namespace std;


class Person
{
    char name[10];
    int age;

public:
    void getData();
    void display();
};

void Person :: getData()
{
    cout<< "Enter name: ";
    cin>>name;
    cout<< "Enter age: ";
    cin>>age;
}

void Person :: display()
{
    cout<< "\nName: "<<name;
    cout<< "\nAge: "<<age;
}

int main()
{
    Person p;
    p.getData();
    p.display();

    return 0;
}
