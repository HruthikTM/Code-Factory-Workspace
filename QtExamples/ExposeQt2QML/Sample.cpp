#include "Sample.h"

Sample::Sample(QObject *parent)
    : QObject{parent}
{}

void Sample::work()
{
    qDebug() << Q_FUNC_INFO;
}
