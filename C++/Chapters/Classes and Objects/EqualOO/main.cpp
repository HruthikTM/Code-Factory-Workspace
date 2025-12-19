#include <iostream>

using namespace std;

// class Channel
// {
// public:
//     int channelId1;
//     int channelId2;
//     ///string channelName;


// public :
//     // void operator = (const Channel *ch1)
//     // {
//     //     //this->channelId = ch1->channelId;
//     //     cout << "Operator overloading" << endl;
//     //     *this = ch1;
//     // }

//     Channel ()
//     {

//     }

//     Channel(int c1, int c2) : channelId1(c1) , channelId2(c2)
//     {

//     }

//     Channel &operator + (const Channel& other)
//     {
//         Channel *temp = new Channel;
//         temp->channelId1 = this->channelId1 + other.channelId1;
//         temp->channelId2 = this->channelId2 + other.channelId2;
//         return *temp;
//     }

//     // Channel (const Channel &copy)
//     // {
//     //     cout << "Copy constructor" << endl;
//     // }
//     int getChannelId1() const;
//     void setChannelId1(int newChannelId1);
// };


static void run()
{
    cout << "Iam static member" << endl;
}

int main()
{
    // Channel obj1(10,20);
    // Channel obj2(30,40);

    // Channel obj3 = obj1 + obj2;

    // cout << obj3.channelId1 << ", " << obj3.channelId2 << endl;

    // Channel c1(10,"etv");
    // Channel c2 ;
    //  c2 = c1;

    // cout << &c1 << endl;
    // cout << &c2 << endl;

    cout << "I am main method" << endl;



    // cout << c2.channelId << ","  << c2.channelName << endl;

    // cout << &c1 << endl;
    // cout << &c2 << endl;


}

// int Channel::getChannelId1() const
// {
//     return channelId1;
// }

// void Channel::setChannelId1(int newChannelId1)
// {
//     channelId1 = newChannelId1;
// }
