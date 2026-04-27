#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "mylib.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    qmlRegisterUncreatableType<MyLib>(
        "LowerCase_Bug", 1, 0,
        "mylib",   // <-- problem: lowercase
        "Enum only"
        );

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("LowerCase_Bug", "Main");

    return app.exec();
}
