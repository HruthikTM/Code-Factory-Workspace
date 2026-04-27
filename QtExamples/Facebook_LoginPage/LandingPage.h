#ifndef LANDINGPAGE_H
#define LANDINGPAGE_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QFrame>

class LandingPage : public QWidget
{
    Q_OBJECT

public:
    LandingPage(QWidget *parent = nullptr);
    ~LandingPage();

    void ui();

private:
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_centerWrapper;
    QVBoxLayout *m_contentColumn;
};
#endif // LANDINGPAGE_H
