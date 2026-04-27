import QtQuick 2.15

Item {
    id: customRct

    property int rectWidth: 300
    property int rectHeight: 220

    width: rectWidth
    height: rectHeight

    Rectangle {
        anchors.fill: parent
        color: "#7a3f12"
    }

    Rectangle {
        id: photoArea
        anchors.fill: parent
        anchors.margins: 6
        radius: 4
        color: "white"
        clip: true
    }

    default property alias content: photoArea.data
}
