#include "MySlot.h"

MySlot::MySlot(QWidget *parent)
    : QWidget{parent}
{}

void MySlot::onDataChanged(int data)
{
    qDebug() << Q_FUNC_INFO << "Recived data: " << data;
}
