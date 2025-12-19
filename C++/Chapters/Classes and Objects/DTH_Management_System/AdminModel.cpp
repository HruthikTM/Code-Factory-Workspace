#include "AdminModel.h"

AdminModel::AdminModel()
{
    m_reader = SqlReader::getInstance();

    Admin* defaultAdmin = new Admin();
    defaultAdmin->setId(1);
    defaultAdmin->setPassword("admin123");
    defaultAdmin->setName("SuperAdmin");
    defaultAdmin->setPhoneNumber("9999999999");

    m_adminMap[1] = defaultAdmin;
}

bool AdminModel::verifyUser(int id, const string& password)
{
    return m_reader->verifyUser("admin", id, password);
}

Admin* AdminModel::loadAdmin(int id)
{
    if (adminExists(id))
        return getAdmin(id);

    int uid;
    string uname, upass, uphone;

    bool found = m_reader->getUser("admin", id, uid, uname, upass, uphone);
    if (!found)
        return nullptr;

    Admin* a = new Admin();
    a->setId(uid);
    a->setName(uname);
    a->setPassword(upass);
    a->setPhoneNumber(uphone);

    addAdmin(uid, a);
    return a;

}

bool AdminModel::createAdmin(int id, const string& name, const string& pass, const string& phone)
{
    Admin* a = new Admin();
    a->setId(id);
    a->setName(name);
    a->setPassword(pass);
    a->setPhoneNumber(phone);

    addAdmin(id, a);

    bool dbSuccess = m_reader->insertUser("admin", id, name, pass, phone);
    return dbSuccess;
}

bool AdminModel::addAdmin(int id, Admin* admin)
{
    m_adminMap[id] = admin;
    return true;
}

Admin* AdminModel::getAdmin(int id)
{
    return m_adminMap.count(id) ? m_adminMap[id] : nullptr;
}

bool AdminModel::adminExists(int id)
{
    return m_adminMap.count(id) > 0;
}


//count-->find
