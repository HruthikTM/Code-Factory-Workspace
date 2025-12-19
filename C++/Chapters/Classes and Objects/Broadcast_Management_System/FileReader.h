#ifndef FILEREADER_H
#define FILEREADER_H

#include <map>
#include <string>
#include "Languages.h"
#include "Channels.h"
#include "Programs.h"
#include "Package.h"

using namespace std;

class FileReader
{
public:
    FileReader();
    virtual ~FileReader();

    virtual bool createFile() = 0;

    virtual bool readFile(map<int, Languages*>& languageMap) = 0;

    virtual bool insertLanguage(int languageId, const string& languageName) = 0;
    virtual bool updateLanguage(int languageId, const string& newName) = 0;
    virtual bool deleteLanguage(int languageId) = 0;

    virtual bool insertChannel(int channelId, const string& channelName,const double& price, int languageId) = 0;
    virtual bool updateChannel(int channelId, const string& newChannelName,const double& newPrice, int languageId) = 0;
    virtual bool deleteChannel(int channelId) = 0;

    virtual bool insertProgram(int programId, const string& programTitle, const string& startTime, const string& endTime, int channelId) = 0;
    virtual bool updateProgram(int programId, const string& newProgramTitle, const string& newStartTime, const string& newEndTime) = 0;
    virtual bool deleteProgram(int programId) = 0;

    virtual bool createUserTables() = 0;
    virtual bool insertUser(const string& type, int id, const string& name, const string& password, const string& phone) = 0 ;
    virtual bool verifyUser(const string& type, int id, const string& password) = 0;
    virtual bool updateUser(const string& type, int id, const string& name, const string& phone, const string& password) = 0;
    virtual bool getUser(const string& type, int id) = 0;

    virtual bool insertPackage(int packageId, const string& name, double price) = 0;
    virtual bool insertPackageChannel(int packageId, int channelId) = 0;
    virtual bool deletePackage(int packageId) = 0;
    virtual bool readPackages(map<int, Package*>& packageMap, map<int, Languages*>& languageMap) = 0;

    virtual  bool insertCustomerPackage(int customerId, int packageId, const string& transactionRef, const string& paymentMethod) = 0;
    virtual bool getCustomerPackages(int customerId) = 0;

    virtual bool userExists(const string& type, const string& phone) = 0;
    virtual bool userExists(const string& type, int id) = 0;
};

#endif // FILEREADER_H
