#ifndef MYSIGNAL_H
#define MYSIGNAL_H

#include <QWidget>
#include <QDebug>

class MySignal : public QWidget
{
    Q_OBJECT

public:
    MySignal(QWidget *parent = nullptr);
    ~MySignal();

    void setData(int data);

signals:
    void dataChange(int updateData);

private:
    int m_data;
};
#endif // MYSIGNAL_H
