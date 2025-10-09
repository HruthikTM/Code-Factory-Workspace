#include <iostream>

using namespace std;

// int main()
// {
//     int i=0;
//     i =i + 1;
//     cout<< i << " ";
//     cout<<i;
//     return 0;
// }


// int main()
// {
//     short i=2500, j=3000;
//     //cout>> "i + j =" >> -(i+j);
//     //cout<< "i + j =" << -(i+j); //correct form
//     return 0;
// }

int main()
{
    int i = 10, j = 5;

    int modResult;
    int divResult;

    modResult = i%j;
    cout<< modResult<<endl;

    modResult = 2;
    divResult = i/modResult;
    cout<< divResult<<endl;

    return 0;
}
