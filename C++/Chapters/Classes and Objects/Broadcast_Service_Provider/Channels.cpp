#include "Channels.h"
#include "Sql_Reader.h"
#include <iomanip>

Channels::Channels()
{
    cout << "Channel Constructor" << endl;
}

Channels::Channels(int channelId, const string& channelName): m_channelId(channelId), m_channelName(channelName)
{
    cout << "Channel Parameterized Constructor" << endl;
}

void Channels::setChannelId(const int& id)
{
    m_channelId = id;
}

int Channels::getChannelId()
{
    return m_channelId;
}

void Channels::setChannelName(const string& name)
{
    m_channelName = name;
}

string Channels::getChannelName()
{
    return m_channelName;
}

void Channels::createProgram(int id, const string& title, const string& start, const string& end, FileReader* m_reader)
{
    if (isProgramIdPresent(id))
            {
                cout << "Program ID already exists.\n";
                return;
            }

            Programs* program = new Programs(id, title, start, end);
            m_program[id] = program;
            cout << "Program " << title << " (ID: " << id << ") added.\n";

        if(m_reader)
            m_reader->insertProgram(id, title, start, end, m_channelId);
}

void Channels::updateProgram(int programId, const string& programTitle, const string& startTime, const string& endTime, FileReader* m_reader)
{
    auto it = m_program.find(programId);

    if (it == m_program.end())
    {
        cout << "Program ID not found\n";
        return;
    }

    Programs* p = it->second;
    p->setProgramTitle(programTitle);
    p->setStartTime(startTime);
    p->setEndTime(endTime);

    cout << "Program updated successfully\n";

    if(m_reader)
        m_reader->updateProgram(programId, programTitle, startTime, endTime);
}

void Channels::deleteProgram(int programId, FileReader* m_reader)
{
    auto it = m_program.find(programId);

    if (it == m_program.end())
    {
        cout << "Program ID not found\n";
        return;
    }

    delete it->second;
    m_program.erase(it);
    cout << "Program deleted successfully\n";

    if(m_reader)
        m_reader->deleteProgram(programId);
}

void Channels::displayChannels(int languageId, int categoryId, const map<int, string>& languageMap, const map<int, string>& categoryMap)
{
    string langName = languageMap.count(languageId) ? languageMap.at(languageId) : "Unknown";
    string catName = categoryMap.count(categoryId) ? categoryMap.at(categoryId) : "Unknown";

    cout << left << setw(5) << "ID"
         << left << setw(20) << "Channel Name"
         << left << setw(20) << "Language"
         << left << setw(20) << "Category" << endl;

    cout << left << setw(5) << m_channelId
         << left << setw(20) << m_channelName
         << left << setw(20) << langName
         << left << setw(20) << catName << endl;

    displayAllPrograms();
    cout << "\n*****************************************\n";
}

void Channels::channelsList(int languageId, int categoryId, const map<int, string>& languageMap, const map<int, string>& categoryMap)
{
    string langName = languageMap.count(languageId) ? languageMap.at(languageId) : "Unknown";
    string catName = categoryMap.count(categoryId) ? categoryMap.at(categoryId) : "Unknown";

    cout << "Channel Id ---> " << m_channelId
         << " | Channel Name ---> " << m_channelName
         << " | Language ---> " << langName
         << " | Category ---> " << catName << endl;
}

void Channels::displayAllPrograms()
{
    if (m_program.empty())
    {
        cout << "No programs available" << endl;
        return;
    }

    for (auto& i : m_program)
    {
        i.second->displayPrograms();
    }
}

bool Channels::isProgramIdPresent(int programId)
{
    if( m_program.find(programId) == m_program.end())
        return false;
    else
        return true;
}

Programs* Channels::getProgram(int programId)
{
    auto it = m_program.find(programId);
    if (it != m_program.end())
        return it->second;
    else
        return nullptr;
}

Channels::~Channels()
{
    for (auto& prog : m_program)
    {
        delete prog.second;
    }
    m_program.clear();
    cout << "Channel Destructor" << endl;
}
