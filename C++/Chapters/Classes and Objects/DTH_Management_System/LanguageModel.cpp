#include "LanguageModel.h"
using namespace std;

LanguageModel::LanguageModel()
{
    m_reader = SqlReader::getInstance();
    m_reader->readFile(m_languageMap);
}

map<int, Languages*>& LanguageModel::getLanguageMap()
{
    return m_languageMap;
}

void LanguageModel::createLanguage(int id, const string& name)
{
    if (m_languageMap.count(id))
    {
        cout << "Language already exists.\n";
        return;
    }

    m_languageMap[id] = new Languages(id, name);
    m_reader->insertLanguage(id, name);

    cout << "Language created.\n";
}

void LanguageModel::deleteLanguage(int id)
{
    if (!m_languageMap.count(id))
    {
        cout << "Language not found.\n";
        return;
    }

    delete m_languageMap[id];
    m_languageMap.erase(id);

    m_reader->deleteLanguage(id);

    cout << "Language deleted.\n";
}

void LanguageModel::displayLanguages()
{
    if (m_languageMap.empty())
    {
        cout << "No languages available.\n";
        return;
    }

    for (auto& lang : m_languageMap)
    {
        cout << "Language ID: " << lang.first << " | Name: " << lang.second->getLanguageName() << endl;
    }
}

void LanguageModel::createChannel(int langId, int chId, const string& name, double price)
{
    if (!m_languageMap.count(langId))
    {
        cout << "Language not found.\n";
        return;
    }

    m_languageMap[langId]->addChannel(chId, name, price);
    m_reader->insertChannel(chId, name, price, langId);

    cout << "Channel created.\n";
}

void LanguageModel::updateChannel(int langId, int chId, const string& name, double price)
{
    if (!m_languageMap.count(langId))
    {
        cout << "Language not found.\n";
        return;
    }

    auto& chMap = m_languageMap[langId]->getChannelMap();
    if (!chMap.count(chId))
    {
        cout << "Channel not found.\n";
        return;
    }

    m_languageMap[langId]->editChannel(chId, name, price);
    m_reader->updateChannel(chId, name, price, langId);

    cout << "Channel updated.\n";
}

void LanguageModel::deleteChannel(int langId, int chId)
{
    if (!m_languageMap.count(langId))
    {
        cout << "Language not found.\n";
        return;
    }

    m_languageMap[langId]->deleteChannel(chId);
    m_reader->deleteChannel(chId);

    cout << "Channel deleted.\n";
}

void LanguageModel::displayChannels(int langId)
{
    if (!m_languageMap.count(langId))
    {
        cout << "Language not found.\n";
        return;
    }

    m_languageMap[langId]->displayChannels();
}

void LanguageModel::createProgram(int langId, int chId, int prgId, const string& name, const string& start, const string& end)
{
    if (!m_languageMap.count(langId))
    {
        cout << "Language not found.\n";
        return;
    }

    auto& chMap = m_languageMap[langId]->getChannelMap();
    if (!chMap.count(chId))
    {
        cout << "Channel not found.\n";
        return;
    }

    chMap[chId]->addProgram(prgId, name, start, end);
    m_reader->insertProgram(prgId, name, start, end, chId);

    cout << "Program created.\n";
}

void LanguageModel::updateProgram(int langId, int chId, int prgId, const string& name, const string& start, const string& end)
{
    if (!m_languageMap.count(langId))
    {
        cout << "Language not found.\n";
        return;
    }

    auto& chMap = m_languageMap[langId]->getChannelMap();
    if (!chMap.count(chId))
    {
        cout << "Channel not found.\n";
        return;
    }

    chMap[chId]->editProgram(prgId, name, start, end);
    m_reader->updateProgram(prgId, name, start, end);

    cout << "Program updated.\n";
}

void LanguageModel::deleteProgram(int langId, int chId, int prgId)
{
    if (!m_languageMap.count(langId))
    {
        cout << "Language not found.\n";
        return;
    }

    auto& chMap = m_languageMap[langId]->getChannelMap();
    if (!chMap.count(chId))
    {
        cout << "Channel not found.\n";
        return;
    }

    chMap[chId]->deleteProgram(prgId);
    m_reader->deleteProgram(prgId);

    cout << "Program deleted.\n";
}

void LanguageModel::displayPrograms(int langId, int chId)
{
    if (!m_languageMap.count(langId))
    {
        cout << "Language not found.\n";
        return;
    }

    auto& chMap = m_languageMap[langId]->getChannelMap();
    if (!chMap.count(chId))
    {
        cout << "Channel not found.\n";
        return;
    }

    chMap[chId]->displayPrograms();
}
