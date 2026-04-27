import QtQuick
import QtQuick.Window

//Required Properties
Window {
    id : root
    width: 400
    height: 300
    visible: true

    CustomItem {
        customWidth: root.width
        customHeight: root.height
    }
}
