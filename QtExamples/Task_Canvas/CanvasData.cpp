#include "CanvasData.h"

CanvasData::CanvasData() {}

int CanvasData::getId() const
{
    return m_id;
}

void CanvasData::setId(int id)
{
    m_id = id;
}

QString CanvasData::getImagePath() const
{
    return m_imagePath;
}

void CanvasData::setImagePath(const QString &imagePath)
{
    m_imagePath = imagePath;
}

QVector<QPointF> CanvasData::getFreeHandPoints() const
{
    return m_freeHandPoints;
}

void CanvasData::setFreeHandPoints(const QVector<QPointF> &freeHandPoints)
{
    m_freeHandPoints = freeHandPoints;
}

QVector<QPointF> CanvasData::getDotPoints() const
{
    return m_dotPoints;
}

void CanvasData::setDotPoints(const QVector<QPointF> &dotPoints)
{
    m_dotPoints = dotPoints;
}

QString CanvasData::getUploadImage() const
{
    return m_uploadImage;
}

void CanvasData::setUploadImage(const QString &uploadImage)
{
    m_uploadImage = uploadImage;
}

bool CanvasData::getButtonEnabled() const
{
    return m_buttonEnabled;
}

void CanvasData::setButtonEnabled(bool buttonEnabled)
{
    m_buttonEnabled = buttonEnabled;
}
