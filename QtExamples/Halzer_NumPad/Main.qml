import QtQuick
import QtQuick.Window
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("NumPad")
    color: "#4A4A4A"

    Rectangle {
        id: container
        width: parent.width * 0.60
        height: parent.height * 0.70
        anchors.centerIn: parent

        color: "#585858"

        property var activeButton: null

        GridLayout {
            id: numPad

            rows: 5
            columns: 4

            width: parent.width * 0.70
            height: parent.height * 0.90
            anchors.centerIn: parent

            CustomButton { btnText: "CLEAR"}
            CustomButton { btnText: "◀" }
            CustomButton { btnText: "▶" }
            CustomButton { btnText: "/" }

            CustomButton { btnText: "7" }
            CustomButton { btnText: "8" }
            CustomButton { btnText: "9" }
            CustomButton { btnText: "*" }

            CustomButton { btnText: "4" }
            CustomButton { btnText: "5" }
            CustomButton { btnText: "6" }
            CustomButton { btnText: "-" }

            CustomButton { btnText: "1" }
            CustomButton { btnText: "2" }
            CustomButton { btnText: "3" }
            CustomButton { btnText: "+" }

            CustomButton { btnText: "⌫" }
            CustomButton { btnText: "0" }
            CustomButton { btnText: "." }
            CustomButton { btnText: "ENTER" }

        }
    }
}
