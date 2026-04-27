QT += quick quickcontrols2

SOURCES += \
        main.cpp

resources.files = main.qml CustomButton.qml CustomLabel.qml CustomRow.qml CustomTextField.qml ConfigServer.qml
resources.prefix = /$${TARGET}
RESOURCES += resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ConfigServer.qml \
    CustomButton.qml \
    CustomLabel.qml \
    CustomRow.qml \
    CustomTextField.qml
