#include <iostream>

using namespace std;

int func(int a)
{
    return a;
}

float func(float a)
{
    return a;
}


int main()
{

    func(10);
    func(2.2f);

    cout << "Hello World!" << endl;

    return 0;
}
