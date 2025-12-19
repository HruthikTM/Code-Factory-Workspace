#include "MainDataModel.h"
#include "SqlReader.h"

MainDataModel* MainDataModel::instance = nullptr;

MainDataModel* MainDataModel::getInstance()
{
    if (instance == nullptr)
        instance = new MainDataModel();
    return instance;
}

MainDataModel::MainDataModel()
    : packageModel(&languageModel),
    customerModel(&packageModel)
{
    SqlReader::getInstance()->createFile();
}

void MainDataModel::createLanguage(int id, const std::string& name)
{
    languageModel.createLanguage(id, name);
}

void MainDataModel::deleteLanguage(int id)
{
    languageModel.deleteLanguage(id);
}

void MainDataModel::displayLanguages()
{
    languageModel.displayLanguages();
}

void MainDataModel::createChannel(int langId, int chId, const string& name, double price)
{
    languageModel.createChannel(langId, chId, name, price);
}

void MainDataModel::updateChannel(int langId, int chId, const string& name, double price)
{
    languageModel.updateChannel(langId, chId, name, price);
}

void MainDataModel::deleteChannel(int langId, int chId)
{
    languageModel.deleteChannel(langId, chId);
}

void MainDataModel::displayChannels(int langId)
{
    languageModel.displayChannels(langId);
}

void MainDataModel::createProgram(int langId, int chId, int prgId, const string& name, const string& start, const string& end)
{
    languageModel.createProgram(langId, chId, prgId, name, start, end);
}

void MainDataModel::updateProgram(int langId, int chId, int prgId, const string& name, const string& start, const string& end)
{
    languageModel.updateProgram(langId, chId, prgId, name, start, end);
}

void MainDataModel::deleteProgram(int langId, int chId, int prgId)
{
    languageModel.deleteProgram(langId, chId, prgId);
}

void MainDataModel::displayPrograms(int langId, int chId)
{
    languageModel.displayPrograms(langId, chId);
}

void MainDataModel::createPackage()
{
    packageModel.createPackage();
}

void MainDataModel::editPackage(int pkgId)
{
    packageModel.editPackage(pkgId);
}

void MainDataModel::deletePackage(int pkgId)
{
    packageModel.deletePackage(pkgId);
}

void MainDataModel::displayPackages()
{
    packageModel.displayPackages();
}

void MainDataModel::viewAvailablePackages()
{
    customerModel.displayAvailablePackages();
}

bool MainDataModel::subscribePackage(int customerId)
{
    return customerModel.selectPackage(customerId);
}

void MainDataModel::viewSubscribedPackages(int customerId)
{
    customerModel.viewSubscribedPackages(customerId);
}

void MainDataModel::viewProfile(int id)
{
    customerModel.viewProfile(id);
}

void MainDataModel::editProfile(int id)
{
    customerModel.editProfile(id);
}
