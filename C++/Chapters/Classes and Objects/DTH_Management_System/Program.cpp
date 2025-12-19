#include "Program.h"

Programs::Programs() {}

Programs::Programs(int id, const string& name, const string& start, const string& end) : m_programId(id), m_programName(name), m_startTime(start), m_endTime(end)
{}

int Programs::getProgramId() const
{
    return m_programId;
}

string Programs::getProgramName() const
{
    return m_programName;
}

string Programs::getStartTime() const
{
    return m_startTime;
}

string Programs::getEndTime() const
{
    return m_endTime;
}

void Programs::setProgramId(int id)
{
    m_programId = id;
}

void Programs::setProgramName(const string& name)
{
    m_programName = name;
}

void Programs::setStartTime(const string& start)
{
    m_startTime = start;
}

void Programs::setEndTime(const string& end)
{
    m_endTime = end;
}
