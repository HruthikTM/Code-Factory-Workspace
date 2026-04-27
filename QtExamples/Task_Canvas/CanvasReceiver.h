#ifndef CANVASRECEIVER_H
#define CANVASRECEIVER_H

#include <QObject>
#include <QString>
#include <QPointF>
#include <QVector>

#include "CanvasData.h"

class CanvasReceiver : public QObject
{
    Q_OBJECT
public:
    explicit CanvasReceiver(QObject *parent = nullptr);

    void receiveFreeDraw(const QVector<QPointF> &points);
    void receiveDotPoints(const QVector<QPointF> &points);
    void receiveImage(const QString &path);

signals:
    void dataReady(const CanvasData &data);

private:
    CanvasData data;
};

#endif // CANVASRECEIVER_H