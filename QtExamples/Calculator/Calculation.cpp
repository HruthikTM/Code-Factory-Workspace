#include "Calculation.h"

Calculation::Calculation(QObject *parent)
    : QObject{parent}, m_displayText("")
{}

double Calculation::calculate(QString exp)
{
    QJSEngine engine;
    return engine.evaluate(exp).toNumber();
}

void Calculation::appendToDisplay(QString value)
{
    m_displayText += value;
    emit displayValueChanged();
}

void Calculation::clearDisplay()
{
    m_displayText = "";
    emit displayValueChanged();
}

void Calculation::deleteLastChar()
{
    if(!m_displayText.isEmpty())
    {
        m_displayText = m_displayText.sliced(0, m_displayText.length() - 1);
        emit displayValueChanged();
    }
}

void Calculation::performCalcualtion()
{
    if(!m_displayText.isEmpty())
    {
        double res = calculate(m_displayText);
        m_displayText = QString::number(res);
        emit displayValueChanged();
    }
}

QString Calculation::getDisplayText() const
{
    return m_displayText;
}

void Calculation::setDisplayText(const QString &displayText)
{
    if(m_displayText != displayText)
    {
        m_displayText = displayText;
        emit displayValueChanged();
    }
}

