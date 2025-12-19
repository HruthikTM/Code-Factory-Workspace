#ifndef SQLREADER_H
#define SQLREADER_H

#include "FileReader.h"
#include <sqlite3.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class SqlReader : public FileReader
{
private:
    static SqlReader* instance;
    SqlReader();

public:
    ~SqlReader();
    static SqlReader* getInstance();

    bool createFile() override;
    bool readFile(map<int, Languages*>& languageMap) override;

    bool insertLanguage(int languageId, const string& languageName) override;
    bool updateLanguage(int languageId, const string& newName) override;
    bool deleteLanguage(int languageId) override;

    bool insertChannel(int channelId, const string& channelName, const double& price, int languageId) override;
    bool updateChannel(int channelId, const string& newChannelName, const double& newPrice, int languageId) override;
    bool deleteChannel(int channelId) override;

    bool insertProgram(int programId, const string& programTitle, const string& startTime, const string& endTime, int channelId) override;
    bool updateProgram(int programId, const string& newProgramTitle, const string& newStartTime, const string& newEndTime) override;
    bool deleteProgram(int programId) override;

    bool createUserTables() override;
    bool insertUser(const string& type, int id, const string& name, const string& password, const string& phone) override;
    bool verifyUser(const string& type, int id, const string& password) override;
    bool updateUser(const string& type, int id, const string& name, const string& phone, const string& password) override;
    bool getUser(const string& type, int id) override;

    bool insertPackage(int packageId, const string& name, double price) override;
    bool insertPackageChannel(int packageId, int channelId) override;
    bool deletePackage(int packageId) override;
    bool readPackages(map<int, Package*>& packageMap, map<int, Languages*>& languageMap) override;

    bool insertCustomerPackage(int customerId, int packageId, const string& transactionRef, const string& paymentMethod) override;
    bool getCustomerPackages(int customerId) override;

    bool userExists(const string& type, const string& phone);
    bool userExists(const string& type, int id);

private:
    static int callback(void* data, int argc, char** argv, char** azColName);
    void loadChannelsAndPrograms(sqlite3* db, Languages* lang);
};

#endif // SQLREADER_H
