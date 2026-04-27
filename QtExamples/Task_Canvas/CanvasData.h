#ifndef CANVASDATA_H
#define CANVASDATA_H

#include <QString>
#include <QVector>
#include <QPointF>

class CanvasData
{

public:
    CanvasData();

    int getId() const;
    void setId(int id);

    QString getImagePath() const;
    void setImagePath(const QString &imagePath);

    QVector<QPointF> getFreeHandPoints() const;
    void setFreeHandPoints(const QVector<QPointF> &freeHandPoints);

    QVector<QPointF> getDotPoints() const;
    void setDotPoints(const QVector<QPointF> &dotPoints);

    QString getUploadImage() const;
    void setUploadImage(const QString &uploadImage);

    bool getButtonEnabled() const;
    void setButtonEnabled(bool buttonEnabled);

private:
    int m_id;
    QString m_imagePath;
    QVector<QPointF> m_freeHandPoints;
    QVector<QPointF> m_dotPoints;
    QString m_uploadImage;
    bool m_buttonEnabled;

};

#endif // CANVASDATA_H
