import QtQuick

Rectangle {
    id: custRect
    width: parent.width / parent.columns - parent.columnSpacing
    height: parent.height / parent.rows - parent.rowSpacing
    radius: width / 2

    signal btnClicked(string value)

    property alias btnText: textItem.text
    property string btnColor: "gainsboro"

    color: btnColor

    TextInput {
        id: textItem
        anchors.centerIn: parent
        font.pixelSize: 24
        font.family: "Helvetica"
        font.bold: true
    }

    // MouseArea {
    // anchors.fill: parent
    // onClicked:
    // {
    //     custRect.btnClicked(btnText)
    // }
    // }

    MouseArea {
        anchors.centerIn: parent
        width: parent.width
        height: parent.height

        onClicked: {
            let centerX = width / 2
            let centerY = height / 2
            let radius = width / 2

            let clickX = mouseX
            let clickY = mouseY

            let distanceSquared = (clickX - centerX) * (clickX - centerX) + (clickY - centerY) * (clickY - centerY)
            let radiusSquared = radius * radius

            if (distanceSquared <= radiusSquared) {
                custRect.btnClicked(btnText)
            }
        }
    }
}
