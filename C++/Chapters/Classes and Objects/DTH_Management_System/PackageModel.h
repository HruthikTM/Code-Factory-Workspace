#ifndef PACKAGEMODEL_H
#define PACKAGEMODEL_H

#include <map>
#include <string>
#include <iostream>

#include "Package.h"
#include "LanguageModel.h"
#include "SqlReader.h"

using namespace std;

class PackageModel
{
public:
    PackageModel(LanguageModel* langModel);

    void createPackage();
    void editPackage(int pkgId);
    void deletePackage(int pkgId);
    void displayPackages();

    Package* getPackage(int id);
    map<int, Package*>& getPackageMap();

private:
    map<int, Package*> m_packageMap;
    LanguageModel* m_langModel;
    SqlReader* m_reader;

    int getValidatedInt();
    string getValidatedString();
};

#endif
