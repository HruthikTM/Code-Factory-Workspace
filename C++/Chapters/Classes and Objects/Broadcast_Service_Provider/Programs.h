#ifndef PROGRAMS_H
#define PROGRAMS_H

#include <iostream>
#include <string>

using namespace std;

class Programs
{
public:
    Programs();
    Programs(int programId, string programTitle, string startTime, string endTime);
    ~Programs();

    void displayPrograms();

    int getProgramId() const;
    void setProgramId(int newProgramId);
    string getProgramTitle() const;
    void setProgramTitle(const string& title);
    string getStartTime() const;
    void setStartTime(const string& time);
    string getEndTime() const;
    void setEndTime(const string& time);

private:
    int m_programId;
    string m_programTitle;
    string m_startTime;
    string m_endTime;
};

#endif // PROGRAMS_H
