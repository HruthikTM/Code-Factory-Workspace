#include <iomanip>
#include "Service_Provider.h"
#include "Sql_Reader.h"

ServiceProvider::ServiceProvider()
{
    cout << "Service Provider Constructor" << endl;
    m_serviceProviderId = 123;
    m_serviceProviderName = "Tata Sky";

    m_reader = new Sql_Reader;
    m_reader->createFile();

    m_reader->loadLanguages(m_languageMap);
    m_reader->loadCategories(m_categoryMap);

    m_reader->readFile(m_channel, m_languageMap, m_categoryMap);
}

int ServiceProvider::getServiceProviderId() const
{
    return m_serviceProviderId;
}

void ServiceProvider::displayLanguages()
{
    cout << "\nAvailable Languages:\n";
    for (auto& lang : m_languageMap)
        cout << "  " << lang.first << " - " << lang.second << endl;
}

void ServiceProvider::displayCategories()
{
    cout << "\nAvailable Categories:\n";
    for (auto& cat : m_categoryMap)
        cout << "  " << cat.first << " - " << cat.second << endl;
}

int ServiceProvider::selectLanguage()
{
    displayLanguages();
    cout << "Enter Language ID: ";
    int id;
    cin >> id;

    if (m_languageMap.find(id) == m_languageMap.end())
    {
        cout << "Invalid language ID.\n";
        return 1;
    }
    return id;
}

int ServiceProvider::selectCategory()
{
    displayCategories();
    cout << "Enter Category ID: ";
    int id;
    cin >> id;

    if (m_categoryMap.find(id) == m_categoryMap.end())
    {
        cout << "Invalid category ID.\n";
        return 1;
    }
    return id;
}

int ServiceProvider::createChannel()
{
    int newChannelId;
    string newChannelName;

    validateChannelId(newChannelId);
    cin.ignore();

    while (true)
    {
        cout << "Enter Channel Name: ";
        getline(cin, newChannelName);

        bool hasLetter = false;
        for (char c : newChannelName)
        {
            if (isalpha(c))
                hasLetter = true;
        }

        if (hasLetter && !newChannelName.empty())
            break;
        else
            cout << "Invalid input. Channel name must contain letters.\n";
    }

    int languageId = selectLanguage();
    int categoryId = selectCategory();

    if (!isChannelIdPresent(newChannelId))
    {
        Channels* channel = new Channels(newChannelId, newChannelName);
        m_channel[newChannelId] = channel;

        m_reader->insertChannel(newChannelId, newChannelName, m_serviceProviderId, languageId, categoryId);

        cout << "\nChannel created successfully.\n";
    }
    else
    {
        cout << "\nChannel already exists.\n";
    }

    return newChannelId;
}

void ServiceProvider::updateChannel(int channelId, const string& newChannelName, int languageId, int categoryId)
{
    Channels* ch = getChannel(channelId);
    if (!ch)
    {
        cout << "Channel Id not found" << endl;
        return;
    }

    ch->setChannelName(newChannelName);
    m_reader->updateChannel(channelId, newChannelName, languageId, categoryId);

    cout << "Channel Updated successfully" << endl;
}

void ServiceProvider::deleteChannel(int channelId)
{
    auto it = m_channel.find(channelId);
    if (it == m_channel.end())
    {
        cout << "Channel Id not found" << endl;
        return;
    }

    delete it->second;
    m_channel.erase(it);
    m_reader->deleteChannel(channelId);

    cout << "Channel Deleted successfully" << endl;
}

void ServiceProvider::display()
{
    if (m_channel.empty())
    {
        cout << "No channels available" << endl;
        return;
    }

    for (auto& entry : m_channel)
    {
        int channelId = entry.first;
        Channels* ch = entry.second;

        auto [langId, catId] = m_reader->getChannelLanguageCategory(channelId);

        ch->displayChannels(langId, catId, m_languageMap, m_categoryMap);
    }
}

bool ServiceProvider::isValidTime(const string& time)
{
    if (time.size() != 5 || time[2] != ':')
        return false;

    string hh = time.substr(0, 2);
    string mm = time.substr(3, 2);

    if (!isdigit(hh[0]) || !isdigit(hh[1]) || !isdigit(mm[0]) || !isdigit(mm[1]))
        return false;

    int hour = stoi(hh);
    int minute = stoi(mm);
    return (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59);
}

void ServiceProvider::validateChannelId(int& channelId)
{
    while (true)
    {
        cout << "Enter Channel Id (numbers only): ";
        string input;
        cin >> input;

        bool allDigits = true;
        for (char c : input)
        {
            if (!isdigit(c))
            {
                allDigits = false;
                break;
            }
        }

        if (allDigits && !input.empty())
        {
            channelId = stoi(input);
            break;
        }
        cout << "Invalid input. Channel ID must be numeric.\n";
    }
}

void ServiceProvider::validateProgramId(int& programId)
{
    while (true)
    {
        cout << "Enter Program Id (numbers only): ";
        string input;
        cin >> input;

        bool allDigits = true;
        for (char c : input)
        {
            if (!isdigit(c))
            {
                allDigits = false;
                break;
            }
        }

        if (allDigits && !input.empty())
        {
            programId = stoi(input);
            break;
        }

        cout << "Invalid input. Program ID must be numeric.\n";
    }
}


void ServiceProvider::managePrograms(Channels* channel)
{
    while (true)
    {
        cout << "\n--- Manage Programs for Channel: " << channel->getChannelName() << " ---\n";
        cout << "1. Add Program\n";
        cout << "2. Update Program\n";
        cout << "3. Delete Program\n";
        cout << "4. Display Programs\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            createProgram(channel);
            break;
        case 2:
            updateProgram(channel);
            break;
        case 3:
            deleteProgram(channel);
            break;
        case 4:
            channel->displayAllPrograms();
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice\n";
        }
    }
}

void ServiceProvider::createProgram(Channels* channel)
{
    int programId;
    string title, start, end;

    validateProgramId(programId);
    cin.ignore();
    cout << "Enter Program Title: ";
    getline(cin, title);
    cout << "Enter Start Time (HH:MM): ";
    getline(cin, start);
    cout << "Enter End Time (HH:MM): ";
    getline(cin, end);

    if (!isValidTime(start) || !isValidTime(end))
    {
        cout << "Invalid time format.\n";
        return;
    }

    channel->createProgram(programId, title, start, end, m_reader);
}

void ServiceProvider::updateProgram(Channels* channel)
{
    int programId;
    validateProgramId(programId);
    cin.ignore();

    string title, start, end;
    cout << "Enter new Program Title: ";
    getline(cin, title);
    cout << "Enter new Start Time (HH:MM): ";
    getline(cin, start);
    cout << "Enter new End Time (HH:MM): ";
    getline(cin, end);

    if (!isValidTime(start) || !isValidTime(end))
    {
        cout << "Invalid time format.\n";
        return;
    }

    channel->updateProgram(programId, title, start, end, m_reader);
}

void ServiceProvider::deleteProgram(Channels* channel)
{
    int programId;
    validateProgramId(programId);
    cin.ignore();

    channel->deleteProgram(programId, m_reader);
}

void ServiceProvider::setupChannels()
{
    while (true)
    {
        int choice;
        while(true)
        {
            cout << "\n=====================================\n";
            cout << "       Broadcast Management System    \n";
            cout << "=====================================\n";
            cout << "1. Add Channel\n";
            cout << "2. Update Channel\n";
            cout << "3. Delete Channel\n";
            cout << "4. Manage Programs\n";
            cout << "5. Display Channels\n";
            cout << "6. Exit\n";
            cout << "=====================================\n";

            cout << "Enter your choice: ";
            cin >> choice;

            if(!isdigit(choice))
                break;
            else
            {
                cin.ignore();
                cin.clear();
                while(getchar() != '\n');
                cout << "Only digits are allowed" << endl;
            }
        }

        switch (choice)
        {
        case CREATE:
            createChannel();
            break;

        case UPDATE:
        {
            if (m_channel.empty())
            {
                cout << "No channels available\n";
                break;
            }

            for (auto& i : m_channel)
            {
                int channelId = i.first;
                Channels* ch = i.second;
                auto [lid, cid] = m_reader->getChannelLanguageCategory(channelId);
                ch->channelsList(lid, cid, m_languageMap, m_categoryMap);
            }

            int channelId;
            validateChannelId(channelId);
            cin.ignore();

            Channels* ch = getChannel(channelId);
            if (!ch)
            {
                cout << "Channel not found\n";
                break;
            }

            string newName;
            cout << "Enter new Channel Name: ";
            getline(cin, newName);
            int newLangId = selectLanguage();
            int newCatId = selectCategory();

            updateChannel(channelId, newName, newLangId, newCatId);

            managePrograms(ch);
            break;
        }

        case DELETE:
        {
            if (m_channel.empty())
            {
                cout << "No channels available\n";
                break;
            }

            for (auto& i : m_channel)
            {
                int channelId = i.first;
                Channels* ch = i.second;
                auto [lid, cid] = m_reader->getChannelLanguageCategory(channelId);
                ch->channelsList(lid, cid, m_languageMap, m_categoryMap);
            }

            int channelId;
            validateChannelId(channelId);
            cin.ignore();

            deleteChannel(channelId);
            break;
        }

        case ManagePrograms:
        {
            if (m_channel.empty())
            {
                cout << "No channels available\n";
                break;
            }

            cout << "\nAvailable Channels:\n";
            for (auto& entry : m_channel)
            {
                int channelId = entry.first;
                Channels* ch = entry.second;
                auto [lid, cid] = m_reader->getChannelLanguageCategory(channelId);
                ch->channelsList(lid, cid, m_languageMap, m_categoryMap);
            }

            int channelId;
            validateChannelId(channelId);
            cin.ignore();

            Channels* ch = getChannel(channelId);
            if (!ch)
            {
                cout << "Channel not found.\n";
                break;
            }

            managePrograms(ch);
            break;
        }

        case DISPLAY:
            display();
            break;

        case EXIT:
            cout << "\nExiting...\n";
            return;

        default:
            cout << "Invalid choice.\n";
        }
    }
}

bool ServiceProvider::isChannelIdPresent(int newchannelId)
{
    return m_channel.find(newchannelId) != m_channel.end();
}

Channels* ServiceProvider::getChannel(int channelId)
{
    auto it = m_channel.find(channelId);
    return (it != m_channel.end()) ? it->second : nullptr;
}

ServiceProvider::~ServiceProvider()
{
    for (auto& channel : m_channel)
        delete channel.second;

    m_channel.clear();
    cout << "Service Provider Destructor" << endl;
}
