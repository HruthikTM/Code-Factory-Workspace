
#ifndef GENERATEBILL_H
#define GENERATEBILL_H
#include <iostream>
#include <string>
using namespace std;

class GenerateBill
{
private:
    float m_amount;
    string m_mode;
    string m_format;

public:
    GenerateBill();
    virtual ~GenerateBill();

    void setAmount(float amount);
    float getAmount();

    void setMode(string mode);
    string getMode();

    void setFormat(string format);
    string getFormat();

    void save();
    void display();
};

#endif
