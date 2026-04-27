import QtQuick
import QtQuick.Controls 2.15

TextField {
    id: txtField

    property int textFieldWidth: 50
    property int textFieldHeight: 50
    property string customPlaceHolder: "Enter Something"

    width: textFieldWidth
    height: textFieldHeight
    placeholderText: customPlaceHolder

}

