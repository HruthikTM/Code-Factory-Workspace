#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <QObject>
#include <QList>
#include <QString>

class ContactList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> contacts READ contacts CONSTANT)

public:
    explicit ContactList(QObject *parent = nullptr);
    QList<QString> contacts() const;

private:
    QList<QString> m_contactList;
};

#endif // CONTACTLIST_H
