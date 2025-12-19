#ifndef CHANNELS_H
#define CHANNELS_H

#include <iostream>
#include <map>
#include "Programs.h"
#include "Sql_Reader.h"
using namespace std;

class Channels
{
public:
    Channels();
    Channels(int channelId, const string& channelName);
    ~Channels();

    int getChannelId();
    string getChannelName();

    void setChannelId(const int& id);
    void setChannelName(const string& name);

    void createProgram(int programId, const string& programTitle, const string& startTime, const string& endTime, FileReader *m_reader = nullptr);

    void updateProgram(int programId, const string& programTitle, const string& startTime, const string& endTime, FileReader *m_reader = nullptr);

    void deleteProgram(int programId, FileReader *m_reader = nullptr);

    bool isProgramIdPresent(int programId);
    void displayAllPrograms();

    void displayChannels(int languageId, int categoryId, const map<int, string>& languageMap, const map<int, string>& categoryMap);
    void channelsList(int languageId, int categoryId,const map<int, string>& languageMap, const map<int, string>& categoryMap);

    Programs* getProgram(int programId);

private:
    int m_channelId;
    string m_channelName;
    map<int, Programs*> m_program;
};

#endif // CHANNELS_H
