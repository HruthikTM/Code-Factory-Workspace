#ifndef PERSONDETAILS_H
#define PERSONDETAILS_H

#include <iostream>
#include <string>

using namespace std;

class PersonlDetails
{
public:
    PersonlDetails();
    ~PersonlDetails();

    int id() const;
    void setId(int newId);
    string password() const;
    void setPassword(const string &newPassword);
    string name() const;
    void setName(const string &newName);
    string phoneNumber() const;
    void setPhoneNumber(const string &newPhoneNumber);

private:
    int m_id;
    string m_password;
    string m_name;
    string m_phoneNumber;

private:

};

#endif // PERSONDETAILS_H
