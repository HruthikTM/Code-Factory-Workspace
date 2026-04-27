#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Sample.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Sample sampleObj;
    // engine.rootContext()->setContextProperty("sample", &sampleObj);

    qmlRegisterType<Sample>("com.app.sample",1,0,"Sample");

    const QUrl url(QStringLiteral("qrc:/ExposeQt2QML/main.qml"));
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
