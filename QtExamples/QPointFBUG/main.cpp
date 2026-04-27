#include <QApplication>
#include <QMainWindow>
#include "MyTableView.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow window;

    MyTableView *table = new MyTableView(&window);
    window.setCentralWidget(table);

    window.resize(600, 400);
    window.show();

    return a.exec();
}
