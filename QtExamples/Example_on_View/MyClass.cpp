#include "MyClass.h"

MyClass::MyClass(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO;

    m_name = "Dixit";
}

QString MyClass::getName() const
{
    qDebug()<<Q_FUNC_INFO;
    return m_name;
}

void MyClass::setName(const QString &newName)
{
    qDebug()<<Q_FUNC_INFO;

    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

void MyClass::fun()
{
    qDebug()<<"Function called";
}
