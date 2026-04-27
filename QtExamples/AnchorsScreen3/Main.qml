import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id:rect1
        height: 100
        width: 100
        color: "red"
    }

    Rectangle {
        id:rect2
        height: 100
        width: 100
        color: "green"
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Rectangle {
        id:rect3
        height: 100
        width: 100
        color: "blue"
        anchors.right: parent.right
    }

    Rectangle {
        id:rect4
        height: 100
        width: 100
        color: "#556528"
        anchors.verticalCenter: parent.verticalCenter
    }

    Rectangle {
        id:rect5
        height: 100
        width: 100
        color: "#952125"
        anchors.centerIn: parent
    }

    Rectangle {
        id:rect6
        height: 100
        width: 100
        color: "#439897"
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
    }

    Rectangle {
        id:rect7
        height: 100
        width: 100
        color: "brown"
        anchors.bottom: parent.bottom
    }

    Rectangle {
        id:rect8
        height: 100
        width: 100
        color: "pink"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Rectangle {
        id:rect9
        height: 100
        width: 100
        color: "yellow"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }
}
