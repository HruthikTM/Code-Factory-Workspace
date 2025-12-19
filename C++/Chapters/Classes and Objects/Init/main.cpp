#include <iostream>

using namespace std;

class Test
{
public:
    const static int a = 10;
};

//int Test::a = 0;


int main()
{
    cout << "Hello World!" << endl;
    //Test::a++;
    cout << Test::a;

    return 0;
}
