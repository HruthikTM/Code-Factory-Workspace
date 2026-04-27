#include "MySignal.h"

#include <QApplication>
#include "MySlot.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MySignal sig;
    MySlot slt;

    QObject::connect(&sig,&MySignal::dataChange,&slt,MySlot::onDataChanged);

    sig.setData(25);

    return a.exec();
}
