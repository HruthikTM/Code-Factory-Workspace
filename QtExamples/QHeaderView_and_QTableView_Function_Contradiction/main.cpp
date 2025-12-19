#include "mainwindow.h"

#include <QApplication>
#include <QTableView>
#include <QHeaderView>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTableView table;
    table.show();

    QHeaderView standalone(Qt::Horizontal);
    qDebug() << "Standalone QHeaderView highlightSections Default =" << standalone.highlightSections();

    QHeaderView* tableHeader = table.horizontalHeader();

    qDebug() << "Before change, QTableView header highlightSections =" << tableHeader->highlightSections();

    tableHeader->setHighlightSections(false);

    qDebug() << "After change, QTableView header highlightSections =" << tableHeader->highlightSections();

    return a.exec();
}
