#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyWindow();
    ~MyWindow();
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void exitApplication();
private:
    void createTrayIcon();
    QSystemTrayIcon *trayIcon;

};
#endif // MYWINDOW_H
