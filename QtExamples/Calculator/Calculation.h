#ifndef CALCULATION_H
#define CALCULATION_H

#include <QObject>
#include <QJSEngine>

class Calculation : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(QString displayText READ getDisplayText WRITE setDisplayText NOTIFY displayValueChanged)

    
public:
    explicit Calculation(QObject *parent = nullptr);

    Q_INVOKABLE double calculate(QString exp);

    Q_INVOKABLE void appendToDisplay(QString value);
    Q_INVOKABLE void clearDisplay();
    Q_INVOKABLE void deleteLastChar();
    Q_INVOKABLE void performCalcualtion();

    QString getDisplayText() const;
    void setDisplayText(const QString &displayText);

signals:
    void displayValueChanged();

private:
    QString m_displayText;
};

#endif // CALCULATION_H
