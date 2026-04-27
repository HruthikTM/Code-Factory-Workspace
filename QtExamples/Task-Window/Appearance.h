#ifndef APPEARANCE_H
#define APPEARANCE_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QBoxLayout>

#include "AppearanceStructure.h"

class Appearance : public QWidget
{
    Q_OBJECT

public:
    Appearance(QWidget *parent = nullptr);
    ~Appearance();

    void setupUI();

    void createMainLayout();
    void createCheckBoxSection();
    void createBackgroundSection();
    void createForegroundSection();
    void createStyleSection();
    void createOrientationSection();
    void createFontSection();
    void createFooterButtons();

    void assembleLayouts();

public slots:
    void applyBtnClicked();
    void postBtnClicked();
    void dissmissBtnClicked();

private:
    QVBoxLayout *m_mainWindow;

    QHBoxLayout *m_checkBoxLayout;
    QHBoxLayout *m_backgroundGUILayout;
    QHBoxLayout *m_foregroundGUILayout;
    QHBoxLayout *m_styleGUILayout;
    QHBoxLayout *m_orientationGUILayout;
    QHBoxLayout *m_fontGUILayout;
    QHBoxLayout *m_footerBtnLayout;

    QCheckBox *m_checkBox;

    QLabel *m_backgroundLabel;
    QLabel *m_foregroundLabel;
    QLabel *m_styleGUILabel;
    QLabel *m_orientationGUILabel;
    QLabel *m_fontGUILabel;

    QPushButton *m_backgroundBtn;
    QPushButton *m_foregroundBtn;
    QPushButton *m_applyBtn;
    QPushButton *m_postBtn;
    QPushButton *m_dismissBtn;

    QComboBox *m_styleCombo;
    QComboBox *m_orientationCombo;

    QTextEdit *m_fontArea;

    AppearanceStructure m_structure;

};
#endif // APPEARANCE_H
