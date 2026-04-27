#ifndef MYHEADERVIEW_H
#define MYHEADERVIEW_H

#include <QHeaderView>
#include<iostream>
using namespace std;
class MyHeaderView : public QHeaderView
{
    Q_OBJECT

public:
    explicit MyHeaderView(Qt::Orientation orientation, QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *event) override;
};

#endif // MYHEADERVIEW_H
