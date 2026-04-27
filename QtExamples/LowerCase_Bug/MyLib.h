#pragma once

#include <QObject>

class MyLib : public QObject
{
    Q_OBJECT

public:
    explicit MyLib(QObject *parent = nullptr);

    enum MyEnum {
        Val1,
        Val2
    };
    Q_ENUM(MyEnum)
};
