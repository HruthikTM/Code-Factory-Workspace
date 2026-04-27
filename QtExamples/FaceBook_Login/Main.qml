import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    width: 420
    height: 640
    visible: true
    title: "Facebook Login"
    color: "#f0f2f5"


    Item {
        id: container
        width: parent.width * 0.85
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        height: 420
        }

    Label {
        id: titleText
        text: "Log in to Facebook"
        font.pixelSize: 22
        font.bold: true
        anchors.top: container.top
        anchors.horizontalCenter: container.horizontalCenter
        }

    CustomTextField {
        id: idField
        customPlaceHolder: "Email address or mobile number"
        textFieldWidth: container.width
        textFieldHeight: 45
        anchors.top: titleText.bottom
        anchors.topMargin: 25
        anchors.horizontalCenter: container.horizontalCenter

        background: Rectangle {
            anchors.fill: parent
            radius:  8
            border.color:  "#ccd0d5"
            border.width:  1
            color: "white"
        }
    }

    CustomTextField {
        id: passwordField
        placeholderText:  "Password"
        textFieldWidth: container.width
        textFieldHeight: 45
        anchors.top: idField.bottom
        anchors.topMargin: 15
        anchors.horizontalCenter: container.horizontalCenter

        background: CustomRectangle {
            customRadius: 8
            customBorderColor: "#ccd0d5"
            customBorderWidth: 1
            customColor:"white"
        }
    }
}

