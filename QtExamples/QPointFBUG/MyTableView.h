#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QTableView>

class MyTableView : public QTableView
{
    Q_OBJECT

public:
    explicit MyTableView(QWidget *parent = nullptr);

protected:
    bool viewportEvent(QEvent *event) override;
};

#endif // MYTABLEVIEW_H
