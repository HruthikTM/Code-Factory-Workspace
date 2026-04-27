import QtQuick
import QtQuick.Controls

Button {
    id : btn

    property color backgroundColor: "#F2F2F2"
    property color hoverColor: "#DDDDDD"
    property color pressedColor: "#CCCCCC"
    property color textColor: "black"

    text: "BUTTON"
    width: 120
    height: 40

    background: Rectangle {
        radius: 2
        border.color: "#B0B0B0"

        color: btn.down ? btn.pressedColor : btn.hovered ? btn.hoverColor : btn.backgroundColor
    }

    contentItem: Text {
        text: btn.text
        color: btn.textColor
        font.pointSize: 12
        anchors.centerIn: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

    }

}
