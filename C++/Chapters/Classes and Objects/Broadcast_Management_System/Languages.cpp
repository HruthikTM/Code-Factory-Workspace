#include "Languages.h"

Languages::Languages() {}
Languages::Languages(int id, string name) : m_languageId(id), m_languageName(name) {}

Languages::~Languages()
{
    for (auto &c : m_channelMap)
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

void Languages::setLanguageName(const string &name)
{
    m_languageName = name;
}

void Languages::addChannel(int id, string name, double price)
{
    if (m_channelMap.find(id) != m_channelMap.end())
    {
        cout << "Channel ID already exists\n";
        return;
    }
    m_channelMap[id] = new Channels(id, name, price);
    cout << "Channel added successfully\n";
}

void Languages::editChannel(int id, string newName, double newPrice)
{
    auto it = m_channelMap.find(id);
    if (it != m_channelMap.end())
    {
        it->second->setChannelName(newName);
        it->second->setPrice(newPrice);
        cout << "Channel updated successfully\n";
    }
    else
        cout << "Channel not found!\n";
}

void Languages::deleteChannel(int id)
{
    auto it = m_channelMap.find(id);
    if (it != m_channelMap.end())
    {
        delete it->second;
        m_channelMap.erase(it);
        cout << "Channel deleted.\n";
    }
    else
        cout << "Channel not found!\n";
}

void Languages::displayChannels()
{
    if (m_channelMap.empty())
    {
        cout << "No channels available.\n";
        return;
    }

    cout << "\nChannels:\n";
    for (auto &c : m_channelMap)
    {
        cout << "  ID: " << c.second->getChannelId()
            << ", Name: " << c.second->getChannelName()
            << ", Price: " << c.second->getPrice() << endl;
    }
}


map<int, Channels*>& Languages::getChannelMap() {
    return m_channelMap;
}
