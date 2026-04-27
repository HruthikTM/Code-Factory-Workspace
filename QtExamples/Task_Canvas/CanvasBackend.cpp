#include "CanvasBackend.h"

#include <QVariantMap>
#include <QPointF>
#include <QDebug>

CanvasBackend::CanvasBackend(QObject *parent)
    : QObject(parent)
{
    connect(&m_receiver,
            &CanvasReceiver::dataReady,
            &m_model,
            &CanvasModel::insertData);
}

CanvasModel* CanvasBackend::model()
{
    return &m_model;
}

void CanvasBackend::sendFreeDraw(QVariantList xCoords, QVariantList yCoords)
{
    qDebug() << "sendFreeDraw called with" << xCoords.length() << "x coords and" << yCoords.length() << "y coords";
    
    if(xCoords.isEmpty() || yCoords.isEmpty() || xCoords.length() != yCoords.length()) {
        qDebug() << "Invalid coordinates";
        return;
    }
    
    QVector<QPointF> convertedPoints;

    for(int i = 0; i < xCoords.length(); ++i)
    {
        bool xOk = false, yOk = false;
        double x = xCoords.at(i).toDouble(&xOk);
        double y = yCoords.at(i).toDouble(&yOk);
        
        if(xOk && yOk) {
            QPointF point(x, y);
            convertedPoints.append(point);
        }
    }

    qDebug() << "Successfully converted" << convertedPoints.length() << "points";
    
    if(convertedPoints.length() > 0) {
        m_receiver.receiveFreeDraw(convertedPoints);
    }
}


void CanvasBackend::sendDotPoints(QVariantList xCoords, QVariantList yCoords)
{
    qDebug() << "sendDotPoints called with" << xCoords.length() << "x coords and" << yCoords.length() << "y coords";
    
    if(xCoords.isEmpty() || yCoords.isEmpty() || xCoords.length() != yCoords.length()) {
        qDebug() << "Invalid coordinates";
        return;
    }
    
    QVector<QPointF> convertedPoints;

    for(int i = 0; i < xCoords.length(); ++i)
    {
        bool xOk = false, yOk = false;
        double x = xCoords.at(i).toDouble(&xOk);
        double y = yCoords.at(i).toDouble(&yOk);
        
        if(xOk && yOk) {
            QPointF point(x, y);
            convertedPoints.append(point);
        }
    }

    qDebug() << "Successfully converted" << convertedPoints.length() << "points";
    
    if(convertedPoints.length() > 0) {
        m_receiver.receiveDotPoints(convertedPoints);
    }
}


void CanvasBackend::uploadImage(QString path)
{
    qDebug() << "uploadImage called with path:" << path;
    m_receiver.receiveImage(path);
}
