#include "TestTable.h"

#include <QHeaderView>
#include <QMouseEvent>
#include <QDebug>

TestTable::TestTable(QWidget *parent) : QTableWidget(parent)
{
    setRowCount(3);
    setColumnCount(4);

    horizontalHeader()->setSectionsMovable(true);
}

void TestTable::mousePressEvent(QMouseEvent *event)
{
    QPoint headerPos = horizontalHeader()->mapFromParent(event->pos());

    int index = horizontalHeader()->logicalIndexAt(headerPos);

    qDebug() << "Mouse position:" << headerPos;
    qDebug() << "Logical index:" << index;

    QTableWidget::mousePressEvent(event);
}
