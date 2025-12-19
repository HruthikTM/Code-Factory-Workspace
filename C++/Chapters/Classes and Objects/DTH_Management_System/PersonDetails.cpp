#include "PersonDetails.h"

PersonDetails::PersonDetails() {}

PersonDetails::~PersonDetails() {}

int PersonDetails::id() const
{
    return m_id;
}

void PersonDetails::setId(int newId)
{
    m_id = newId;
}

string PersonDetails::password() const
{
    return m_password;
}

void PersonDetails::setPassword(const string &newPassword)
{
    m_password = newPassword;
}

string PersonDetails::name() const
{
    return m_name;
}

void PersonDetails::setName(const string &newName)
{
    m_name = newName;
}

string PersonDetails::phoneNumber() const
{
    return m_phoneNumber;
}

void PersonDetails::setPhoneNumber(const string &newPhoneNumber)
{
    m_phoneNumber = newPhoneNumber;
}
