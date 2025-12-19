#ifndef MAINDATAMODEL_H
#define MAINDATAMODEL_H

#include <string>
#include "AdminModel.h"
#include "CustomerModel.h"
#include "LanguageModel.h"
#include "PackageModel.h"

using namespace std;

class MainDataModel
{
public:

    static MainDataModel* getInstance();


    void createLanguage(int id, const string& name);
    void deleteLanguage(int id);
    void displayLanguages();

    void createChannel(int langId, int chId, const string& name, double price);
    void updateChannel(int langId, int chId, const string& name, double price);
    void deleteChannel(int langId, int chId);
    void displayChannels(int langId);

    void createProgram(int langId, int chId, int prgId, const string& name, const string& start, const string& end);
    void updateProgram(int langId, int chId, int prgId, const string& name, const string& start, const string& end);
    void deleteProgram(int langId, int chId, int prgId);
    void displayPrograms(int langId, int chId);

    void createPackage();
    void editPackage(int pkgId);
    void deletePackage(int pkgId);
    void displayPackages();

    void viewAvailablePackages();
    bool subscribePackage(int customerId);
    void viewSubscribedPackages(int customerId);

    void viewProfile(int id);
    void editProfile(int id);


    LanguageModel* getLanguageModel() { return &languageModel; }
    PackageModel* getPackageModel() { return &packageModel; }
    CustomerModel* getCustomerModel() { return &customerModel; }
    AdminModel* getAdminModel() { return &adminModel; }

private:
    MainDataModel();
    static MainDataModel* instance;


    MainDataModel(const MainDataModel&) = delete;
    MainDataModel& operator=(const MainDataModel&) = delete;


    LanguageModel languageModel;
    PackageModel packageModel;
    CustomerModel customerModel;
    AdminModel adminModel;
};

#endif
