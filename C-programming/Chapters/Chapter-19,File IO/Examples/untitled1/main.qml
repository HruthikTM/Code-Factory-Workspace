
import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 600
    height: 400
    visible: true

    Item {
        width: 100
        height: 100
        anchors.centerIn: parent

        Menu {
            title: "Some Menu"
            visible: true
            MenuItem {
                text: "Action 1"
            }
        }
    }
}
