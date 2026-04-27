#ifndef SAMPLE_H
#define SAMPLE_H

#include <QObject>
#include <QDebug>

class Sample : public QObject
{
    Q_OBJECT
public:
    explicit Sample(QObject *parent = nullptr);

    Q_INVOKABLE void work();

signals:
};

#endif // SAMPLE_H
