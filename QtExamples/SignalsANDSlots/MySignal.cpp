#include "MySignal.h"

MySignal::MySignal(QWidget *parent)
    : QWidget(parent)
{}

MySignal::~MySignal() {}

void MySignal::setData(int data)
{
    qDebug() << Q_FUNC_INFO << "Sent data: " << data;
    if(m_data == data)
    {
        return;
    }
    m_data = data;

    emit dataChange(m_data);
}

