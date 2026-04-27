import QtQuick
import QtQuick.Controls

TextField {
    id: textField
    property alias textFieldWidth: textField.width
    height: 35

    background: Rectangle {
        border.color: "black"
        border.width: 1
        radius: 10
        color: "white"
    }
}
