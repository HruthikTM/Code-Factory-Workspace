#include <iostream>

using namespace std;

class Item{
    static int count;
    int number;

public:
    void getData(int a)
    {
        number = a;
        count ++;
    }

    void getCount()
    {
        cout << "Count: " << count << endl;
    }
};

int Item :: count = 10;


int main()
{
    Item a, b, c;

    a.getCount();
    b.getCount();
    c.getCount();

    a.getData(100);
    b.getData(200);
    c.getData(300);

    a.getCount();
    b.getCount();
    c.getCount();

    return 0;
}
