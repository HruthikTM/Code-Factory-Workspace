#include "PackageModel.h"
#include <iostream>

using namespace std;

PackageModel::PackageModel(LanguageModel* langModel)
{
    m_langModel = langModel;
    m_reader = SqlReader::getInstance();

    m_reader->readPackages(m_packageMap, m_langModel->getLanguageMap());
}

int PackageModel::getValidatedInt()
{
    int input;
    while (!(cin >> input))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Try again: ";
    }
    return input;
}

string PackageModel::getValidatedString()
{
    string s;
    cin >> s;
    return s;
}

map<int, Package*>& PackageModel::getPackageMap()
{
    return m_packageMap;
}

Package* PackageModel::getPackage(int id)
{
    return m_packageMap.count(id) ? m_packageMap[id] : nullptr;
}

void PackageModel::displayPackages()
{
    if (m_packageMap.empty())
    {
        cout << "No packages available.\n";
        return;
    }

    cout << "\n======= PACKAGE DETAILS =======\n";

    for (auto& p : m_packageMap)
    {
        Package* pkg = p.second;

        cout << "\nPackage ID: " << pkg->getPackageId()
             << "\nName: " << pkg->getPackageName()
             << "\nTotal Price: ₹" << pkg->getTotalPrice()
             << "\nChannels:\n";

        for (auto& ch : pkg->getChannelMap())
        {
            cout << "  [" << ch.second->getChannelId() << "] " << ch.second->getChannelName() << " (" << ch.second->getPrice() << ")\n";
        }
    }
}

void PackageModel::createPackage()
{
    cout << "Enter Package ID: ";
    int pkgId = getValidatedInt();

    if (m_packageMap.count(pkgId))
    {
        cout << "Package ID already exists.\n";
        return;
    }

    cout << "Enter Package Name: ";
    string name = getValidatedString();

    Package* pkg = new Package(pkgId, name);

    while (true)
    {
        cout << "Add channel? (1=yes, 0=no): ";
        int op = getValidatedInt();
        if (!op) break;

        cout << "Enter Language ID: ";
        int langId = getValidatedInt();

        auto& lmap = m_langModel->getLanguageMap();
        if (!lmap.count(langId))
        {
            cout << "Invalid language.\n";
            continue;
        }

        cout << "Enter Channel ID: ";
        int chId = getValidatedInt();

        auto& cmap = lmap[langId]->getChannelMap();
        if (!cmap.count(chId))
        {
            cout << "Invalid channel.\n";
            continue;
        }

        pkg->addChannel(cmap[chId]);
    }

    pkg->calculateTotalPrice();

    m_packageMap[pkgId] = pkg;

    if (!m_reader->insertPackage(pkgId, name, pkg->getTotalPrice()))
    {
        cout << "Failed to insert package into database.\n";
    }
    else
    {
        for (auto& chPair : pkg->getChannelMap())
        {
            int chId = chPair.second->getChannelId();
            m_reader->insertPackageChannel(pkgId, chId);
        }
    }

    cout << "Package created.\n";
}

void PackageModel::editPackage(int pkgId)
{
    if (!m_packageMap.count(pkgId))
    {
        cout << "Package not found.\n";
        return;
    }

    Package* pkg = m_packageMap[pkgId];

    cout << "\n1. Rename Package\n";
    cout << "2. Add Channel\n";
    cout << "3. Remove Channel\n";
    cout << "Choice: ";

    int choice = getValidatedInt();

    if (choice == 1)
    {
        cout << "New Name: ";
        string name = getValidatedString();
        pkg->setPackageName(name);

        if (!m_reader->updatePackage(pkgId, name))
            cout << "Failed to update package name in database.\n";
    }
    else if (choice == 2)
    {
        cout << "Language ID: ";
        int langId = getValidatedInt();

        auto& lmap = m_langModel->getLanguageMap();
        if (!lmap.count(langId))
        {
            cout << "Invalid language.\n";
            return;
        }

        cout << "Channel ID: ";
        int chId = getValidatedInt();

        auto& cmap = lmap[langId]->getChannelMap();
        if (!cmap.count(chId))
        {
            cout << "Invalid channel.\n";
            return;
        }

        pkg->addChannel(cmap[chId]);
        pkg->calculateTotalPrice();

        if (!m_reader->insertPackageChannel(pkgId, chId))
            cout << "Failed to insert package channel into database.\n";

        if (!m_reader->updatePackagePrice(pkgId, pkg->getTotalPrice()))
            cout << "Failed to update package price in database.\n";
    }
    else if (choice == 3)
    {
        cout << "Channel ID: ";
        int chId = getValidatedInt();

        pkg->removeChannel(chId);
        pkg->calculateTotalPrice();

        if (!m_reader->removePackageChannel(pkgId, chId))
            cout << "Failed to remove package channel from database.\n";

        if (!m_reader->updatePackagePrice(pkgId, pkg->getTotalPrice()))
            cout << "Failed to update package price in database.\n";
    }

    cout << "Package updated.\n";
}

void PackageModel::deletePackage(int pkgId)
{
    if (!m_packageMap.count(pkgId))
    {
        cout << "Package not found.\n";
        return;
    }

    delete m_packageMap[pkgId];
    m_packageMap.erase(pkgId);

    if (!m_reader->deletePackage(pkgId))
    {
        cout << "Failed to delete package from database.\n";
    }

    cout << "Package deleted.\n";
}
