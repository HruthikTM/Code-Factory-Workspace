import QtQuick

Text {
    id: customTxt
    property string displaytext: "QML"

    text: displaytext
    color: "#7a3f12"
    font.pixelSize: 48
    font.bold: displaytext
}
