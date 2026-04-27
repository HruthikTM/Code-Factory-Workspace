import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects
import QtQuick.Layouts

Button {
    id: custBtn

    property string btnText: "BTN"

    property color hoverColor: "#FFB366"
    property color startColor: "#4D4D4D"
    property color endColor: "#3C3C3C"
    property color shadowColor: "#30FFFFFF"


    property string fontFamily: "Arial"
    property int fontWeight: Font.Bold
    property color fontColor: "#EDEDED"

    Layout.fillWidth: true
    Layout.fillHeight: true
    Layout.preferredWidth: 70
    Layout.preferredHeight: 50

    property int fontSize: height * 0.25

    hoverEnabled: true

    readonly property bool isActive: container.activeButton === custBtn

    onClicked: {
        container.activeButton = (container.activeButton === custBtn) ? null : custBtn
    }

    background: Rectangle {
        id: rect
        anchors.fill: parent
        radius: 5
        border.width: custBtn.hovered && !custBtn.isActive ? 2 : 0
        border.color: custBtn.hoverColor

        gradient: Gradient {
            GradientStop {
                position: 0.0
                color: custBtn.isActive ? custBtn.hoverColor : custBtn.startColor
            }
            GradientStop {
                position: 1.0
                color: custBtn.isActive ? custBtn.hoverColor : custBtn.endColor
            }
        }
    }
    DropShadow {
        anchors.fill: rect
        source: rect

        radius: 20

        color: custBtn.shadowColor
        horizontalOffset: 6
        verticalOffset: 6
    }
    contentItem: Text {
        text: custBtn.btnText

        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        font.family: custBtn.fontFamily
        font.pixelSize: custBtn.fontSize
        font.weight: custBtn.fontWeight
        color: "#FFFFFF"
    }
}



