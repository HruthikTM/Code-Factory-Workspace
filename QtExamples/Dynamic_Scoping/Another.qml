
import QtQuick
import QtQuick.Window

Window {
    width: 500
    height: 400
    visible: true

    Item {
        id: screenRoot
        anchors.fill: parent

        CustomItem { }
    }
}
