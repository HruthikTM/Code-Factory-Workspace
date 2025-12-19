#include "Channels.h"

Channels::Channels()
{

}

Channels::Channels(int id, string name, double price) : m_channelId(id), m_channelName(name), m_price(price)
{

}

int Channels::getChannelId() const
{
    return m_channelId;
}

string Channels::getChannelName() const
{
    return m_channelName;
}

void Channels::setChannelId(int id)
{
    m_channelId = id;
}

void Channels::setChannelName(const string &name)
{
    m_channelName = name;
}

void Channels::addProgram(int id, string name, string start, string end)
{
    if(m_programMap.find(id) != m_programMap.end())
    {
        cout << "Program ID already exists\n";
        return;
    }

    m_programMap[id] = new Programs(id, name, start, end);
    cout << "Program added successfully\n";
}

void Channels::editProgram(int id, string newName, string newStart, string newEnd)
{
    if (m_programMap.find(id) != m_programMap.end())
    {
        m_programMap[id]->setProgramName(newName);
        m_programMap[id]->setStartTime(newStart);
        m_programMap[id]->setEndTime(newEnd);
    } else
        cout << "Program not found!\n";
}

void Channels::deleteProgram(int id)
{
    auto it = m_programMap.find(id);
    if (it != m_programMap.end())
    {
        delete it->second;
        m_programMap.erase(it);
        cout << "Program deleted.\n";
    }
    else
        cout << "Program not found!\n";
}

void Channels::clearPrograms()
{
    for (auto &p : m_programMap)
    {
        delete p.second;
    }
    m_programMap.clear();
}

void Channels::displayPrograms()
{
    if (m_programMap.empty())
    {
        cout << "No programs available.\n";
        return;
    }
    for (auto &p : m_programMap)
        cout << "  ID: " << p.second->getProgramId()
             << ", Name: " << p.second->getProgramName()
             << ", Start: " << p.second->getStartTime()
             << ", End: " << p.second->getEndTime() << endl;
}

double Channels::getPrice() const
{
    return m_price;
}

void Channels::setPrice(double newPrice)
{
    m_price = newPrice;
}

Channels::~Channels()
{
    for (auto &p : m_programMap)
        delete p.second;
    m_programMap.clear();
}
