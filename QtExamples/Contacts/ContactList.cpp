#include "ContactList.h"

ContactList::ContactList(QObject *parent)
    : QObject{parent}
{
    m_contactList.push_back("APPA");
    m_contactList.push_back("AMMA");
    m_contactList.push_back("KOTI");
    m_contactList.push_back("CHETAN");
    m_contactList.push_back("DIXIT");
    m_contactList.push_back("PRATHIK");
    m_contactList.push_back("YASHWANTH");
    m_contactList.push_back("VIDYADEESH");
    m_contactList.push_back("SUHAS");
    m_contactList.push_back("HARSHA");
}

QList<QString> ContactList::contacts() const
{
    return m_contactList;
}
