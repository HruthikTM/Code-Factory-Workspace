#include "MainWindow.h"

MyWindow::MyWindow()
{
    createTrayIcon();
    connect(trayIcon, &QSystemTrayIcon::activated, this, &MyWindow::iconActivated);
    trayIcon->show();
}
MyWindow::~MyWindow()
{

}

void MyWindow::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible()) {
        hide();
        event->ignore(); // Prevent the window from closing
    }
}

void MyWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger) {
        // Restore window on tray icon click
        if (isHidden()) {
            show();
            activateWindow();
        }
    }
}

void MyWindow::exitApplication()
{
    trayIcon->hide();
    qApp->quit();
}

void MyWindow::createTrayIcon()
{
    trayIcon = new QSystemTrayIcon(QIcon(":/icon.png"), this);

    QMenu *trayMenu = new QMenu(this);
    QAction *restoreAction = new QAction("Restore", this);
    QAction *exitAction = new QAction("Exit", this);

    connect(restoreAction, &QAction::triggered, this, [=]() {
        show();
        activateWindow();
    });
    connect(exitAction, &QAction::triggered, this, &MyWindow::exitApplication);

    trayMenu->addAction(restoreAction);
    trayMenu->addAction(exitAction);

    trayIcon->setContextMenu(trayMenu);
}

