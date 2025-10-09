
#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        qFatal("No system tray available on this system.");
    }

    QApplication::setQuitOnLastWindowClosed(false);

    MyWindow window;
    window.show();

    return app.exec();
}
