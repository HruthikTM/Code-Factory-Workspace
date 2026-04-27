#include "MyTableView.h"

#include <QHoverEvent>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QDebug>

MyTableView::MyTableView(QWidget *parent) : QTableView(parent)
{
    setMouseTracking(true);
    viewport()->setAttribute(Qt::WA_Hover);

    auto *model = new QStandardItemModel(5, 3, this);
    setModel(model);

    for (int c = 0; c < 3; c++)
        model->setHeaderData(c, Qt::Horizontal, QStringLiteral("Col %1").arg(c));
}

bool MyTableView::viewportEvent(QEvent *event)
{
    if (event->type() == QEvent::HoverMove) {
        auto *hoverEvent = static_cast<QHoverEvent *>(event);

        // Modern Qt API gives QPointF
        const QPointF posF = hoverEvent->position();

        // QHeaderView still works with QPoint
        const int index =
            horizontalHeader()->logicalIndexAt(posF.toPoint());

        qDebug() << "Hover index:" << index;
    }

    return QTableView::viewportEvent(event);
}
