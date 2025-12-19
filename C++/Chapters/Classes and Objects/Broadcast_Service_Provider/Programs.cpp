#include "Programs.h"
#include <iomanip>

Programs::Programs()
{
    cout << "Programs Constructor" << endl;
}

Programs::Programs(int programId, string programTitle, string startTime, string endTime): m_programId(programId), m_programTitle(programTitle), m_startTime(startTime), m_endTime(endTime)
{
    cout << "Programs Parameterized Constructor" << endl;
}

void Programs::setProgramTitle(const string& title)
{
    m_programTitle = title;
}

void Programs::setStartTime(const string& time)
{
    m_startTime = time;
}

void Programs::setEndTime(const string& time)
{
    m_endTime = time;
}

int Programs::getProgramId() const
{
    return m_programId;
}

string Programs::getProgramTitle() const
{
    return m_programTitle;
}

string Programs::getStartTime() const
{
    return m_startTime;
}

string Programs::getEndTime() const
{
    return m_endTime;
}

void Programs::displayPrograms()
{
    cout << left << setw(5) << "ID"
         << left << setw(20) << "Program Title"
         << left << setw(15) << "Start Time"
         << left << setw(15) << "End Time" << endl;

    cout << left << setw(5) << m_programId
         << left << setw(20) << m_programTitle
         << left << setw(15) << m_startTime
         << left << setw(15) << m_endTime << '\n';
    cout << "\n-----------------------------------------\n";
}

Programs::~Programs()
{
    cout << "Programs Destructor" << endl;
}

