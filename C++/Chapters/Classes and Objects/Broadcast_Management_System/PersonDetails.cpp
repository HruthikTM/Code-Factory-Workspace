#include "PersonDetails.h"

PersonlDetails::PersonlDetails() {}

PersonlDetails::~PersonlDetails() {}

int PersonlDetails::id() const
{
    return m_id;
}

void PersonlDetails::setId(int newId)
{
    m_id = newId;
}

string PersonlDetails::password() const
{
    return m_password;
}

void PersonlDetails::setPassword(const string &newPassword)
{
    m_password = newPassword;
}

string PersonlDetails::name() const
{
    return m_name;
}

void PersonlDetails::setName(const string &newName)
{
    m_name = newName;
}

string PersonlDetails::phoneNumber() const
{
    return m_phoneNumber;
}

void PersonlDetails::setPhoneNumber(const string &newPhoneNumber)
{
    m_phoneNumber = newPhoneNumber;
}
