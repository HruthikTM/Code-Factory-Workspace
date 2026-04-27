#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    m_submitButton = new QPushButton("Submit",this);
    //m_submitButton->setGeometry(50,50,100,50);
    m_submitButton->setFixedSize(100,50);

    m_cancelButton = new QPushButton("Cancel",this);
    //m_cancelButton->setGeometry(200,50,100,50);
    m_cancelButton->setFixedSize(100,50);


    m_hBoxLayout = new QHBoxLayout(this);
    m_hBoxLayout->addWidget(m_submitButton);
    m_hBoxLayout->addWidget(m_cancelButton);

    this->setLayout(m_hBoxLayout);

}

MyWidget::~MyWidget() {}
