#ifndef CANVASBACKEND_H
#define CANVASBACKEND_H

#include <QObject>
#include <QVariantList>

#include "CanvasReceiver.h"
#include "CanvasModel.h"

class CanvasBackend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(CanvasModel* model READ model CONSTANT)

public:

    explicit CanvasBackend(QObject *parent = nullptr);

    CanvasModel* model();

    Q_INVOKABLE void sendFreeDraw(QVariantList xCoords, QVariantList yCoords);

    Q_INVOKABLE void sendDotPoints(QVariantList xCoords, QVariantList yCoords);

    Q_INVOKABLE void uploadImage(QString path);

private:

    CanvasReceiver m_receiver;

    CanvasModel m_model;

};

#endif
