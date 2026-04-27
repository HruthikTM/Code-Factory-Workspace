#include "Login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    m_userName = new QLabel("Username");

    m_userNameTextArea = new QTextEdit();
    m_userNameTextArea->setFixedSize(200,20);

    m_password = new QLabel("Password");

    m_passwordTextArea = new QTextEdit();
    m_passwordTextArea->setFixedSize(200,20);

    m_loginButton = new QPushButton("Login");
    m_loginButton->setFixedSize(80,40);

    m_cancelButton = new QPushButton("Cancel");
    m_cancelButton->setFixedSize(80,40);

    m_mainLayout = new QVBoxLayout;

    m_hLayout1   = new QHBoxLayout;
    m_hLayout2   = new QHBoxLayout;
    m_hLayout3   = new QHBoxLayout;

    m_hLayout1->addStretch();
    m_hLayout1->setSpacing(30);
    m_hLayout1->addWidget(m_userName);
    m_hLayout1->addWidget(m_userNameTextArea);
    m_hLayout1->addStretch();


    m_hLayout2->addStretch();
    m_hLayout2->setSpacing(30);
    m_hLayout2->addWidget(m_password);
    m_hLayout2->addWidget(m_passwordTextArea);
    m_hLayout2->addStretch();

    m_hLayout3->addStretch();
    m_hLayout3->setSpacing(30);
    m_hLayout3->addWidget(m_loginButton);
    m_hLayout3->addWidget(m_cancelButton);
    m_hLayout3->addStretch();

    m_mainLayout->addStretch();
    m_mainLayout->setSpacing(30);
    m_mainLayout->addLayout(m_hLayout1);
    m_mainLayout->addLayout(m_hLayout2);
    m_mainLayout->addLayout(m_hLayout3);
    m_mainLayout->addStretch();


    this->setLayout(m_mainLayout);


}

Login::~Login() {}
