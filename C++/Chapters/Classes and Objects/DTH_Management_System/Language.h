#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <map>
#include <string>
#include "Channels.h"

using namespace std;

class Languages
{
public:
    Languages();
    Languages(int id, const string& name);
    ~Languages();

    int getLanguageId() const;
    string getLanguageName() const;

    void setLanguageId(int id);
    void setLanguageName(const string& name);

    void addChannel(int id, const string& name, double price);
    void editChannel(int id, const string& newName, double newPrice);
    void deleteChannel(int id);
    void displayChannels();

    map<int, Channels*>& getChannelMap();

private:
    int m_languageId;
    string m_languageName;

    map<int, Channels*> m_channelMap;
};

#endif
