#ifndef MYHEADERVIEW_H
#define MYHEADERVIEW_H

#include <QHeaderView>

class MyHeaderView : public QHeaderView
{
    Q_OBJECT

public:
    explicit MyHeaderView(Qt::Orientation orientation, QWidget *parent = nullptr);

    using QHeaderView::logicalIndexAt;

    int logicalIndexAt(const QPointF &pos) const;

};

#endif // MYHEADERVIEW_H
