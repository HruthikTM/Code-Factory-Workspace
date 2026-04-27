import QtQuick
import QtQuick.Window
import Test 1.0

Window {
    visible: true
    width: 300
    height: 200

    Component.onCompleted: {
        console.log(mylib.Val1)
    }
}
