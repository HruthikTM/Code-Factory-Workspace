#include <iostream>
#include <Subscript.h>

using namespace std;

int main()
{
    int x[5] = {1,2,3,4,5};
    Subscript A(x);
    for (int i = 0; i < 5; ++i)
    {
        cout << A[i] << endl;
    }
    return 0;
}
