#include "MyHeaderView.h"

#include <QMouseEvent>
#include <QDebug>

MyHeaderView::MyHeaderView(Qt::Orientation orientation, QWidget *parent) : QHeaderView(orientation, parent)
{
    setSectionsMovable(true);
}

// void MyHeaderView::mousePressEvent(QMouseEvent *event)
// {
//     QPoint pos = event->pos();

//     int logical = logicalIndexAt(pos);

//     int visual = (orientation() == Qt::Horizontal) ? visualIndexAt(pos.x()) : visualIndexAt(pos.y());


//     qDebug() << "Mouse position:" << pos;
//     qDebug() << "Visual index:" << visual;
//     qDebug() << "Logical index:" << logical;
//     qDebug() << "----------------------";

//     QHeaderView::mousePressEvent(event);
// }

// void MyHeaderView::mousePressEvent(QMouseEvent *event)
// {
//     QPointF pos = event->position();

//     // Check if fractional part exists
//     bool hasDecimal = (pos.x() != qFloor(pos.x())) || (pos.y() != qFloor(pos.y()));

//     qDebug() << "Position:" << pos;
//     qDebug() << "X fractional part:" << pos.x() - qFloor(pos.x());
//     qDebug() << "Y fractional part:" << pos.y() - qFloor(pos.y());
//     qDebug() << "Has decimal:" << hasDecimal;

//     QHeaderView::mousePressEvent(event);
// }

// void MyHeaderView::mousePressEvent(QMouseEvent *event)
// {
//     QPointF pos = event->position();

//     // If mouse always returns integers, this will always be true
//     if (pos.x() == static_cast<int>(pos.x()) &&
//         pos.y() == static_cast<int>(pos.y())) {
//         qDebug() << "Integer coordinates confirmed:" << pos;
//     } else {
//         qDebug() << "Fractional coordinates:" << pos;
//     }

//     QHeaderView::mousePressEvent(event);
// }

void MyHeaderView::mousePressEvent(QMouseEvent *event)
{

    qDebug() <<"Position :" << event->position();
    qDebug() <<"Position rx :" << event->position().rx();
    qDebug() <<"Position x :" << event->position().x();
    qDebug() <<"Sence Position :" << event->scenePosition();
    qDebug() <<"Global Position :" << event->globalPos();
    qDebug() << "Local pos: " << event->localPos();
    qDebug() << "Windows pos: " << event->windowPos();
    qDebug() << "Screen pos: " << event->screenPos();

    // qDebug() << "X-Position: " << event->x();
    // qDebug() << "Y-Position: " << event->y();
    QHeaderView::mousePressEvent(event);
}
