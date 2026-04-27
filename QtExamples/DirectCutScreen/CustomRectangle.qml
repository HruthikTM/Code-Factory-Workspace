import QtQuick

Rectangle
{
    id:customRect

    property color rectColor: "red"
    property color borderColor: "black"

    property alias text: rectText.text
    property alias textColor: rectText.color
    property alias textFont: rectText.font.family
    property alias textFontSize: rectText.font.pointSize

    height: 50
    width: parent ? parent.width : 200

    color: rectColor
    border.color: borderColor
    border.width: 1

    Text {
        id: rectText

        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 20

        text: qsTr("text")
        color: "white"

        font.family: "Helvetica"
        font.pointSize: 18
        font.bold: true
    }
}
