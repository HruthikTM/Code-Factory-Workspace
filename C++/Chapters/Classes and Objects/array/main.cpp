#include <iostream>

using namespace std;

class T
{
public:
    int p[3];
    T(){}
    T(int *ptr)
    {
        cout<<"parametarized"<<endl;
        //p=new int[5];
        // for(int i=0;i<3;i++)
        // {
        //     p[i]=ptr[i];
        // }
    }
};
int v[3] = {1,2,3};
int main()
{

    int t2;
    T t;
    t=(int *)v;
    // cout << t << endl;
    return 0;
}
