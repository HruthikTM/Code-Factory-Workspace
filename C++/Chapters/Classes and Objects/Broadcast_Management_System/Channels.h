#ifndef CHANNELS_H
#define CHANNELS_H

#include <map>
#include <string>
#include <iostream>
#include "Programs.h"
using namespace std;

class Channels
{

public:
    Channels();
    Channels(int id, string name, double price);
    ~Channels();

    int getChannelId() const;
    string getChannelName() const;
    double getPrice() const;
    void setChannelId(int id);
    void setChannelName(const string &name);
    void setPrice(double newPrice);

    void addProgram(int id, string name, string start, string end);
    void editProgram(int id, string newName, string newStart, string newEnd);
    void deleteProgram(int id);
    void clearPrograms();
    void displayPrograms();


private:
    int m_channelId;
    string m_channelName;
    double m_price;
    map<int, Programs*> m_programMap;
};


#endif // CHANNELS_H
