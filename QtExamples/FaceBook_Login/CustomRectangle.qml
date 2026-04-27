import QtQuick

Rectangle {
    id: customRect

    property alias customColor :customRect.color
    property alias customBorderColor :customRect.border.color
    property alias customWidth:customRect.width
    property alias customHeight: customRect.height
    property alias customRadius: customRect.radius
    property alias customBorderWidth: customRect.border.width


    border.color: customRect.border.color
}
