#include "Package.h"

Package::Package(int id, const string& name) : m_packageId(id), m_packageName(name), m_totalPrice(0.0) {}

Package::~Package() {}

int Package::getPackageId() const
{
    return m_packageId;
}

string Package::getPackageName() const
{
    return m_packageName;
}

void Package::setPackageName(const string &newPackageName)
{
    m_packageName = newPackageName;
}

double Package::getTotalPrice() const
{
    return m_totalPrice;
}

void Package::setTotalPrice(double newTotalPrice)
{
    m_totalPrice = newTotalPrice;
}

map<int, Channels*> Package::getChannelMap() const
{
    return m_channelMap;
}

void Package::addChannel(Channels* channel)
{
    if (m_channelMap.find(channel->getChannelId()) == m_channelMap.end())
    {
        m_channelMap[channel->getChannelId()] = channel;
        m_totalPrice += channel->getPrice();
    }
}

void Package::removeChannel(int channelId)
{
    auto it = m_channelMap.find(channelId);
    if (it != m_channelMap.end())
    {
        m_totalPrice -= it->second->getPrice();
        m_channelMap.erase(it);
    }
}

double Package::calculateTotalPrice()
{
    m_totalPrice = 0;
    for (auto &chPair : m_channelMap)
        m_totalPrice += chPair.second->getPrice();
    return m_totalPrice;
}
