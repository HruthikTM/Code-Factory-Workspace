#include "Language.h"
#include <iostream>
using namespace std;

Languages::Languages() {}

Languages::Languages(int id, const string& name) : m_languageId(id), m_languageName(name)
{}

Languages::~Languages()
{
    for (auto& c : m_channelMap)
        delete c.second;
    m_channelMap.clear();
}

int Languages::getLanguageId() const
{
    return m_languageId;
}
string Languages::getLanguageName() const
{
    return m_languageName;
}

void Languages::setLanguageId(int id)
{
    m_languageId = id;
}
void Languages::setLanguageName(const string& name)
{
    m_languageName = name;
}

map<int, Channels*>& Languages::getChannelMap()
{
    return m_channelMap;
}

void Languages::addChannel(int id, const string& name, double price)
{
    if (m_channelMap.count(id))
    {
        cout << "Channel already exists.\n";
        return;
    }

    m_channelMap[id] = new Channels(id, name, price);
}

void Languages::editChannel(int id, const string& newName, double newPrice)
{
    if (!m_channelMap.count(id))
    {
        cout << "Channel not found.\n";
        return;
    }

    m_channelMap[id]->setChannelName(newName);
    m_channelMap[id]->setPrice(newPrice);
}

void Languages::deleteChannel(int id)
{
    if (!m_channelMap.count(id))
    {
        cout << "Channel not found.\n";
        return;
    }

    delete m_channelMap[id];
    m_channelMap.erase(id);
}

void Languages::displayChannels()
{
    if (m_channelMap.empty())
    {
        cout << "No channels available.\n";
        return;
    }

    for (auto& c : m_channelMap)
    {
        Channels* ch = c.second;
        cout << ch->getChannelId() << ". " << ch->getChannelName() << " (" << ch->getPrice() << ")\n";
    }
}
