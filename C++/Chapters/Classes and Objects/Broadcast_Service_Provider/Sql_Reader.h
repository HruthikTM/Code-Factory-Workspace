#ifndef SQL_READER_H
#define SQL_READER_H

#include <iostream>
#include <map>
#include <string>
#include "FileReader.h"
#include "Channels.h"
using namespace std;

class Sql_Reader : public FileReader
{
public:
    Sql_Reader();
    ~Sql_Reader();

    void createFile() override;
    void readFile(map<int, Channels*>& m_channel, map<int, string>& languageMap, map<int, string>& categoryMap) override;

    void insertChannel(int channelId, const string& channelName, int serviceProviderId, int languageId, int categoryId) override;
    void insertProgram(int programId, const string& programTitle, const string& startTime, const string& endTime, int channelId) override;

    void updateChannel(int channelId, const string& newChannelName, int languageId, int categoryId) override;
    void updateProgram(int programId, const string& programTitle, const string& startTime, const string& endTime) override;

    void deleteChannel(int channelId) override;
    void deleteProgram(int programId) override;

    void loadLanguages(map<int, string>& languageMap) override;
    void loadCategories(map<int, string>& categoryMap) override;
    pair<int, int> getChannelLanguageCategory(int channelId) override;
};

#endif // SQL_READER_H
