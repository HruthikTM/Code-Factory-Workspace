#ifndef ADMINMODEL_H
#define ADMINMODEL_H

#include <map>
#include <string>
#include "Admin.h"
#include "SqlReader.h"

using namespace std;

class AdminModel
{
public:
    AdminModel();

    bool verifyUser(int id, const string& password);
    Admin* loadAdmin(int id);
    bool createAdmin(int id, const string& name, const string& pass, const string& phone);

    bool addAdmin(int id, Admin* admin);
    Admin* getAdmin(int id);
    bool adminExists(int id);

private:
    map<int, Admin*> m_adminMap;
    SqlReader* m_reader;
};

#endif
