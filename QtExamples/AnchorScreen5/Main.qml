import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rect1
        height: parent.height / 4
        width: parent.width / 4
        color: "#855682"
        anchors.right: parent.right
    }

    Rectangle {
        id: rect2
        height: parent.height / 4
        width: parent.width / 4
        color: "#745943"
        anchors.top: rect1.bottom
        anchors.right: rect1.left

    }

    Rectangle {
        id: rect3
        height: parent.height / 4
        width: parent.width / 4
        color: "#961253"
        anchors.top: rect2.bottom
        anchors.right: rect2.left
    }

    Rectangle {
        id: rect4
        height: parent.height / 4
        width: parent.width / 4
        color: "#231456"
        anchors.top: rect3.bottom
        anchors.right: rect3.left
    }
}
