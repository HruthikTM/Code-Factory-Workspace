#include <iostream>

using namespace std;

int area(int);
int area(int,int);
float area(float);

int main()
{
    cout << "area of rectangle" << area(5) << endl;
    cout << "area of rectangle" << area(4,5) << endl;
    cout << "area of circle" << area(5.5f) << endl;
    return 0;
}

int area(int side)
{
    return (side*side);
}

int area(int length, int breadth)
{
    return (length*breadth);
}

float area(float radius)
{
    return (3.14 * radius * radius);
}
