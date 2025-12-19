#pragma once

#include <sqlite3.h>
#include <map>
#include <string>
#include "Language.h"
#include "Package.h"

using std::map;
using std::string;

class SqlReader
{
private:
    static SqlReader* instance;
    SqlReader();
public:
    ~SqlReader();
    static SqlReader* getInstance();

    static int callback(void*, int, char**, char**);

    bool createFile();
    bool readFile(map<int, Languages*>& languageMap);
    void loadChannelsAndPrograms(sqlite3* db, Languages* lang);

    bool insertLanguage(int languageId, const string& languageName);
    bool updateLanguage(int languageId, const string& newName);
    bool deleteLanguage(int languageId);

    bool insertChannel(int channelId, const string& channelName, const double& price, int languageId);
    bool updateChannel(int channelId, const string& newChannelName, const double& newPrice, int languageId);
    bool deleteChannel(int channelId);

    bool insertProgram(int programId, const string& programTitle, const string& startTime,
                       const string& endTime, int channelId);
    bool updateProgram(int programId, const string& newProgramTitle, const string& newStartTime, const string& newEndTime);
    bool deleteProgram(int programId);

    bool insertPackage(int packageId, const string& name, double price);
    bool insertPackageChannel(int packageId, int channelId);
    bool deletePackage(int packageId);
    bool readPackages(map<int, Package*>& packageMap, map<int, Languages*>& languageMap);

    bool updatePackage(int packageId, const string& newName);
    bool removePackageChannel(int packageId, int channelId);
    bool updatePackagePrice(int packageId, double newPrice);

    bool createUserTables();
    bool insertUser(const string& type, int id, const string& name, const string& password, const string& phone);
    bool verifyUser(const string& type, int id, const string& password);
    bool updateUser(const string& type, int id, const string& name, const string& phone, const string& password);
    bool userExists(const string& type, const string& phone);
    bool userExists(const string& type, int id);
    bool getUser(const string& type, int id);
    bool getUser(const string& type, int id, int& outId, string& outName, string& outPassword, string& outPhone);

    bool insertCustomerPackage(int customerId, int packageId, const string& transactionRef, const string& paymentMethod);
    bool getCustomerPackages(int customerId);
};

