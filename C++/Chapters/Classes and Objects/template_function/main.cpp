#include <iostream>

using namespace std;

// template<typename T1>
template<typename T1,typename T2>
T1 add(T1 a, T2 b)
{
    return a + b;
}

int main()
{
    // cout << "Sum: " << add(5,5) << endl;
    cout << "Sum: " << add(3.3f,5) << endl;
}
