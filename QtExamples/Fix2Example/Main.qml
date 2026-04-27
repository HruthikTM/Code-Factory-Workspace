import QtQuick

Window {
    id: root
    width: 400
    height: 300
    visible: true

    CustomItem {
        width: root.width
        height: root.height
        boxColor: "blue"
    }
}
