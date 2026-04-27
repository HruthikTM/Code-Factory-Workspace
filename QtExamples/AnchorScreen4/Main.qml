import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rect1
        height: parent.height / 5
        width: parent.width / 5
        color: "#855682"
    }

    Rectangle {
        id: rect2
        height: parent.height / 5
        width: parent.width / 5
        color: "#745943"
        anchors.top: rect1.bottom
        anchors.left: rect1.right
    }

    Rectangle {
        id: rect3
        height: parent.height / 5
        width: parent.width / 5
        color: "#961253"
        anchors.top: rect2.bottom
        anchors.left: rect2.right
    }

    Rectangle {
        id: rect4
        height: parent.height / 5
        width: parent.width / 5
        color: "#231456"
        anchors.top: rect3.bottom
        anchors.left: rect3.right
    }

    // Rectangle {
    //     id: rect5
    //     height: parent.height / 5
    //     width: parent.width / 5
    //     color: "#332145"
    //     anchors.top: rect4.bottom
    //     anchors.left: rect4.right
    // }
}
