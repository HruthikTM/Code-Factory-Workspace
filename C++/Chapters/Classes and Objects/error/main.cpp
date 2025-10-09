#include <iostream>

using namespace std;

// class Addition{
//     int p,q;

//     void input()
//     {
//         cout << "Enter 2 numbers ";
//         cin>>p>>q;
//     }

//     void show()
//     {
//         cout << "Addition is: " << add() << endl;
//     }

//     int add()
//     {
//         int s = p + q;
//         return (s);
//     }


// };

// class stm{
//     static int a;
//     int number;
// public:
//     void increment(int b)
//     {
//         number = b;
//         a++;
//     }

//     void show()
//     {
//         cout << a << endl;
//     }
// };

//int stm :: a;

class weight{
    int leter,ml;

public:
    void getData();
    void putData();
    void sum_of_weight(weight,weight);
};

void weight :: getData()
{
    cout<<"in letter";
    cin>>leter;
    cout<<"in ml";
    cin>>ml;
}

void weight :: putData()
{
    cout<<leter<<"Leter and "<<ml<<"ML";
}

void weight :: sum_of_weight(weight w1,weight w2)
{
    ml = w1.ml + w2.ml;
    leter = ml/1000;
    ml=ml%1000;
    leter+=w1.leter + w2.leter;
}

int main()
{
    // Addition x;
    // x.input();
    // x.add();
    // x.show();

    // stm s1,s2,s3;
    // s1.increment(10);
    // s1.show();
    // s2.show();
    // s3.show();

    weight w1,w2,w3;

    cout<<"Enter the weights \n";
    cout << "Enter weight 1";
    w1.getData();
    cout << "Enter weight 2";
    w2.getData();


    return 0;
}
