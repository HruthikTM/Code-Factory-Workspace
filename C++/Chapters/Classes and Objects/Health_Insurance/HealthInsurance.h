#ifndef HEALTHINSURANCE_H
#define HEALTHINSURANCE_H

#include <iostream>
#include <string>
using namespace std;

class HealthInsurance
{

public:
    HealthInsurance();
    ~HealthInsurance();

    void setName(string name);
    string getName();

    void setNumber(int num);
    int getNumber();

    void policy(float amount, int age);

private:
    string m_name;
    int m_phoneNumber;
    float m_amount;
    int m_age;
};

#endif // HEALTHINSURANCE_H
