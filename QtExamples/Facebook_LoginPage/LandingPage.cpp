#include "LandingPage.h"

LandingPage::LandingPage(QWidget *parent)
    : QWidget(parent)
{}

LandingPage::~LandingPage() {}

void LandingPage::ui()
{
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addStretch();

    m_centerWrapper = new QHBoxLayout;
    m_centerWrapper->addStretch();

    m_contentColumn = new QVBoxLayout;
    m_contentColumn->addStretch();



}

void LandingPage::
