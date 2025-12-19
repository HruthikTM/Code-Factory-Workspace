#ifndef PROGRAMS_H
#define PROGRAMS_H

#include <string>
using namespace std;

class Programs
{

public:
    Programs();
    Programs(int id, string name, string start, string end);
    ~Programs();

    int getProgramId() const;
    string getProgramName() const;
    string getStartTime() const;
    string getEndTime() const;

    void setProgramId(int id);
    void setProgramName(const string &name);
    void setStartTime(const string &start);
    void setEndTime(const string &end);

private:
    int m_programId;
    string m_programName;
    string m_startTime;
    string m_endTime;
};

#endif // PROGRAMS_H
