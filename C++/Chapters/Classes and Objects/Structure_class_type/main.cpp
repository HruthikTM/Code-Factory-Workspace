
#include <iostream>

using namespace std;

//using structure

struct Bike
{
    // struct fff{
    //     int a;
    //     int b;
    // };

    private :
    float cc;
    string brand;

        //virtual void run() =0;


    public:
        void getData(void);
        void putData(void);
};

void Bike :: getData(void)
{
    cout << "Enter CC: ";
    cin >> cc;
    cout << "Enter Brand: ";
    cin >> brand;
}

void Bike :: putData(void)
{
    cout << "\nCC: " << cc;
    cout << "\nBrand: " << brand;
}

int main()
{

    Bike b;
    b.getData();
    b.putData();
    return 0;
}


//using Class

// class Bike
// {

// float cc;
// string brand;


// public:
//     void getData(void);
//     void putData(void);
// };

// void Bike :: getData(void)
// {
//     cout << "Enter CC: ";
//     cin >> cc;
//     cout << "Enter Brand: ";
//     cin >> brand;
// }

// void Bike :: putData(void)
// {
//     cout << "\nCC: " << cc;
//     cout << "\nBrand: " << brand;
// }

// int main()
// {

//     Bike b;
//     b.getData();
//     b.putData();
//     return 0;
// }
