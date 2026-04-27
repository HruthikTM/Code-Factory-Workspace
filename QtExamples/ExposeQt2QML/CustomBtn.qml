import QtQuick

Rectangle {
    id: root

    property alias btnText: label.text
    property color btnColor: "gray"

    signal clicked()

    width: 70
    height: 25
    color: btnColor
    radius: 4
    anchors.verticalCenter: parent.verticalCenter

    Text {
        id: label
        anchors.centerIn: parent
        color: "white"
        font.pixelSize: 12
    }

    MouseArea {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}
