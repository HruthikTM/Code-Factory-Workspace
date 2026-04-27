#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QString>
#include "ContactList.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ContactList clist;

    engine.rootContext()->setContextProperty("contact", &clist);

    // QString str;
    // str = ">ERROR: Failed to connect Network";
    // qDebug()<<"Error message = "<<str.section(":",1).trimmed();

    const QUrl url(QStringLiteral("qrc:/Contacts/main.qml"));
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
