#ifndef SERVICE_PROVIDER_H
#define SERVICE_PROVIDER_H

#include <iostream>
#include <map>
#include "FileReader.h"
#include "Sql_Reader.h"
#include "Channels.h"
using namespace std;

class ServiceProvider
{
public:
    ServiceProvider();
    ~ServiceProvider();

    int createChannel();
    void updateChannel(int channelId, const string& newChannelName, int languageId, int categoryId);
    void deleteChannel(int channelId);
    void display();

    int getServiceProviderId() const;
    void setupChannels();
    bool isChannelIdPresent(int newchannelId);
    bool isValidTime(const string &time);

    void validateChannelId(int& channelId);
    void validateProgramId(int& programId);
    Channels* getChannel(int channelId);

    void managePrograms(Channels* channel);
    void createProgram(Channels* channel);
    void updateProgram(Channels* channel);
    void deleteProgram(Channels* channel);


private:
    int m_serviceProviderId;
    string m_serviceProviderName;

    map<int, Channels*> m_channel;
    map<int, string> m_languageMap;
    map<int, string> m_categoryMap;

    FileReader* m_reader;

    void displayLanguages();
    void displayCategories();
    int selectLanguage();
    int selectCategory();

    enum ChannelOperationMenu
    {
        CREATE = 1,
        UPDATE,
        DELETE,
        ManagePrograms,
        DISPLAY,
        EXIT
    };
};

#endif // SERVICE_PROVIDER_H
