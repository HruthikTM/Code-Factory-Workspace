import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    Rectangle {
        id: rect1
        height: 100
        width: 100
        color: "red"
        anchors.top: parent.top
        anchors.topMargin: 20

    }

    Rectangle {
        id: rect2
        height: 100
        width: 100
        color: "blue"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 20
    }

    Rectangle {
        id: rect3
        height: 100
        width: 100
        color: "green"
        anchors.verticalCenter: parent.verticalCenter
    }

    Rectangle {
        id: rect4
        height: 100
        width: 100
        color: "orange"
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
    }

    Rectangle {
        id: rect5
        height: 100
        width: 100
        color: "yellow"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
    }

    Rectangle {
        id: rect6
        height: 100
        width: 100
        color: "violet"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
    }


}
