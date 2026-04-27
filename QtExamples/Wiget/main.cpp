#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qDebug() << " Fire detected at"  ;
    qDebug() << "Activating valve shutdown";
    qDebug() << "Hi..........helll0";

    return a.exec();
}
