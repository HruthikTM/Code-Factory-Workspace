#include "Channels.h"
#include <iostream>
using namespace std;

Channels::Channels() {}

Channels::Channels(int id, const string& name, double price) : m_channelId(id), m_channelName(name), m_price(price)
{}

Channels::~Channels()
{
    for (auto& p : m_programMap)
        delete p.second;
    m_programMap.clear();
}

int Channels::getChannelId() const { return m_channelId; }
string Channels::getChannelName() const { return m_channelName; }
double Channels::getPrice() const { return m_price; }

void Channels::setChannelId(int id) { m_channelId = id; }
void Channels::setChannelName(const string& name) { m_channelName = name; }
void Channels::setPrice(double price) { m_price = price; }

map<int, Programs*>& Channels::getProgramMap()
{
    return m_programMap;
}

void Channels::addProgram(int id, const string& name, const string& start, const string& end)
{
    if (m_programMap.count(id))
    {
        cout << "Program ID exists.\n";
        return;
    }
    m_programMap[id] = new Programs(id, name, start, end);
}

void Channels::editProgram(int id, const string& newName, const string& newStart, const string& newEnd)
{
    if (!m_programMap.count(id))
    {
        cout << "Program not found.\n";
        return;
    }

    m_programMap[id]->setProgramName(newName);
    m_programMap[id]->setStartTime(newStart);
    m_programMap[id]->setEndTime(newEnd);
}

void Channels::deleteProgram(int id)
{
    if (!m_programMap.count(id))
        return;

    delete m_programMap[id];
    m_programMap.erase(id);
}

void Channels::displayPrograms()
{
    if (m_programMap.empty())
    {
        cout << "No programs available.\n";
        return;
    }

    for (auto& p : m_programMap)
    {
        Programs* pr = p.second;
        cout << pr->getProgramId() << ". " << pr->getProgramName() << " (" << pr->getStartTime() << " - " << pr->getEndTime() << ")\n";
    }
}

//count-->find
