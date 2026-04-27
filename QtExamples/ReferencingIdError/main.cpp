#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QDebug>
#include <QtGlobal>

void messageHandler(QtMsgType type,
                    const QMessageLogContext &context,
                    const QString &msg)
{
    Q_UNUSED(context);

    if (type == QtWarningMsg || type == QtCriticalMsg) {
        qDebug() << "QML ERROR:" << msg;
    }
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(messageHandler);

    QGuiApplication app(argc, argv);

    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl::fromLocalFile("CustomItem.qml"));

    QObject *obj = component.create();   // object IS created

    Q_UNUSED(obj);

    return 0;
}
