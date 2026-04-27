#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged FINAL)
public:
    explicit MyClass(QObject *parent = nullptr);
    QString getName() const;
    void setName(const QString &newName);
    Q_INVOKABLE void fun();

private:
    QString m_name;


signals:
    void nameChanged();
};

#endif // MYCLASS_H
