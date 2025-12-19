#include "Package.h"
#include <iostream>
using namespace std;

Package::Package() : m_totalPrice(0) {}

Package::Package(int id, const string& name) : m_packageId(id), m_packageName(name), m_totalPrice(0)
{}

int Package::getPackageId() const
{
    return m_packageId;
}

string Package::getPackageName() const
{
    return m_packageName;
}

double Package::getTotalPrice() const
{
    return m_totalPrice;
}

void Package::setPackageId(int id)
{
    m_packageId = id;
}

void Package::setPackageName(const string& name)
{
    m_packageName = name;
}

map<int, Channels*>& Package::getChannelMap()
{
    return m_channelMap;
}

void Package::addChannel(Channels* ch)
{
    int id = ch->getChannelId();
    m_channelMap[id] = ch;
}

void Package::removeChannel(int id)
{
    if (m_channelMap.count(id))
        m_channelMap.erase(id);
}

void Package::calculateTotalPrice()
{
    m_totalPrice = 0;
    for (auto& c : m_channelMap)
        m_totalPrice += c.second->getPrice();
}

void Package::setTotalPrice(double newTotalPrice)
{
    m_totalPrice = newTotalPrice;
}
