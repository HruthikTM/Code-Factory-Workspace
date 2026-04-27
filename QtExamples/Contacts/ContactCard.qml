import QtQuick

Rectangle {
    id: contactcard

    property string contactName: ""

    width: parent.width
    height: parent.height/12
    topLeftRadius: 10
    topRightRadius: 10
    color: "#3a3a3a"
    border.color: "#3a3a3a"
    border.width: 1

    anchors.horizontalCenter: parent.horizontalCenter

    Row {
        anchors.verticalCenter: contactcard.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: contactcard.height/6.6
        spacing: 12

        Rectangle {
            width: contactcard.height-contactcard.height/6.6
            height: width
            radius: width / 2

            color: "#6c63ff"

            Text {
                anchors.centerIn: parent
                text: contactName.charAt(0)
                color: "white"
                font.bold: true
            }
        }

        Text {
            text: contactName
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 16
            color: "white"
        }
    }
}
