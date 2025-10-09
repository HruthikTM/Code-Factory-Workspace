import QtQuick
import QtQuick.Controls
import QtQuick.DialogsWindow
{
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Button {
        id: button
        text: "Click me!"
        onClicked: msgDialog.open()
    }
    MessageDialog {
        id: msgDialog
        title: "Hello"
        text: "World"
    }
}
