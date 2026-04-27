#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    QPushButton *m_submitButton;
    QPushButton *m_cancelButton;

    QHBoxLayout *m_hBoxLayout;



};
#endif // MYWIDGET_H
