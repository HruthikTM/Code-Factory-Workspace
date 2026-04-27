import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    CustomRectangle{
        id: header
        height: 60
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        rectColor: "#3A3A3A"
        borderColor: "black"
        text: "DIREKTSCHNITTPROGRAMME"
        textColor: "white"
        textFont: "Helvetica"
        textFontSize: 16
    }

    CustomRectangle{
        id: mainArea
        anchors.top: header.bottom
        anchors.bottom: footer.top
        anchors.left: parent.left
        anchors.right: parent.right
        rectColor: "#EFEFEF"
        borderColor: "black"
    }

    CustomRectangle{
        id: footer
        height: 80
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        rectColor: "#5E5E5E"
        borderColor: "black"

        CustomButton{
            id : okBtn
            text: "OKAY"
            anchors.right: parent.right
            anchors.left: parent.bottom
            anchors.margins: 15
        }

        CustomButton{
            text: "SUBMIT"
            anchors.right: okBtn.left
            anchors.left: parent.bottom
            anchors.rightMargin: 10
            anchors.bottomMargin: 15
        }
    }

}
