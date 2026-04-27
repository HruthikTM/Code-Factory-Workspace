#include "mainwindow.h"
#include<map>
#include <QApplication>
#include<iostream>
#include<string>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // MainWindow w;
    // w.show();
    int choice;
    // qDebug() << "Enter the choice:";
    std::cout<<"enter choice";
    std::cin>>choice;

    switch(choice)
    {
    case 1: std::cout<<"hii";
        break;
    case 2: std::cout<<"hello";
        break;
    default:std::cout<<"exit";
    }
    return 0;

    // return a.exec();
}
