#include "CanvasReceiver.h"
#include <QDebug>

CanvasReceiver::CanvasReceiver(QObject *parent)
    : QObject{parent}
{
    data.setId(0);
    data.setButtonEnabled(false);
}

void CanvasReceiver::receiveFreeDraw(const QVector<QPointF> &points)
{
    qDebug() << "receiveFreeDraw: received" << points.length() << "points";
    
    if(points.isEmpty())
        return;
    
    data.setFreeHandPoints(points);
    data.setButtonEnabled(true);

    emit dataReady(data);
}

void CanvasReceiver::receiveDotPoints(const QVector<QPointF> &points)
{
    qDebug() << "receiveDotPoints: received" << points.length() << "points";
    
    if(points.isEmpty())
        return;
    
    data.setDotPoints(points);

    emit dataReady(data);
}

void CanvasReceiver::receiveImage(const QString &path)
{
    qDebug() << "receiveImage:" << path;
    
    data.setImagePath(path);

    emit dataReady(data);
}