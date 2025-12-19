#ifndef CHANNELS_H
#define CHANNELS_H

#include <map>
#include <string>
#include "Program.h"

using namespace std;

class Channels
{
public:
    Channels();
    Channels(int id, const string& name, double price);
    ~Channels();

    int getChannelId() const;
    string getChannelName() const;
    double getPrice() const;

    void setChannelId(int id);
    void setChannelName(const string& name);
    void setPrice(double price);

    void addProgram(int id, const string& name, const string& start, const string& end);
    void editProgram(int id, const string& newName, const string& newStart, const string& newEnd);
    void deleteProgram(int id);
    void displayPrograms();

    map<int, Programs*>& getProgramMap();

private:
    int m_channelId;
    string m_channelName;
    double m_price;

    map<int, Programs*> m_programMap;
};

#endif
