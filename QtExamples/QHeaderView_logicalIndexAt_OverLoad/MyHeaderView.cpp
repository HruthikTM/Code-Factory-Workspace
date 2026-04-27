#include "MyHeaderView.h"
#include <QDebug>

MyHeaderView::MyHeaderView(Qt::Orientation orientation, QWidget *parent) : QHeaderView(orientation, parent)
{
}

int MyHeaderView::logicalIndexAt(const QPointF &pos) const
{
    qDebug() << "Overload Function Is Called";

    return QHeaderView::logicalIndexAt(pos.x(), pos.y());
}
