#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Channels;

class FileReader
{
public:
    FileReader();
    virtual ~FileReader();

    virtual void createFile() = 0;

    virtual void readFile(map<int, Channels*>& m_channel, map<int, string>& languageMap, map<int, string>& categoryMap) = 0;

    virtual void insertChannel(int channelId, const string& channelName, int serviceProviderId, int languageId, int categoryId) = 0;

    virtual void insertProgram(int programId, const string& programTitle, const string& startTime, const string& endTime, int channelId) = 0;

    virtual void updateChannel(int channelId, const string& newChannelName, int languageId, int categoryId) = 0;

    virtual void updateProgram(int programId, const string& programTitle, const string& startTime, const string& endTime) = 0;

    virtual void deleteChannel(int channelId) = 0;
    virtual void deleteProgram(int programId) = 0;

    virtual void loadLanguages(map<int, string>& languageMap) = 0;
    virtual void loadCategories(map<int, string>& categoryMap) = 0;
    virtual pair<int, int> getChannelLanguageCategory(int channelId) = 0;
};

#endif // FILEREADER_H
