#ifndef MYSLOT_H
#define MYSLOT_H

#include <QWidget>
#include <QDebug>

class MySlot : public QWidget
{
    Q_OBJECT
public:
    explicit MySlot(QWidget *parent = nullptr);

public slots:
    void onDataChanged(int data);
};

#endif // MYSLOT_H
