import QtQuick
import QtQuick.Window

Window {
    id: root
    width: 720
    height: 540
    visible: true
    title: "Anchor Layout"

    Rectangle {
        id: row1
        color: "gold"
        width: parent.width
        height: parent.height / 3

        Rectangle {
            id: rect1
            width: parent.width / 8
            height: width
            color: "steelblue"
            anchors.left: parent.left
            anchors.leftMargin: parent.width/40
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle {
            id: rect2
            width: parent.width / 3
            height: rect1.width
            color: "deeppink"
            anchors.left: rect1.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle {
            id: rect3
            width: parent.width / 8
            height:width
            color: "purple"
            anchors.left: rect2.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle {
            id: rect4
            width: parent.width / 4
            height: rect1.width
            color: "red"
            anchors.right: parent.right
            anchors.rightMargin: parent.width/40
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Rectangle {
        id: row2
        width: parent.width
        height: parent.height / 3
        color: "silver"
        anchors.top: row1.bottom

        Rectangle {
            id: rect5
            width: rect1.width+rect2.width+rect3.width
            height: parent.width / 8
            color: "maroon"
            anchors.left: parent.left
            anchors.leftMargin: parent.width/40
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle{
            id:rect6
            width: rect4.width / 2
            height: width
            color: "green"
            anchors.left: rect5.right
            anchors.leftMargin: parent.width/9
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle{
            id:rect7
            width: rect4.width / 2
            height: width
            color: "orange"
            anchors.left: rect6.right
            anchors.leftMargin: parent.width/75
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Rectangle {
        id: row3
        height: parent.height / 3
        width: parent.width
        color: "navajowhite"
        anchors.top: row2.bottom

        Rectangle {
            id: rect8
            width: rect5.width / 4.5
            height: width
            color: "navy"
            anchors.left: parent.left
            anchors.leftMargin: parent.width/40
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle {
            id: rect9
            width: rect5.width / 4.5
            height: width
            color: "orangered"
            anchors.left: rect8.right
            anchors.leftMargin: parent.width/15
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle {
            id: rect10
            width: rect5.width / 4.5
            height: width
            color: "blueviolet"
            anchors.right: rect11.left
            anchors.rightMargin: parent.width/20
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle {
            id: rect11
            width: parent.width / 4.5
            height: rect10.width
            color: "fuchsia"
            anchors.right: rect12.left
            anchors.rightMargin:  parent.width/80
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle{
            id:rect12
            width: rect4.width / 2
            height: width
            color: "black"
            anchors.right: parent.right
            anchors.rightMargin: parent.width/40
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
