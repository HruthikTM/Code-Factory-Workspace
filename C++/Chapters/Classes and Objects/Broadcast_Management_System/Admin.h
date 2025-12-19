#ifndef ADMIN_H
#define ADMIN_H

#include "PersonDetails.h"
#include "Languages.h"
#include "Channels.h"
#include "Programs.h"
#include "SqlReader.h"
#include <map>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Admin : public PersonlDetails
{
    enum adminMenu
    {
        AddLanguage = 1,
        DeleteLanguage,
        DisplayLanguages,
        ManageChannels,
        ViewProfile,
        EditProfile,
        ManagePackages,
        Logout
    };

    enum channelMenu
    {
        AddChannel = 1,
        UpdateChannel,
        DeleteChannel,
        DisplayChannels,
        ManagePrograms,
        Back
    };

    enum programsMenu
    {
        AddPrograms = 1,
        UpdateProgram,
        DeleteProgram,
        DisplayPrograms,
        Return
    };

    enum packageMenu
    {
        AddPackage = 1,
        UpdatePackage,
        DeletePackage,
        DisplayPackage,
        Exit
    };

    enum selectPackage
    {
        CompletePackage = 1,
        LanguagePackage,
        CustomPackage
    };

    enum editPackageMenu
    {
        RenamePackage = 1,
        AddChannel_to_Package,
        RemoveChannel,
        BACK
    };

public:
    Admin(map<int, Languages*>& languageMap, map<int, Package*>& packageMap);
    Admin(int id, const string& name, const string& password, const string& phone, map<int, Languages*>& languageMap, map<int, Package*>& packageMap);
    ~Admin();

    void adminMenu();

private:

    void createLanguage();
    void deleteLanguage();
    void displayLanguages();

    void createChannel(int languageId);
    void updateChannel(int languageId);
    void deleteChannel(int languageId);
    void displayChannels(int languageId);

    void createProgram(int languageId, int channelId);
    void updateProgram(int languageId, int channelId);
    void deleteProgram(int languageId, int channelId);
    void displayPrograms(int languageId, int channelId);


    void managePackages();
    void createPackage(map<int, Languages*>& languageMap);
    void displayPackages();
    void editPackage();
    void deletePackage();

    void manageChannels(int languageId);
    void managePrograms(int languageId, int channelId);

    void viewProfile();
    void editProfile();

    int getValidatedInt();
    double getValidatedDouble();
    string getValidatedName();
    string getValidatedPhone();
    string getValidatedPassword();
    string getValidatedChannelName();
    bool isValidTime(const string &time);

    Languages* getLanguage(int id);
    Channels* getChannel(int languageId, int channelId);

private:
    SqlReader* m_reader;
    map<int, Languages*>& m_languageMap;
    int m_adminId;
    map<int, Package*>& m_packageMap;
};

#endif // ADMIN_H
