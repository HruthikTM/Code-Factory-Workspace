#ifndef TESTTABLE_H
#define TESTTABLE_H

#include <QTableWidget>

class TestTable : public QTableWidget
{
    Q_OBJECT

public:
    explicit TestTable(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *event) override;
};

#endif // TESTTABLE_H
