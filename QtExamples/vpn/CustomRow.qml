import QtQuick
import QtQuick.Controls

Row {
    spacing: 15

    property alias labelText: label.labelText
    property alias text: field.text
    property alias fieldWidth: field.width

    CustomLabel {
        id: label
    }

    CustomTextField {
        id: field
    }
}
