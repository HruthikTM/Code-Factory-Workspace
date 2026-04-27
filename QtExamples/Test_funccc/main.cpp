#include <iostream>

using namespace std;

// void add1(int a, int b, int sum)
// {
//     sum = a + b;
//     cout << sum;
// }

// void add2(int *a, int *b, int *sum)
// {
//     *sum = *a + *b;
//     cout << *sum;
// }

// void add3(int &a, int &b, int &sum)
// {
//     sum = a + b;
//     cout << sum;
// }


int &add()
{
    int k=20;
    cout<<"vlaue of k"<<k;
    return k;
}

int main()
{
    int x = 10;
    // int y = 20;
    // int sum;
    // add1(x,y,sum);
    // cout << sum;
    // add2(&x,&y,&sum);
    // cout << sum;
    // add3(x,y,sum);
    // cout << sum;
    add()=x;
    cout<<"hi"<<endl;
    add();
    return 0;
}
