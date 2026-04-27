#include "Appearance.h"

Appearance::Appearance(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << Q_FUNC_INFO;
    // QFont font("Calibri",12);
    setFont(QFont("Calibri",12));
    setupUI();
    QObject::connect(m_applyBtn,&QPushButton::clicked,this,&Appearance::applyBtnClicked);
    QObject::connect(m_postBtn,&QPushButton::clicked,this,&Appearance::postBtnClicked);
    QObject::connect(m_dismissBtn,&QPushButton::clicked,this,&Appearance::dissmissBtnClicked);
}

void Appearance::setupUI()
{
    qDebug() << Q_FUNC_INFO;
    createMainLayout();

    createCheckBoxSection();
    createBackgroundSection();
    createForegroundSection();
    createStyleSection();
    createOrientationSection();
    createFontSection();
    createFooterButtons();

    assembleLayouts();

    this->setLayout(m_mainWindow);
}

void Appearance::createMainLayout()
{
    qDebug() << Q_FUNC_INFO;
    m_mainWindow = new QVBoxLayout;
    m_mainWindow->setSpacing(20);
    m_mainWindow->setContentsMargins(18,18,18,18);
}

void Appearance::createCheckBoxSection()
{
    qDebug() << Q_FUNC_INFO;
    m_checkBoxLayout = new QHBoxLayout;

    m_checkBox = new QCheckBox("Use default system appearance");

    m_checkBoxLayout->addWidget(m_checkBox);
    m_checkBoxLayout->addStretch();
}

void Appearance::createBackgroundSection()
{
    qDebug() << Q_FUNC_INFO;
    m_backgroundGUILayout = new QHBoxLayout;

    m_backgroundLabel = new QLabel("GUI background");
    m_backgroundLabel->setFixedWidth(120);

    m_backgroundBtn = new QPushButton;
    m_backgroundBtn->setFixedSize(60,30);
    m_backgroundBtn->setStyleSheet("background-color: white;");

    m_backgroundGUILayout->addWidget(m_backgroundLabel);
    m_backgroundGUILayout->addWidget(m_backgroundBtn);
    m_backgroundGUILayout->addStretch();
}

void Appearance::createForegroundSection()
{
    qDebug() << Q_FUNC_INFO;
    m_foregroundGUILayout = new QHBoxLayout;

    m_foregroundLabel = new QLabel("GUI foreground");
    m_foregroundLabel->setFixedWidth(120);

    m_foregroundBtn = new QPushButton;
    m_foregroundBtn->setFixedSize(60,30);
    m_foregroundBtn->setStyleSheet("background-color: black;");

    m_foregroundGUILayout->addWidget(m_foregroundLabel);
    m_foregroundGUILayout->addWidget(m_foregroundBtn);
    m_foregroundGUILayout->addStretch();
}

void Appearance::createStyleSection()
{
    qDebug() << Q_FUNC_INFO;
    m_styleGUILayout = new QHBoxLayout;

    m_styleGUILabel = new QLabel("GUI style");
    m_styleGUILabel->setFixedWidth(120);

    m_styleCombo = new QComboBox;
    m_styleCombo->setFixedSize(200,30);
    m_styleCombo->addItems({
        "WindowsVista",
        "Glassmorphism",
        "Aurora Backgrounds",
        "Skeuomorphism"
    });

    m_styleGUILayout->addWidget(m_styleGUILabel);
    m_styleGUILayout->addWidget(m_styleCombo);
    m_styleGUILayout->addStretch();
}

void Appearance::createOrientationSection()
{
    qDebug() << Q_FUNC_INFO;
    m_orientationGUILayout = new QHBoxLayout;

    m_orientationGUILabel = new QLabel("GUI orientation");
    m_orientationGUILabel->setFixedWidth(120);

    m_orientationCombo = new QComboBox;
    m_orientationCombo->setFixedSize(200,30);
    m_orientationCombo->addItems({
        "Portrait",
        "LandScape",
        "Horizontal",
        "Vertical"
    });

    m_orientationGUILayout->addWidget(m_orientationGUILabel);
    m_orientationGUILayout->addWidget(m_orientationCombo);
    m_orientationGUILayout->addStretch();
}

void Appearance::createFontSection()
{
    qDebug() << Q_FUNC_INFO;
    m_fontGUILayout = new QHBoxLayout;

    m_fontGUILabel = new QLabel("GUI font");
    m_fontGUILabel->setFixedWidth(120);

    m_fontArea = new QTextEdit;
    m_fontArea->setFixedSize(200,30);

    m_fontGUILayout->addWidget(m_fontGUILabel);
    m_fontGUILayout->addWidget(m_fontArea);
    m_fontGUILayout->addStretch();
}

void Appearance::createFooterButtons()
{
    qDebug() << Q_FUNC_INFO;
    m_footerBtnLayout = new QHBoxLayout;

    m_applyBtn   = new QPushButton("Apply");
    m_applyBtn->setFixedSize(100,30);
    m_postBtn    = new QPushButton("Post");
    m_postBtn->setFixedSize(100,30);
    m_dismissBtn = new QPushButton("Dismiss");
    m_dismissBtn->setFixedSize(100,30);

    m_footerBtnLayout->addWidget(m_applyBtn);
    m_footerBtnLayout->addWidget(m_postBtn);
    m_footerBtnLayout->addWidget(m_dismissBtn);
    m_footerBtnLayout->addStretch();
}

void Appearance::assembleLayouts()
{
    qDebug() << Q_FUNC_INFO;
    m_mainWindow->addLayout(m_checkBoxLayout);
    m_mainWindow->addLayout(m_backgroundGUILayout);
    m_mainWindow->addLayout(m_foregroundGUILayout);
    m_mainWindow->addLayout(m_styleGUILayout);
    m_mainWindow->addLayout(m_orientationGUILayout);
    m_mainWindow->addLayout(m_fontGUILayout);
    m_mainWindow->addLayout(m_footerBtnLayout);
    m_mainWindow->addStretch();
}

void Appearance::applyBtnClicked()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "CheckBox is : " << m_checkBox->isChecked();
    qDebug() << "GUI Background : " << m_backgroundBtn->styleSheet();
    qDebug() << "GUI Foreground : " << m_foregroundBtn->styleSheet();
    qDebug() << "GUI style : " << m_styleCombo->currentText();
    qDebug() << "GUI orientation : " << m_orientationCombo->currentText();
    qDebug() << "GUI font : " << m_fontArea->toPlainText();

}

void Appearance::postBtnClicked()
{
    qDebug() << Q_FUNC_INFO;
    m_structure.m_isChecked = m_checkBox->isChecked();
    m_structure.m_backgroundColor = m_backgroundBtn->styleSheet();
    m_structure.m_foregroundColor = m_foregroundBtn->styleSheet();
    m_structure.m_style = m_styleCombo->currentText();
    m_structure.m_orientation = m_orientationCombo->currentText();
    m_structure.m_font = m_fontArea->toPlainText();


    qDebug() << "CheckBox is : " << m_structure.m_isChecked;
    qDebug() << "GUI Background : " << m_structure.m_backgroundColor;
    qDebug() << "GUI Foreground : " << m_structure.m_foregroundColor;
    qDebug() << "GUI style : " << m_structure.m_style;
    qDebug() << "GUI orientation : " << m_structure.m_orientation;
    qDebug() << "GUI font : " << m_structure.m_font;

}

void Appearance::dissmissBtnClicked()
{
    qDebug() << Q_FUNC_INFO;
    this->close();
}

Appearance::~Appearance()
{
    qDebug() << Q_FUNC_INFO;
}

