#include "Admin.h"

Admin::Admin(map<int, Languages*>& languageMap, map<int, Package*>& packageMap) : m_reader(SqlReader::getInstance()), m_languageMap(languageMap), m_packageMap(packageMap) {}

Admin::Admin(int id, const string& name, const string& password, const string& phone, map<int, Languages*>& languageMap, map<int, Package*>& packageMap) : m_reader(SqlReader::getInstance()), m_languageMap(languageMap), m_packageMap(packageMap)
{
    setId(id);
    setName(name);
    setPassword(password);
    setPhoneNumber(phone);
}

Admin::~Admin() {}

int Admin :: getValidatedInt()
{
    int value;
    while (true)
    {
        cin >> value;

        if (!cin.fail())
        {
            cin.ignore(1000,'\n');
            return value;
        }
        else
        {
            cin.clear();
            while(getchar() != '\n');
            cout << "Invalid input.\n";
        }
    }
}

double Admin :: getValidatedDouble()
{
    double value;
    while (true)
    {
        cin >> value;

        if (!cin.fail())
            return value;

        cout << "Invalid input!, Enter Numeric Value only.\n";
    }
}

string Admin::getValidatedName()
{
    string input;
    while (true)
    {
        getline(cin, input);

        bool valid = true;
        for (char c : input)
        {
            if (!isalpha(c) && c != ' ')
            {
                valid = false;
                break;
            }
        }

        if (valid)
            return input;

        cout << "Invalid name! Enter alphabets only.\n";
    }
}

string Admin::getValidatedPhone()
{
    string input;
    while (true)
    {
        cin >> input;

        bool valid = true;
        if (input.size() != 10)
            valid = false;
        else
        {
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    valid = false;
                    break;
                }
            }
        }

        if (valid)
            return input;

        cout << "Invalid phone number! Enter 10 digits only.\n";
    }
}

string Admin :: getValidatedPassword()
{
    string password;
    while (true)
    {
        cin >> password;
        if (password.size() >= 4)
            return password;
        cout << "Password must have min. 4 characters.\n";
    }
}

string Admin :: getValidatedChannelName()
{
    string input;

    while(true)
    {
        getline(cin, input);

        bool valid = true;
        for (char c : input)
        {
            if (!isalnum(c) && c != ' ')
            {
                valid = false;
                break;
            }
        }

        if (valid)
            return input;

        cout << "Invalid name! Enter alpha-numeric value only.\n";
    }
}


void Admin::adminMenu()
{
    int choice;
    while (true)
    {
        cout << "\n=========== ADMIN DASHBOARD ===========\n";
        cout << "1. Add Language\n"
                "2. Delete Language\n"
                "3. Display Languages\n"
                "4. Manage Channels\n"
                "5. View Profile\n"
                "6. Edit Profile\n"
                "7. Manage Packages\n"
                "8. Exit\n";

        cout << "Enter Choice: ";
        choice = getValidatedInt();

        switch (choice)
        {
        case AddLanguage:
            createLanguage();
            break;
        case DeleteLanguage:
            deleteLanguage();
            break;
        case DisplayLanguages:
            displayLanguages();
            break;
        case ManageChannels:
        {
            cout << "Enter Language ID: ";
            int langId = getValidatedInt();
            if (getLanguage(langId))
                manageChannels(langId);
            else
                cout << "Language not found.\n";
            break;
        }
        case ViewProfile:
            viewProfile();
            break;
        case EditProfile:
            editProfile();
            break;
        case ManagePackages:
            managePackages();
            break;
        case Logout:
            cout << "Logging out...\n";
            return;
        default:
            cout << "Invalid choice.\n";
        }
    }
}

void Admin::viewProfile()
{
    cout << "Enter your Admin ID: ";
    int id = getValidatedInt();
    m_reader->getUser("admin", id);
}

void Admin::editProfile()
{
    cout << "Enter your Admin ID: ";
    int id = getValidatedInt();

    cout << "Enter new Name: ";
    string name = getValidatedName();

    cout << "Enter new Phone: ";
    string phone = getValidatedPhone();

    cout << "Enter new Password: ";
    string password = getValidatedPassword();

    if (m_reader->updateUser("admin", id, name, phone, password))
        cout << "Profile updated successfully!\n";
    else
        cout << "Failed to update profile.\n";
}

bool Admin::isValidTime(const string &time)
{
    if (time.size() != 5 || time[2] != ':')
        return false;
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return (h >= 0 && h < 24 && m >= 0 && m < 60);
}

void Admin::createLanguage()
{
    cout << "Enter Language ID: ";
    int id = getValidatedInt();

    cout << "Enter Language Name: ";
    string name = getValidatedName();

    if (m_languageMap.find(id) != m_languageMap.end())
    {
        cout << "Language already exists\n";
        return;
    }

    Languages* newLang = new Languages(id, name);
    m_languageMap[id] = newLang;

    if (m_reader->insertLanguage(id, name))
        cout << "Language added successfully\n";
    else
        cout << "Failed to add language\n";
}

void Admin::deleteLanguage()
{
    cout << "Enter Language ID to delete: ";
    int id = getValidatedInt();

    auto it = m_languageMap.find(id);
    if (it == m_languageMap.end())
    {
        cout << "Language not found\n";
        return;
    }

    if (m_reader->deleteLanguage(id))
    {
        delete it->second;
        m_languageMap.erase(it);
        cout << "Language deleted\n";
    }
    else
        cout << "Deletion failed\n";
}

void Admin::displayLanguages()
{
    if (m_languageMap.empty())
    {
        cout << "No languages.\n";
        return;
    }
    cout << "\nLanguages:\n";
    for (auto &l : m_languageMap)
        cout << l.first << " - " << l.second->getLanguageName() << endl;
}

Languages* Admin::getLanguage(int id)
{
    auto it = m_languageMap.find(id);
    if(it != m_languageMap.end())
        return it->second;
    else
        return nullptr;
}

Channels* Admin::getChannel(int languageId, int channelId)
{
    auto lang = getLanguage(languageId);
    if (!lang) return nullptr;

    auto &chMap = lang->getChannelMap();
    auto it = chMap.find(channelId);
    if(it != chMap.end())
        return it->second;
    else
        return nullptr;
}

void Admin::manageChannels(int languageId)
{
    int choice;
    while (true)
    {
        auto lang = getLanguage(languageId);
        if (!lang)
        {
            cout << "Language not found.\n";
            return;
        }

        cout << "\n===== MANAGE CHANNELS for " << lang->getLanguageName() << " =====\n";
        cout << "1. Add Channel\n"
                "2. Edit Channel\n"
                "3. Delete Channel\n"
                "4. Display Channels\n"
                "5. Manage Programs\n"
                "6. Back\n";

        cout << "Enter choice: ";
        choice = getValidatedInt();

        switch (choice)
        {
        case AddChannel:
            createChannel(languageId);
            break;
        case UpdateChannel:
            updateChannel(languageId);
            break;
        case DeleteChannel:
            deleteChannel(languageId);
            break;
        case DisplayChannels:
            displayChannels(languageId);
            break;
        case ManagePrograms:
        {
            cout << "Enter Channel ID: ";
            int chId = getValidatedInt();
            if (getChannel(languageId, chId))
                managePrograms(languageId, chId);
            else
                cout << "Channel not found.\n";
            break;
        }
        case Back:
            return;
        default: cout << "Invalid choice.\n";
        }
    }
}

void Admin::createChannel(int languageId)
{
    auto lang = getLanguage(languageId);
    if (!lang)
    {
        cout << "Invalid Language.\n";
        return;
    }

    cout << "Enter Channel ID: ";
    int id = getValidatedInt();

    cout << "Enter Channel Name: ";
    string name = getValidatedChannelName();

    cout << "Enter Channel Price: ";
    double price = getValidatedDouble();

    lang->addChannel(id, name, price);
    m_reader->insertChannel(id, name, price, lang->getLanguageId());
}

void Admin::updateChannel(int languageId)
{
    auto lang = getLanguage(languageId);
    if (!lang)
    {
        cout << "Invalid Language.\n";
        return;
    }

    cout << "Enter Channel ID to update: ";
    int id = getValidatedInt();

    cout << "Enter New Channel Name: ";
    string name = getValidatedChannelName();

    cout << "Enter New Price: ";
    double price = getValidatedDouble();

    lang->editChannel(id, name, price);
    m_reader->updateChannel(id, name, price, lang->getLanguageId());
}

void Admin::deleteChannel(int languageId)
{
    auto lang = getLanguage(languageId);
    if (!lang)
    {
        cout << "Invalid Language.\n";
        return;
    }

    cout << "Enter Channel ID to delete: ";
    int id = getValidatedInt();

    lang->deleteChannel(id);
    m_reader->deleteChannel(id);
}

void Admin::displayChannels(int languageId)
{
    auto lang = getLanguage(languageId);
    if (!lang)
    {
        cout << "Invalid Language.\n";
        return;
    }
    lang->displayChannels();
}

void Admin::managePrograms(int languageId, int channelId)
{
    int choice;
    while (true)
    {
        auto channel = getChannel(languageId, channelId);
        if (!channel)
        {
            cout << "Channel not found.\n";
            return;
        }

        cout << "\n===== MANAGE PROGRAMS for " << channel->getChannelName() << " =====\n";
        cout << "1. Add Program\n"
                "2. Edit Program\n"
                "3. Delete Program\n"
                "4. Display Programs\n"
                "5. Back\n";

        cout << "Enter choice: ";
        choice = getValidatedInt();

        switch (choice)
        {
        case AddPrograms:
            createProgram(languageId, channelId);
            break;
        case UpdateProgram:
            updateProgram(languageId, channelId);
            break;
        case DeleteProgram:
            deleteProgram(languageId, channelId);
            break;
        case DisplayPrograms:
            displayPrograms(languageId, channelId);
            break;
        case Return:
            return;
        default:
            cout << "Invalid choice.\n";
        }
    }
}

void Admin::createProgram(int languageId, int channelId)
{
    auto channel = getChannel(languageId, channelId);
    if (!channel)
    {
        cout << "Invalid Channel.\n";
        return;
    }

    cout << "Enter Program ID: ";
    int id = getValidatedInt();

    cout << "Enter Program Name: ";
    string name = getValidatedName();

    string start, end;

    cout << "Enter Start Time (HH:MM): ";
    cin >> start;
    cout << "Enter End Time (HH:MM): ";
    cin >> end;

    if (!isValidTime(start) || !isValidTime(end))
    {
        cout << "Invalid time format.\n";
        return;
    }

    channel->addProgram(id, name, start, end);
    m_reader->insertProgram(id, name, start, end, channel->getChannelId());
}

void Admin::updateProgram(int languageId, int channelId)
{
    auto channel = getChannel(languageId, channelId);
    if (!channel)
    {
        cout << "Invalid Channel.\n";
        return;
    }

    cout << "Enter Program ID: ";
    int id = getValidatedInt();

    cout << "Enter New Program Name: ";
    string name = getValidatedName();

    string start, end;

    cout << "Enter New Start Time (HH:MM): ";
    cin >> start;
    cout << "Enter New End Time (HH:MM): ";
    cin >> end;

    if (!isValidTime(start) || !isValidTime(end))
    {
        cout << "Invalid time format.\n";
        return;
    }

    channel->editProgram(id, name, start, end);
    m_reader->updateProgram(id, name, start, end);
}

void Admin::deleteProgram(int languageId, int channelId)
{
    auto channel = getChannel(languageId, channelId);
    if (!channel)
    {
        cout << "Invalid Channel.\n";
        return;
    }

    cout << "Enter Program ID to delete: ";
    int id = getValidatedInt();

    channel->deleteProgram(id);
    m_reader->deleteProgram(id);
}

void Admin::displayPrograms(int languageId, int channelId)
{
    auto channel = getChannel(languageId, channelId);
    if (!channel)
    {
        cout << "Invalid Channel.\n";
        return;
    }
    channel->displayPrograms();
}

void Admin::managePackages()
{
    int choice;
    while (true)
    {
        cout << "\n===== PACKAGE MANAGEMENT =====\n";
        cout << "1. Create Package\n"
                "2. Edit Package\n"
                "3. Delete Package\n"
                "4. View Packages\n"
                "5. Back\n";

        cout << "Enter choice: ";
        choice = getValidatedInt();

        switch (choice)
        {
        case AddPackage:
            createPackage(m_languageMap);
            break;
        case UpdatePackage:
            editPackage();
            break;
        case DeletePackage:
            deletePackage();
            break;
        case DisplayPackage:
            displayPackages();
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice.\n";
        }
    }
}

void Admin::createPackage(map<int, Languages*>& languageMap)
{
    cout << "Enter Package ID: ";
    int pkgId = getValidatedInt();

    cout << "Enter Package Name: ";
    string pkgName = getValidatedName();

    if (m_packageMap.find(pkgId) != m_packageMap.end())
    {
        cout << "Package with this ID already exists.\n";
        return;
    }

    Package* pack = new Package(pkgId, pkgName);

    cout << "\nSelect Package Type:\n";
    cout << "1. Complete Package\n";
    cout << "2. Language Package\n";
    cout << "3. Custom Package\n";

    cout << "Enter choice: ";
    int type = getValidatedInt();

    switch (type)
    {
    case CompletePackage:
        for (auto& langPair : languageMap)
        {
            for (auto& chPair : langPair.second->getChannelMap())
            {
                pack->addChannel(chPair.second);
            }
        }
        break;

    case LanguagePackage:
    {
        cout << "Enter Language ID: ";
        int langId = getValidatedInt();

        auto it = languageMap.find(langId);
        if (it != languageMap.end())
        {
            Languages* lang = it->second;
            for (auto& chPair : lang->getChannelMap())
            {
                pack->addChannel(chPair.second);
            }
        }
        else
        {
            cout << "Language not found!\n";
            delete pack;
            return;
        }
        break;
    }

    case CustomPackage:
    {
        char choice;
        do
        {
            cout << "Enter Channel ID to add: ";
            int chId = getValidatedInt();

            bool found = false;

            for (auto& langPair : languageMap)
            {
                auto& chMap = langPair.second->getChannelMap();
                if (chMap.find(chId) != chMap.end())
                {
                    pack->addChannel(chMap[chId]);
                    cout << "Added channel: " << chMap[chId]->getChannelName() << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Channel not found.\n";

            cout << "Add another channel? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
        break;
    }

    default:
        cout << "Invalid type.\n";
        delete pack;
        return;
    }

    m_packageMap[pack->getPackageId()] = pack;

    if (m_reader->insertPackage(pack->getPackageId(), pack->getPackageName(), pack->getTotalPrice()))
    {
        for (auto& chPair : pack->getChannelMap())
            m_reader->insertPackageChannel(pack->getPackageId(), chPair.second->getChannelId());

        cout << "\nPackage '" << pack->getPackageName()  << " created successfully with total price " << pack->getTotalPrice() << ".\n";
    }
    else
    {
        cout << "Failed to save package.\n";
    }
}

void Admin::displayPackages()
{
    if (m_packageMap.empty())
    {
        cout << "No packages available.\n";
        return;
    }

    for (auto& [id, pack] : m_packageMap)
    {
        cout << "\n========== PACKAGE ID: " << pack->getPackageId() << " | NAME: " << pack->getPackageName() << " ==========\n";

        if (pack->getChannelMap().empty())
        {
            cout << "No channels in this package.\n";
            continue;
        }

        for (auto& chPair : pack->getChannelMap())
        {
            Channels* ch = chPair.second;
            cout << " - " << ch->getChannelId() << "." << ch->getChannelName() << " (" << ch->getPrice() << ")\n";
        }


        cout << "----------------------------------------------\n";
        cout << "Total Price: " << pack->getTotalPrice() << endl;
    }
}

void Admin::editPackage()
{
    cout << "Enter Package ID to edit: ";
    int pkgId = getValidatedInt();

    auto it = m_packageMap.find(pkgId);
    if (it == m_packageMap.end())
    {
        cout << "Package not found.\n";
        return;
    }

    Package* pack = it->second;

    cout << "\nEditing Package: " << pack->getPackageName() << endl;
    cout << "1. Rename Package\n";
    cout << "2. Add Channel\n";
    cout << "3. Remove Channel\n";
    cout << "4. Back\n";

    cout << "Enter choice: ";
    int choice = getValidatedInt();

    switch (choice)
    {
    case RenamePackage:
    {
        cout << "Enter new package name: ";
        string newName = getValidatedName();

        pack->setPackageName(newName);
        if (m_reader->insertPackage(pack->getPackageId(), newName, pack->getTotalPrice()))
            cout << "Package renamed successfully.\n";
        else
            cout << "Failed to rename package.\n";
        break;
    }

    case AddChannel_to_Package:
    {
        cout << "Enter Channel ID to add: ";
        int chId = getValidatedInt();

        for (auto& langPair : m_languageMap)
        {
            auto& chMap = langPair.second->getChannelMap();
            if (chMap.find(chId) != chMap.end())
            {
                pack->addChannel(chMap[chId]);
                m_reader->insertPackageChannel(pack->getPackageId(), chId);
                cout << "Channel added successfully.\n";
                break;
            }
        }
        pack->calculateTotalPrice();
        break;
    }

    case RemoveChannel:
    {
        cout << "Enter Channel ID to remove: ";
        int chId = getValidatedInt();

        pack->removeChannel(chId);
        pack->calculateTotalPrice();
        cout << "Channel removed successfully.\n";
        break;
    }

    case BACK:
        return;

    default:
        cout << "Invalid choice.\n";
    }
}

void Admin::deletePackage()
{
    cout << "Enter Package ID to delete: ";
    int id = getValidatedInt();

    auto it = m_packageMap.find(id);
    if (it != m_packageMap.end())
    {
        m_reader->deletePackage(id);
        delete it->second;
        m_packageMap.erase(it);
        cout << "Package deleted successfully.\n";
    }
    else
        cout << "Package not found.\n";
}
