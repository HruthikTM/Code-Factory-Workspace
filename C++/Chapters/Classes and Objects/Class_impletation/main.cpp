#include <iostream>

using namespace std;

class Item{

    int number;
    float cost;

public:
    void getData(int a, float b);

    //Inline function
    void putData(void)
    {
        cout << "Number: " << number << endl;
        cout << "Cost: " << cost << endl;
    }
};

//Member function Defined outside the class
void Item :: getData(int a, float b)
{
    number = a;
    cost = b;
}

int main()
{
    Item x;  //Object creation

    cout << "\nObject x " << endl;
    x.getData(100, 299.95f);
    x.putData();


    Item y;  //Object creation

    cout << "\nObject y " << endl;
    y.getData(23, 78.63f);
    y.putData();

    return 0;
}
