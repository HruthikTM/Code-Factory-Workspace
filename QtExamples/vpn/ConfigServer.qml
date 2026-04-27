import QtQuick
import QtQuick.Controls

Column {
    anchors.centerIn: parent
    anchors.margins: 20
    spacing: 20

    Row {
        spacing: 15

        CustomLabel {
            labelText: "Server Type"
        }

        ComboBox {
            id: dropdown
            model: ["UDP Server", "WEB Server", "TCP Server"]
            width: 165
            height: 35
            font.family: "Inter"
            font.pixelSize: 14
        }
    }

    CustomRow {
        id: iprow
        labelText: "IP Address"
        fieldWidth: 165
    }

    CustomRow {
        id: portrow
        labelText: "Port"
        fieldWidth: 165
    }

    Row {
        spacing: 20
        anchors.horizontalCenter: parent.horizontalCenter

        CustomButton {
            btnText: "Submit"
        }

        CustomButton {
            btnText: "Cancel"
        }
    }
}
