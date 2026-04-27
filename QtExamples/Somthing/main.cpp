#include "mainwindow.h"

#include "QPushButton"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPushButton btn;
    w.show();
    return a.exec();
}
