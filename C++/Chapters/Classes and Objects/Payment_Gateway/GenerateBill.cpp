#include "GenerateBill.h"

GenerateBill::GenerateBill()
{
    cout << "Generate Bill Constructor" << endl;
    m_format = "";
}

GenerateBill::~GenerateBill()
{
    cout << "Generate Bill Destructor" << endl;
}

void GenerateBill::setAmount(float amount)
{
    m_amount = amount;
}

float GenerateBill::getAmount()
{
    return m_amount;
}

void GenerateBill::setMode(string mode)
{
    m_mode = mode;
}

string GenerateBill::getMode()
{
    return m_mode;
}

void GenerateBill::setFormat(string format)
{
    m_format = format;
}

string GenerateBill::getFormat()
{
    return m_format;
}

void GenerateBill::save()
{
    cout << "Bill saved to " << m_format << endl;
}

void GenerateBill::display()
{
    cout << "Displaying bill from " << m_format << " Amount: " << m_amount << ", Mode: " << m_mode << endl;
}
