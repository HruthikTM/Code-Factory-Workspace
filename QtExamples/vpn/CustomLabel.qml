import QtQuick

Text {
    id: lab

    property alias labelText: lab.text
    property int labelWidth: 120

    width: labelWidth
    font.pixelSize: 20
    font.bold: true
}
