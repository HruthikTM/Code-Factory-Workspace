#include "mainwindow.h"

#include <iostream>
#include <QApplication>
#include <QPushButton>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QWidget wb;
    // QWidget *win = &wb;
    // win = &wb;
    QPushButton btn;
    cout<<"Qkjskdskd";
    MainWindow w;
    w.show();
    return a.exec();
}
