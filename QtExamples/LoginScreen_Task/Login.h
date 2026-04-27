#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QBoxLayout>

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    QLabel *m_userName;
    QLabel *m_password;

    QTextEdit *m_userNameTextArea;
    QTextEdit *m_passwordTextArea;

    QPushButton *m_loginButton;
    QPushButton *m_cancelButton;

    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_hLayout1;
    QHBoxLayout *m_hLayout2;
    QHBoxLayout *m_hLayout3;

};
#endif // LOGIN_H
