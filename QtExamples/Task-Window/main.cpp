#include "Appearance.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Appearance w;
    w.show();
    return a.exec();
}
