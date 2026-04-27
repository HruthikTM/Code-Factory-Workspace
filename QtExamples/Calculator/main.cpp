#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Calculation.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Calculation cal;

    engine.rootContext()->setContextProperty("calculation", &cal);

    const QUrl url(QStringLiteral("qrc:/Calculator/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}


