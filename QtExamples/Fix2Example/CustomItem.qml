import QtQuick

Item {
    id: container

    property alias boxColor: rect.color

    Rectangle {
        id : rect
        width: container.width
        height: container.height / 2
        color: "red"
    }
}
