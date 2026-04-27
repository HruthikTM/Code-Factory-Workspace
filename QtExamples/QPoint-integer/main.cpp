#include "mainwindow.h"

#include <QApplication>
#include <QPoint>
#include <QPointF>
#include <QDebug>

int main(int argc, char *argv[])
{
    // QPointF pf(10.4,20.4);
    // QPoint p = pf.toPoint();

    QPoint p(10.45,89.3);

    //qDebug() << "QPointF: " << pf;
    qDebug() << "QPoint: " << p;
}
